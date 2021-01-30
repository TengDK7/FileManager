#pragma once
#include"stdafx.h"
#include<string>
using namespace std;

class CppFile
{
public:
    static bool IsFileExist(const string filepath,int index);
    static bool CreateFileW(const string& filepath,int index);
    static bool DeleteFileW(const string& filepath);
    static bool ReadFileText(const string& filepath, string& text, int index);
    static bool WriteFileText(const string& filepath, string& text,int index);
    static bool AppendFileText(const string& filepath, const string& text);
    template<class T>
    static bool ReadBinFile(T& mobject);
    template<class T>
    static bool WriteBinFile(T mobject);
};