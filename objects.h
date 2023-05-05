#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED
#include <fstream>
#include <iostream>

using namespace std;

namespace objects_r
{
    class Rem_Point{
    public:
        int cor_t = 0;
        int dor_m = 0;
        int for_s = 0;
    };
    class MainSettings{
    public:
        static int SETTING_TIME;
    };
    class FileSettings {
    private:
        int Setting_Time = 0;
    public:
        void write_settings(string& path_file_settings);
        void read_settings(string& path_file_settings);
    };
}
#endif // OBJECTS_H_INCLUDED
