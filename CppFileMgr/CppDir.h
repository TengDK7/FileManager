#pragma once
#include<string>
using namespace std;

class CppDir
{
public:
    static bool IsDirExist(string dirpath);
    static bool CreateDir(string dirpath);
    static bool DeleteDir(string dirpath);
};

