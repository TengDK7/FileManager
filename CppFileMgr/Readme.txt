#pragma once

===========================================================================
FILE * fopen(const char * path,const char * mode);
path->文件路径
mode->打开方式:
　　r 以只读方式打开文件，该文件必须存在。
　　r+ 以可读写方式打开文件，该文件必须存在。
　　rb+ 读写打开一个二进制文件，允许读数据。
　　rw+ 读写打开一个文本文件，允许读和写。
　　w 打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件。
　　w+ 打开可读写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。
　　a 以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。（EOF符保留）
　　a+ 以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。 （原来的EOF符不保留）
　　wb 只写打开或新建一个二进制文件；只允许写数据。
　　wb+ 读写打开或建立一个二进制文件，允许读和写。
　　wt+ 读写打开或着建立一个文本文件；允许读写。
　　at+ 读写打开一个文本文件，允许读或在文本末追加数据。
　　ab+ 读写打开一个二进制文件，允许读或在文件末追加数据。
　　上述的形态字符串都可以再加一个b字符，如rb、w+b或ab+等组合，加入b 字符用来告诉函数库打开的文件为二进制文件，而非纯文字文件。
===========================================================================
int _access(const char *path,int mode );
path->文件路径
mode->访问权限设定:
    00 只检查文件是否存在 
    02 写权限 
    04 读权限
    06 读写权限 
===========================================================================
fstream myfile;
myfile.open(const char* _Filename, ios_base::open_mode _Mode)
_Filename->文件路径
_Mode->打开模式:
ios_base::app附件到现有文件的末尾，而不是覆盖它
ios_base::ate切换到文件末尾，但可在文件的任何地方写入数据
ios_base::trunc导致现有文件被覆盖，这是默认设置
ios_base::binary创建二进制文件（默认是文本文件）
ios_base::in以只读的方式打开文件
ios_base::out以只写的方式打开文件
===========================================================================
