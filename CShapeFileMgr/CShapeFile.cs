using System;
using System.Collections.Generic;
using System.Text;

namespace CShapeFileMgr
{
    class CShapeFile
    {
        public static bool IsFileExist(string filepath)
        {
            return false;
        }
        public static bool CreateFile(string filepath)
        {
            return false;
        }
        public static bool DeleteFile(string filepath)
        {
            return false;
        }
        public static bool WriteFileText(string filepath,string text)
        {
            return false;
        }
        public static string ReadFileText(string filepath)
        {
            return string.Empty;
        }
        public static bool AppendFileText(string filepath,string text)
        {
            return false;
        }
        public static bool ReadBinFile<T>(string filepath,T mobject)
        {
            return false;
        }
        public static bool WriteBinFile<T>(string filepath,T mobject)
        {
            return false;
        }

    }
}
