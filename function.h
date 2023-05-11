#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include "objects.h"
#include "sqlite//sqlite3.h"
#include <typeinfo>

namespace func_r
{
    bool Str_SaveFilesettings_Bl(string& path_settings_Str);
    bool Str_ReadFilesettings_Bl(string& path_settings_Str);
    void vcr_output_element(vector<int>& array_int_Vcr);
}
namespace db_r
{
    int vcr_outprint_db(vector<objects_r::st_Address>& address_out_Vcr);
    int path_writerow_st(string& path_db_Str, objects_r::st_Address& rowadress_St);
    int path_allrows_vcr(string& path_db_Str, vector<objects_r::st_Address>& address_Vcr);
    int path_update_row(string& path_db_Str, objects_r::st_Address& update_row_St, int& num_row_Int);
    int path_delete_row(string& path_db_Str, int& num_row_Int);
}

#endif // FUNCTION_H_INCLUDED
