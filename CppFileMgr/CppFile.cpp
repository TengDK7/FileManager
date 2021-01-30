#include"stdafx.h"
#include "CppFile.h"
#include<fstream>
#include<io.h>
#include"Tool.h"

bool CppFile::IsFileExist(const string filepath,int index)
{
    if(index== 1)//fstream
    {
		ifstream fin(filepath.c_str());
		if (fin)
		{
			if (fin.is_open())
			{
				fin.close();
			}
			return true;
		}
		else
		{
			return false;
		}
    }
    else if(index== 2)
    {
        FILE* file = fopen(filepath.c_str(), "r");
        if (file)
        {
            fclose(file);//fopen对应fclose,不可使用delete file,会导致异常
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(index== 3)//io.h
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
    }
    return false;
}

bool CppFile::CreateFileW(const string& filepath,int index)
{
    if (IsFileExist(filepath, 1))
        return true;

    switch (index)
    {
    case 1:
    {
        ofstream fout(filepath.c_str(), ios_base::out);
        if (fout.is_open())
        {
            fout.close();
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
        FILE* file = fopen(filepath.c_str(), "a");
        if (file)
        {
            fclose(file);
            delete file;
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
    default:
        break;
    }
    return false;
}

bool CppFile::DeleteFileW(const string& filepath)
{
    return false;
}

bool CppFile::ReadFileText(const string& filepath, string& text, int index)
{
    if (!IsFileExist(filepath, 1))
        return false;

    switch (index)
    {
    case 1:
    {
        ifstream fin(filepath);
        if (fin)
        {
            if (fin.is_open())
            {
                fin >> noskipws;
                while (fin.good() && !fin.eof())
                {
                    char buf[2048];
                    memset(buf, 0, 2048);
                    fin.getline(buf, 2048);
                    auto line = UTF8ToGB(buf);
                    text += line +'\n';
                }
                fin.close();
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        break;
    }
    case 2:
    {
        ifstream fin(filepath);
        if (fin)
        {
            if (fin.is_open())
            {
                fin >> noskipws;
                string line;
                while (getline(fin, line))
                {
                    text += line+'\n';
                }
                text = UTF8ToGB(text.c_str());
                fin.close();
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        break;
    }
    case 3:
    {
        ifstream fin(filepath);
        if (fin)
        {
            if (fin.is_open())
            {
                fin >> noskipws;
                char elpha;
                while (!fin.eof())
                {
                    fin >> elpha;
                    text += elpha;
                }
                text = UTF8ToGB(text.c_str());
                fin.close();
                return true;
            }
            else
            {
                return false;
            }
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

bool CppFile::WriteFileText(const string& filepath, string& text,int index)
{
    return false;
}

bool CppFile::AppendFileText(const string& filepath, const string& text)
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