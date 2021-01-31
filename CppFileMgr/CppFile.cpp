#include"stdafx.h"
#include "CppFile.h"
#include<fstream>
#include<io.h>
#include"Tool.h"

/// <summary>
/// �ж��ļ��Ƿ����
/// </summary>
/// <param name="filepath"></param>
/// <param name="index"></param>
/// <returns></returns>
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
            fclose(file);//fopen��Ӧfclose,����ʹ��delete file,�ᵼ���쳣
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
/// <summary>
/// �����ļ�
/// </summary>
/// <param name="filepath"></param>
/// <param name="index"></param>
/// <returns></returns>
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
            //delete file;
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
/// <summary>
/// ɾ���ļ�
/// </summary>
/// <param name="filepath"></param>
/// <returns></returns>
bool CppFile::DeleteFileW(const string& filepath,int index)
{
    if (!IsFileExist(filepath,1))
        return true;
    switch (index)
    {
    case 1:
    {
        if (remove(filepath.c_str()) == 0)
            return true;
        else
            return false;
        break;
    }
    }
    return false;
}
/// <summary>
/// ��ȡ�ļ�����
/// </summary>
/// <param name="filepath"></param>
/// <param name="text"></param>
/// <param name="index"></param>
/// <returns></returns>
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
/// <summary>
/// д���ļ�����
/// </summary>
/// <param name="filepath"></param>
/// <param name="text"></param>
/// <param name="index"></param>
/// <returns></returns>
bool CppFile::WriteFileText(const string& filepath, const string& text,int index)
{
    switch (index)
    {
    case 1:
    {
        ofstream fout(filepath);//����ԭʼ�ı�
        if (fout.is_open())
        {
            fout << text << endl;
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
        ofstream fout(filepath,ios_base::out|ios_base::app);//������ԭʼ�ı�֮��
        if (fout.is_open())
        {
            fout << text << endl;
            fout.close();
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
/// <summary>
/// �����ļ�����
/// </summary>
/// <param name="filepath"></param>
/// <param name="text"></param>
/// <returns></returns>
bool CppFile::AppendFileText(const string& filepath, const string& text)
{
    ofstream fout(filepath, ios_base::out | ios_base::app);//������ԭʼ�ı�֮��
    if (fout.is_open())
    {
        fout << text << endl;
        fout.close();
        return true;
    }
    else
    {
        return false;
    }
}
/// <summary>
/// ��ȡ�������ļ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="mobject"></param>
/// <returns></returns>
bool CppFile::ReadBinFile(BinObjct& mobject,const string filepath)
{
    ifstream fin(filepath,ios::binary|ios::in);
    if (fin.is_open())
    {
        fin.read((char*)&mobject, sizeof(mobject));
        fin.close();
        return true;
    }
    return false;
}
/// <summary>
/// д��������ļ�
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="mobject"></param>
/// <returns></returns>
bool CppFile::WriteBinFile(BinObjct mobject, const string filepath)
{
    ofstream fout(filepath,ios_base::binary|ios_base::out);
    if (fout.is_open())
    {
        fout.write(reinterpret_cast<const char*>(&mobject), sizeof(mobject));
        fout.close();
        return true;
    }
    return false;
}