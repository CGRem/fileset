#include <iostream>
#include <fstream>
#include "objects.h"
#include "function.h"

// статические переменные
int objects_r::MainSettings::SETTING_TIME = 0;

using namespace std;

int main()
{
    setlocale (LC_ALL, "Rus");
    string path_file_Str = "cr_files\\fileout.txt";
    string content_file = "string for write \nnext line";
    string path_object_Str = "cr_files\\fileobject.txt";
    /*ofstream fileout;
    fileout.open(path_file_Str);
    fileout << content_file;
    fileout.close();
    */
    ifstream file_read_F;
    file_read_F.open(path_file_Str);
    char ch_Ch;
    /*while(file_read_F.get(ch_Ch)){
        cout << ch_Ch;
    }
    */
    string str;
    while (!file_read_F.eof()){
        getline(file_read_F, str);
        cout << str << endl;
    }
    file_read_F.close();

    objects_r::Rem_Point point;
    point.cor_t = 28;
    point.dor_m = 17;
    point.for_s = 250;

    ofstream objectfile;
    objectfile.open(path_object_Str);
    if (objectfile.is_open()){
        objectfile.write((char*)&point, sizeof(objects_r::Rem_Point));
    }
    else{
        cout << "ошибка открытия файла" << endl;
    }
    objectfile.close();

    ifstream objectfile_out;
    objectfile_out.open(path_object_Str);
    if (objectfile_out.is_open()){
        objects_r::Rem_Point point_read;
        objectfile_out.read((char*)&point_read, sizeof(objects_r::Rem_Point));
        cout << point_read.cor_t << point_read.dor_m << point_read.for_s << endl;
    }
    else{
        cout << "ошибка чтения файла" << endl;
    }
    objectfile_out.close();

    objects_r::MainSettings::SETTING_TIME = 256398;
    string path_filesettings_Str = "cr_files\\filesettings.txt";
    objects_r::FileSettings filesettings;
    filesettings.write_settings(path_filesettings_Str);
//    func_r::print_read_settings(path_filesettings_Str);

    system("pause");
    return 0;
}
