#include "objects.h"
namespace objects_r
{
    void FileSettings::write_settings(string& path_settings_Str){
        this->Setting_Time = MainSettings::SETTING_TIME;
        ofstream setting_file_Ofs;
        setting_file_Ofs.open(path_settings_Str);
        if (setting_file_Ofs.is_open()){
            cout << "размер объекта " << sizeof(objects_r::FileSettings) << endl;
            setting_file_Ofs.write((char*)this, sizeof(objects_r::FileSettings));
            setting_file_Ofs.close();
        }
        else{ cout << "ошибка записи файла" << endl; }
    }

}
