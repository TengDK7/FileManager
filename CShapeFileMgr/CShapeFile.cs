using System;
using System.IO;

namespace CShapeFileMgr
{
    class CShapeFile
    {
        public static bool IsFileExist(string filepath)
        {
            return File.Exists(filepath);
        }
        public static bool CreateFile(string filepath)
        {
            try
            {
                using (File.Create(filepath)) { };
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false, e.Message);
                return false;
            }
            return true;
        }
        public static bool DeleteFile(string filepath)
        {
            try
            {
                File.Delete(filepath);
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false, e.Message);
                return false;
            }
            return true;
        }
        public static bool WriteFileText(string filepath,string text)
        {
            try
            {
                File.WriteAllText(filepath, text);
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false, e.Message);
                return false;
            }
            return true;
        }
        public static bool ReadFileText(string filepath,out string text)
        {
            text = string.Empty;
            try
            {
                text = File.ReadAllText(filepath);
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false, e.Message);
                return false;
            }
            return true;
        }
        public static bool AppendFileText(string filepath,string text)
        {
            try
            {
                File.AppendAllText(filepath, text);
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false, e.Message);
                return false;
            }
            return true;
        }
        public static bool ReadBinFile<T>(string filepath,out byte[] content)
        {
            content = null;
            try
            {
                content = File.ReadAllBytes(filepath);
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false,e.Message);
                return false;
            }
            return true;
        }
        public static bool WriteBinFile<T>(string filepath)
        {
            return false;
        }

    }
}
