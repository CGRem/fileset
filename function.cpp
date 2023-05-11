#include "function.h"
namespace func_r
{
    bool Str_SaveFilesettings_Bl(string& path_settings_Str){
        ofstream file_settings_Ofs;
        file_settings_Ofs.open(path_settings_Str, ios::out | ios::binary);
        if (file_settings_Ofs.is_open()){
            objects_r::st_Filesettings file_settings_St;
            file_settings_St.Setting_Time = objects_r::MainSettings::SETTING_TIME;
            file_settings_St.Setting_String = objects_r::MainSettings::SETTING_STRING;
            int length_strsettings_Int = file_settings_St.Setting_String.length();
            cout << length_strsettings_Int << endl;
            char temp_ch[255];
            file_settings_St.Setting_String.copy(temp_ch, length_strsettings_Int);
            file_settings_Ofs.write((char*)&file_settings_St.Setting_Time, sizeof(file_settings_St.Setting_Time));
            file_settings_Ofs.write((char*)&length_strsettings_Int, sizeof(length_strsettings_Int));
            file_settings_Ofs.write(temp_ch, length_strsettings_Int * sizeof(char));
            file_settings_Ofs.close();
        }
        else{cout << "ошибка записи файла" << endl;}
        return 1;
    }

    bool Str_ReadFilesettings_Bl(string& path_settings_Str){
        objects_r::st_Filesettings file_settings_St;
        ifstream file_settings_Ifs;
        file_settings_Ifs.open(path_settings_Str, ios::in | ios::binary);
        if (file_settings_Ifs.is_open()){
            objects_r::st_Filesettings file_settings_St;
            file_settings_St.Setting_String = "";
            int length_strsettings_Int = 0;
            char temp_ch[255];
            file_settings_Ifs.read((char*)&file_settings_St.Setting_Time, sizeof(file_settings_St.Setting_Time));
            file_settings_Ifs.read((char*)&length_strsettings_Int, sizeof(length_strsettings_Int));
            file_settings_Ifs.read(temp_ch, sizeof(char) * length_strsettings_Int);
            objects_r::MainSettings::SETTING_TIME = file_settings_St.Setting_Time;
            objects_r::MainSettings::SETTING_STRING = string(temp_ch);
            file_settings_Ifs.close();
        }
        else{cout << "ошибка чтения файла" << endl;}

        return 1;
    }
    void vcr_output_element(vector<int>& array_int_Vcr){
        // вывод элемента векторного массива
        cout << "элемент векторного массива\t" << array_int_Vcr[15] << endl;
    }
}
namespace db_r
{
    // OUTPRINT
    int vcr_outprint_db(vector<objects_r::st_Address>& address_out_Vcr){
        for (int index = 0; index < address_out_Vcr.size(); index++){
            string number_Str = to_string(address_out_Vcr[index].number_Int);
            int length_number = number_Str.length();
            int space_number_Int = 0;
            if (length_number < 3){space_number_Int = 3 - length_number;}
            string spase_Str(space_number_Int, ' ');
            string outline_number = number_Str + spase_Str + "| ";
            //
            int length_town_Int = address_out_Vcr[index].town_Str.size();
            int space_town_Int = 0;
            if (length_town_Int < 12){space_town_Int = 12 - length_town_Int;}
            string spase_town_Str(space_town_Int, ' ');
            string outline_town = address_out_Vcr[index].town_Str + spase_town_Str + "| ";
            //
            int length_street_Int = address_out_Vcr[index].street_Str.size();
            int space_street_Int = 0;
            if (length_street_Int < 12){space_street_Int = 12 - length_street_Int;}
            string spase_street_Str(space_street_Int, ' ');
            string outline_street = address_out_Vcr[index].street_Str + spase_street_Str + "| ";
            //
            string building_Str = to_string(address_out_Vcr[index].building_Int);
            int length_building = building_Str.length();
            int space_building_Int = 0;
            if (length_building < 4){space_building_Int = 4 - length_building;}
            string space_building_Str(space_building_Int, ' ');
            string outline_building = building_Str + space_building_Str + "|";

            cout << outline_number + outline_town + outline_street + outline_building<< endl;
        }
        cout << "--------------------------------------" << endl;

//        string number_Str = string(address_Vcr[0].number_Int);
//        cout << number_Str << endl;
    }
    // C
    int path_writerow_st(string& path_db_Str, objects_r::st_Address& rowadress_St){
        sqlite3* db;
        char path_db_Ch[255];
        char* errMsg = 0;
        path_db_Str.copy(path_db_Ch, path_db_Str.length());
        sqlite3_open_v2(path_db_Ch, &db, SQLITE_OPEN_READWRITE, NULL);
        int rc;
        rc = sqlite3_exec(db, "INSERT INTO list_address (town, street, building) VALUES('max', 'step', 48)", NULL, NULL, &errMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "errors BD: %s.\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return(2);
        }
        sqlite3_close(db);
    }
    // R
    int path_allrows_vcr(string& path_db_Str, vector<objects_r::st_Address>& address_Vcr){
        sqlite3* db;
        char path_db_Ch[255];
        path_db_Str.copy(path_db_Ch, path_db_Str.length());
        sqlite3_open_v2(path_db_Ch, &db, SQLITE_OPEN_READWRITE, NULL);
        int rc;
        sqlite3_stmt* db_rows;
        char sql_request[] = "SELECT * FROM list_address";
        rc = sqlite3_prepare(db, sql_request, -1, &db_rows, NULL);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "errors BD: %s.\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return(3);
        }
        while ( sqlite3_step(db_rows) == SQLITE_ROW) {
            objects_r::st_Address row_address_St;
            row_address_St.number_Int = sqlite3_column_int(db_rows, 0);
            row_address_St.town_Str = (char*)sqlite3_column_text(db_rows, 1);
            row_address_St.street_Str = (char*)sqlite3_column_text(db_rows, 2);
            row_address_St.building_Int = sqlite3_column_int(db_rows, 3);
            address_Vcr.push_back(row_address_St);
        }
        sqlite3_close(db);
    }
    // U
    int path_update_row(string& path_db_Str, objects_r::st_Address& update_row_St, int& num_row_Int){
        sqlite3* db;
        char path_db_Ch[255];
        char* errMsg = 0;
        path_db_Str.copy(path_db_Ch, path_db_Str.length());
        sqlite3_open_v2(path_db_Ch, &db, SQLITE_OPEN_READWRITE, NULL);
        int rc;
        string sql = "UPDATE list_address SET town='"  + update_row_St.town_Str  + "', street='"
         + update_row_St.street_Str + "', building=" + to_string(update_row_St.building_Int) + " WHERE prim=" + to_string(num_row_Int);
        cout << "sql= " << sql << endl;
        rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "errors BD: %s.\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return(4);
        }
        sqlite3_close(db);
    }
    // D
    int path_delete_row(string& path_db_Str, int& num_row_Int){
        sqlite3* db;
        char* errMsg = 0;
        sqlite3_open_v2(path_db_Str.c_str(), &db, SQLITE_OPEN_READWRITE, NULL);
        int rc;
        string sql = "DELETE from list_address where prim=" + to_string(num_row_Int);
        rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, &errMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "errors BD: %s.\n", sqlite3_errmsg(db));
            sqlite3_close(db);
            return(5);
        }
        sqlite3_close(db);
    }
}
