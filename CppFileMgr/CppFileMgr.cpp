// CppFileMgr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include"stdafx.h"
#include <iostream>
#include"CppDir.h"
#include"CppFile.h"
#include <direct.h>

int main()
{
    bool r1 = CppDir::IsDirExist("./TestDir", 1);
    bool r2 = CppDir::IsDirExist("./TestDir", 2);
    bool r3 = CppDir::IsDirExist("./MissDir", 1);
    bool r4 = CppDir::IsDirExist("./MissDir", 2);
    std::cout << R"(("./TestDir", 1))" << ends << "=" << ends << r1 << endl;
    std::cout << R"(("./TestDir", 2))" << ends << "=" << ends << r2 << endl;
    std::cout << R"(("./MissDir", 1))" << ends << "=" << ends << r3 << endl;
    std::cout << R"(("./MissDir", 2))" << ends << "=" << ends << r4 << endl;

    auto a1 = CppFile::IsFileExist("./testfile.txt", 1);
    auto a2 = CppFile::IsFileExist("./testfile.txt", 2);
    auto a3 = CppFile::IsFileExist("./testfile.txt", 3);
    auto a4 = CppFile::IsFileExist("./missfile.txt", 1);
    auto a5 = CppFile::IsFileExist("./missfile.txt", 2);
    auto a6 = CppFile::IsFileExist("./missfile.txt", 3);

    std::cout << R"(("./testfile.txt", 1))" << ends << "=" << ends << a1 << endl;
    std::cout << R"(("./testfile.txt", 2))" << ends << "=" << ends << a2 << endl;
    std::cout << R"(("./testfile.txt", 3))" << ends << "=" << ends << a3 << endl;
    std::cout << R"(("./missfile.txt", 1))" << ends << "=" << ends << a4 << endl;
    std::cout << R"(("./missfile.txt", 2))" << ends << "=" << ends << a5 << endl;
    std::cout << R"(("./missfile.txt", 3))" << ends << "=" << ends << a6 << endl;

    auto b1 = CppFile::CreateFileW("./createfile1.txt", 1);
    auto b2 = CppFile::CreateFileW("./createfile2.txt", 2);
    auto b3 = CppFile::CreateFileW("./MissDir/createfile3.txt", 1);
    auto b4 = CppFile::CreateFileW("./MissDir/createfile3.txt", 2);

    std::cout << R"(("./createfile1.txt", 1))" << ends << "=" << ends << b1 << endl;
    std::cout << R"(("./createfile2.txt", 2))" << ends << "=" << ends << b2 << endl;
    std::cout << R"(("./MissDir/createfile3.txt", 1))" << ends << "=" << ends << b3 << endl;
    std::cout << R"(("./MissDir/createfile3.txt", 2))" << ends << "=" << ends << b4 << endl;

    char buffer[_MAX_PATH];
    auto re = _getcwd(buffer, _MAX_PATH); //<direct.h>获取程序目录

    string dirsub = string(buffer) + "\\AddDir1\\SubDir";
    string dirmain= string(buffer) + "\\AddDir2";

    auto c1 = CppDir::CreateDir(dirsub, 1);
    auto c2 = CppDir::CreateDir(dirmain, 1);
    auto c3 = CppDir::CreateDir("./AddDir3/SubDir", 2);
    auto c4 = CppDir::CreateDir("./AddDir4", 2);
    auto c5 = CppDir::CreateDir("./AddDir5/SubDir", 3);
    auto c6 = CppDir::CreateDir("./AddDir6", 3);

    std::cout << R"(("./AddDir1/SubDir", 1))" << ends << "=" << ends << c1 << endl;
    std::cout << R"(("./AddDir2", 1))" << ends << "=" << ends << c2 << endl;
    std::cout << R"(("./AddDir3/SubDir", 2))" << ends << "=" << ends << c3 << endl;
    std::cout << R"(("./AddDir4", 2))" << ends << "=" << ends << c4 << endl;
    std::cout << R"(("./AddDir5/SubDir", 3))" << ends << "=" << ends << c5 << endl;
    std::cout << R"(("./AddDir6", 3))" << ends << "=" << ends << c6 << endl;

    string text1;
    auto d1 = CppFile::ReadFileText("./testfile.txt", text1, 1);
    string text2;
    auto d2 = CppFile::ReadFileText("./testfile.txt", text2, 2);
    string text3;
    auto d3 = CppFile::ReadFileText("./testfile.txt", text3, 3);

    std::cout << text1 << endl << text2 << endl << text3 << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
