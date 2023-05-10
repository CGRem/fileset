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
    // C
    // "INSERT INTO cases (case_number, department, type, manufacturer, model, serial, reason, equipment, defects," \
              " condition, fellow, client, phone, dp_phone, date_input, client_text) " \
              "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)"
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
}
