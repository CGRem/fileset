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
}
