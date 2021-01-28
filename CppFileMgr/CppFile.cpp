#include "CppFile.h"

bool CppFile::IsFileExist(string filepath)
{
    return false;
}

bool CppFile::CreateFile(string filepath)
{
    return false;
}

bool CppFile::DeleteFile(string filepath)
{
    return false;
}

string CppFile::ReadFileText(string filepath)
{
    return string();
}

bool CppFile::WriteFileText(string filepath)
{
    return false;
}

bool CppFile::AppendFileText(string filepath)
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