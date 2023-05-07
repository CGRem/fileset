#include <iostream>
#include <fstream>
#include "objects.h"
#include "function.h"

// статические переменные
int objects_r::MainSettings::SETTING_TIME = 0;
string objects_r::MainSettings::SETTING_STRING = "00";

using namespace std;

int main()
{
    setlocale (LC_ALL, "Rus");

    /*
    // запись настроек с помощью класса FileSettings
    objects_r::MainSettings::SETTING_TIME = 256398;
    objects_r::MainSettings::SETTING_STRING = "строка размером до 500 символов";
    string path_filesettings_Str = "cr_files\\filesettings.txt";
    objects_r::FileSettings filesettings;
    filesettings.write_settings(path_filesettings_Str);
    filesettings.read_settings(path_filesettings_Str);
    cout << "int\t" <<objects_r::MainSettings::SETTING_TIME << endl;
    cout << "char\t" << objects_r::MainSettings::SETTING_STRING << endl;
    */

    // запись настроек с помощью структуры
    string path_filesettings_Str = "cr_files\\filesettings_st.bin";

    objects_r::MainSettings::SETTING_TIME = 256398;
    objects_r::MainSettings::SETTING_STRING = "'dfvgjksd'[pfgok строка размером до 1000000 символов";

    bool save_er_Bl = func_r::Str_SaveFilesettings_Bl(path_filesettings_Str);
//    bool read_er_Bl = func_r::Str_ReadFilesettings_Bl(path_filesettings_Str);

    cout << "int\t" <<objects_r::MainSettings::SETTING_TIME << endl;
    cout << "char\t" << objects_r::MainSettings::SETTING_STRING << endl;

    system("pause");
    return 0;
}
