#pragma once
#include"stdafx.h"
#include<string>
using namespace std;

class CppFile
{
public:
    static bool IsFileExist(const string& filepath,int index);
    static bool CreateFile(const string& filepath,int index);
    static bool DeleteFile(const string& filepath);
    static string ReadFileText(const string& filepath);
    static bool WriteFileText(const string& filepath);
    static bool AppendFileText(const string& filepath);
    template<class T>
    static bool ReadBinFile(T& mobject);
    template<class T>
    static bool WriteBinFile(T mobject);
};