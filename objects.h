#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
#include <fstream>
#include <iostream>

using namespace std;

namespace objects_r
{
    class MainSettings{
    public:
        static int SETTING_TIME;
        static string SETTING_STRING;
    };
    class FileSettings{
    private:
        int Setting_Time = 0;
        string Setting_String = "00";
    public:
        void write_settings(string& path_file_settings);
        void read_settings(string& path_file_settings);
    };
    struct st_Filesettings{
        int Setting_Time = 0;
        string Setting_String = "00";
    };
}
#endif // OBJECTS_H_INCLUDED
