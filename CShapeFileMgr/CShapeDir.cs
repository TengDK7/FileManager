using System;
using System.IO;

namespace CShapeFileMgr
{
    class CShapeDir
    {
        public static bool IsDirExist(string dirpath)
        {
            return Directory.Exists(dirpath);  
        }
        public static bool CreateDir(string dirpath)
        {
            try
            {
                if (!Directory.Exists(dirpath))
                    Directory.CreateDirectory(dirpath);
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false, e.Message);
                return false;
            }
            return true;
        }
        public static bool DeleteDir(string dirpath)
        {
            try
            {
                if (Directory.Exists(dirpath))
                    Directory.Delete(dirpath);
            }
            catch(Exception e)
            {
                System.Diagnostics.Debug.Assert(false, e.Message);
                return false;
            }
            return true;
        }
    }
}
