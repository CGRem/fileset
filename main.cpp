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
    vector<objects_r::st_Address> address_Vcr;
    string path_db_Str = "db//address.db";

    db_r::path_allrows_vcr(path_db_Str, address_Vcr);

    // запись строки
//    objects_r::st_Address newrow_St;
//    int errmsg = db_r::path_writerow_st(path_db_Str, newrow_St);

    // вывод содержимого вектора
    db_r::vcr_outprint_db(address_Vcr);
    //
    objects_r::st_Address new_adress_St = {0, "timberline", "elmet", 33};
    int id_row = 2;
    db_r::path_update_row(path_db_Str, new_adress_St, id_row);
    //
//    db_r::path_delete_row(path_db_Str, id_row);
    address_Vcr.clear();
    db_r::path_allrows_vcr(path_db_Str, address_Vcr);
    db_r::vcr_outprint_db(address_Vcr);
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
