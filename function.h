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
    int path_allrows_vcr(string& path_db_Str, vector<objects_r::st_Address>& address_Vcr);
}

#endif // FUNCTION_H_INCLUDED
