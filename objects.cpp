#include "objects.h"
namespace objects_r
{
    void FileSettings::write_settings(string& path_settings_Str){
        Setting_Time = MainSettings::SETTING_TIME;
        Setting_String = MainSettings::SETTING_STRING;
        int length_str_Int = Setting_String.length();
        ofstream setting_file_Ofs;
        setting_file_Ofs.open(path_settings_Str, ios::out | ios::binary);
        if (setting_file_Ofs.is_open()){
            setting_file_Ofs.write((char*)&Setting_Time, sizeof(int));
            setting_file_Ofs.write((char*)&length_str_Int, sizeof(int));
            for (int index = 0; index < length_str_Int; index++){
                setting_file_Ofs.write((char*)&Setting_String[index], sizeof(char));
            }
        }
        else{cout << "ошибка записи файла" << endl;}
        setting_file_Ofs.close();
    }

    void FileSettings::read_settings(string& path_settings_Str){
        int length_str_Int = 0;
        Setting_String = "";
        char temp_Ch;
        ifstream setting_file_Ifs;
        setting_file_Ifs.open(path_settings_Str, ios::in | ios::binary);
        if (setting_file_Ifs.is_open()){
            setting_file_Ifs.read((char*)&Setting_Time, sizeof(int));
            setting_file_Ifs.read((char*)&length_str_Int, sizeof(int));
            for (int index = 0; index < length_str_Int; index++){
                setting_file_Ifs.read((char*)&temp_Ch, sizeof(char));
                Setting_String += temp_Ch;
            }
            MainSettings::SETTING_TIME = Setting_Time;
            MainSettings::SETTING_STRING = Setting_String;
        }
        else{cout << "ошибка чтения файла" << endl;}
        setting_file_Ifs.close();
    }

}
