#pragma once
#include"stdafx.h"
#include<string>
#include<vector>
using namespace std;


struct BinObjct
{
    BinObjct() {};
    BinObjct(const char* inname, int intotle) :totle(intotle)
    {
        strcpy(name, inname);
    }
    char name[20];
    int totle;
};

class CppFile
{
public:
    static bool IsFileExist(const string filepath,int index);
    static bool CreateFileW(const string& filepath,int index);
    static bool DeleteFileW(const string& filepath,int index);
    static bool ReadFileText(const string& filepath, string& text, int index);
    static bool WriteFileText(const string& filepath, const string& text,int index);
    static bool AppendFileText(const string& filepath, const string& text);
    static bool ReadBinFile(BinObjct& mobject,const string filepath);
    static bool WriteBinFile(BinObjct mobject,const string filepath);
};