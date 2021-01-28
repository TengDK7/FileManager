#pragma once
#include<string>
using namespace std;

class CppFile
{
public:
    static bool IsFileExist(string filepath);
    static bool CreateFile(string filepath);
    static bool DeleteFile(string filepath);
    static string ReadFileText(string filepath);
    static bool WriteFileText(string filepath);
    static bool AppendFileText(string filepath);
    template<class T>
    static bool ReadBinFile(T& mobject);
    template<class T>
    static bool WriteBinFile(T mobject);
};
