# C语言的文件读写解析操作
## 1.输出重定向
``` powershell
text.exe > data.out ##将程序text.exe的输出重定向到data.out
text.exe < data.in  ##将程序text.exe的输入重定向到data.in
```
## 2.FILE
FILE类是一个结构体：定义如下：
``` C
struct _iobuf 
{
    char *_ptr;
    int   _cnt;   
    char *_base;
    int   _flag;
    int   _file;
    int   _charbuf;
    int   _bufsiz;
    char *_tmpfname;
};
typedef struct _iobuf FILE;
```
通过typedef定义了 文件类型 的别名： “FILE”
## 3.文件访问函数
` FILE *fopen( const char *filename, const char *mode ); `  
打开文件，其中filename指定打开的文件名，mode指定文件打开的方式

`fopen()`的返回值：

成功时，返回指向新文件流的指针。错误时，返回空指针。

|Mode(模式字符串)|意义|若文件已存在的动作|若文件不存在的动作|
|:-:|-|-|-|
|"r(b)"| 打开一个用于读取的文本(二进制)文件|从头读|打开失败|
|"w(b)"| 创建一个用于写入的文本(二进制)文件|销毁内容|创建新文件|
|"a(b)"| 附加到一个文本(二进制)文件|写到结尾|创建新文件|
|"r(b)+"| 打开一个用于读/写的文本(二进制)文件|从头读|错误|
|"w(b)+"| 创建一个用于读/写的文本(二进制)文件|销毁内容|创建新文件|
|"a(b)+"| 打开一个用于读/写的文本(二进制)文件|写到结尾|创建新文件|	

* 标签  `b`  只在Windows操作系统上生效