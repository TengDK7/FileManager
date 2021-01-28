#include"stdafx.h"
#include "CppDir.h"
#include<io.h>
#include<Windows.h>
#include<direct.h>

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

bool CppDir::IsDirExist(const string& dirpath,int index)
{
    auto path = _getcwd(NULL,0);
    switch (index)
    {
    case 1://io.h
    {
        auto result = _access(dirpath.c_str(), 0);
        if (result == -1)
            return false;
        else
            return true;
        break;
    }
    case 2://Windows.h
    {
        std::wstring stemp = s2ws(dirpath);
        DWORD result = GetFileAttributes(stemp.c_str());
        if (result == INVALID_FILE_ATTRIBUTES)
            return false;
        else if (result == FILE_ATTRIBUTE_DIRECTORY)
            return true;
        else
            return false;
        break;
    }
    }
    return false;
}

bool CppDir::CreateDir(const string& dirpath)
{
    return false;
}

bool CppDir::DeleteDir(const string& dirpath)
{
    return false;
}
