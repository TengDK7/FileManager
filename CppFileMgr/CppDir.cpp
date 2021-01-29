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

bool CppDir::CreateDir(const string& dirpath,int index)
{
    if (IsDirExist(dirpath,1))
        return true;

    switch (index)
    {
    case 1://command
    {
        string command = "mkdir -p" + dirpath;
        auto result = system(command.c_str());
        if (result == 0)
            return true;
        else
            return false;
        break;
    }
    case 2://direct.h
    {
        if (mkdir(dirpath.c_str()) == 0)// 返回 0 表示创建成功，-1 表示失败
            return true;
        else
            return false;
        break;
    }
    case 3:
    {
        return CreateDirectory(s2ws(dirpath).c_str(), NULL);
        break;
    }
    case 4:
    {
        break;
    }
    }
    return false;
}

bool CppDir::DeleteDir(const string& dirpath)
{
    return false;
}
