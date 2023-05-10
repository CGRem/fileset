#include <iostream>
#include <fstream>
//#include <random>
#include <ctime>
#include <vector>
#include "objects.h"
#include "function.h"

// статические переменные
int objects_r::MainSettings::SETTING_TIME = 0;
string objects_r::MainSettings::SETTING_STRING = "00";

using namespace std;

int main()
{
    setlocale (LC_ALL, "Rus");
    // запись строки
    objects_r::st_Address newrow_St;
    string path_db_Str = "db//address.db";
    int errmsg = db_r::path_writerow_st(path_db_Str, newrow_St);

    // получение из базы всех записей
    vector<objects_r::st_Address> address_Vcr;

    db_r::path_allrows_vcr(path_db_Str, address_Vcr);
    int count_rows_Int = address_Vcr.size();
    for (int index=0; index < count_rows_Int; index++){
        cout << address_Vcr[index].number_Int << "\t\t" << address_Vcr[index].town_Str <<
         "\t\t" << address_Vcr[index].street_Str << "\t\t" << address_Vcr[index].building_Int << endl;
    }


/*
    // векторные массивы
    srand(time(NULL));

    vector<int> array_Vcr;
    int count_elements_Int = 100;
    for (int index = 0; index < count_elements_Int; index++){
        int random_Int = rand() %1000;
        array_Vcr.push_back(random_Int);
    }
    for (int index = 0; index < count_elements_Int; index++){
        cout << array_Vcr[index] << endl;
    }
    cout << "================" << endl;
    func_r::vcr_output_element(array_Vcr);
    cout << "================ удаление последнего элемента" << endl;
    cout << array_Vcr.size() << endl;
    array_Vcr.pop_back();
    cout << "last element\t"  << endl;
    cout << "count elements after" << array_Vcr.size() << endl;
    cout << "================ capasity" << endl;
    cout << array_Vcr.capacity() << endl;
    array_Vcr.shrink_to_fit()
*/
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

/*
    // запись настроек с помощью структуры строк массива char
    string path_filesettings_Str = "cr_files\\filesettings_st.bin";

    objects_r::MainSettings::SETTING_TIME = 1569;
    objects_r::MainSettings::SETTING_STRING = "произвольный адрес для записи.";

    bool save_er_Bl = func_r::Str_SaveFilesettings_Bl(path_filesettings_Str);
    bool read_er_Bl = func_r::Str_ReadFilesettings_Bl(path_filesettings_Str);

    cout << "int\t" <<objects_r::MainSettings::SETTING_TIME << endl;
    cout << "char\t" << objects_r::MainSettings::SETTING_STRING << endl;
*/

    // векторные массивы



    system("pause");
    return 0;
}
