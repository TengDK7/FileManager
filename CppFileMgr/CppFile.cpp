#include"stdafx.h"
#include "CppFile.h"
#include<fstream>
#include<io.h>

bool CppFile::IsFileExist(const string& filepath,int index)
{
    switch (index)
    {
    case 1://fstream
    {
        ifstream fin(filepath);
        if (fin)
        {
            if (fin.is_open())
                fin.close();
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
    case 2:
    {
        FILE* file = fopen(filepath.c_str(), "r");
        if (file)
        {
            delete file;
            return true;
        }
        else
        {
            return true;
        }
        break;
    }
    case 3://io.h
    {
        auto result = _access(filepath.c_str(), 0);
        if (result == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
    }
    return false;
}

bool CppFile::CreateFile(const string& filepath)
{
    return false;
}

bool CppFile::DeleteFile(const string& filepath)
{
    return false;
}

string CppFile::ReadFileText(const string& filepath)
{
    return string();
}

bool CppFile::WriteFileText(const string& filepath)
{
    return false;
}

bool CppFile::AppendFileText(const string& filepath)
{
    return false;
}
template<class T>
inline bool CppFile::ReadBinFile(T& mobject)
{
    return false;
}

template<class T>
inline bool CppFile::WriteBinFile(T mobject)
{
    return false;
}