#pragma once
#include"stdafx.h"
#include<string>
using namespace std;

class CppDir
{
public:
    static bool IsDirExist(const string& dirpath,int index);
    static bool CreateDir(const string& dirpath,int index);
    static bool DeleteDir(const string& dirpath);
};

