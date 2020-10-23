# C语言的文件读写解析操作
## 0.格式化输入输出
### `printf`的格式化输出
`%[flags][width][.prec][类型修饰]type`
|Flag|含义|width 或 prec|含义|
|:-:|-|:-:|-|
|\-|左对⻬|(number)|输出的最小长度(字符数)|
|\+|在前⾯面放\+或\-|\*|""后对应的参数是字符数|
|(space)|正数留空|.(number)|小数点后的位数|
|0|0填充|.*|""后对应的参数是小数点后的位数|

|类型修饰|含义|
|:-:|-|
|hh|单个字节|
|h|short|
|l|long|
|ll|long long|
|L|long double|



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
    char *_ptr;    //xia'y
    int   _cnt;    //剩余的字符数
    char *_base;    //
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

|模式字符串|意义|若文件已存在的动作|若文件不存在的动作|
|:-:|-|-|-|
|r(b)|打开一个用于读取的文本(二进制)文件|从头读|打开失败|
|w(b)|创建一个用于写入的文本(二进制)文件|销毁内容|创建新文件|
|a(b)|附加到一个文本(二进制)文件|写到结尾|创建新文件|
|r(b)+|打开一个用于读/写的文本(二进制)文件|从头读|错误|
|w(b)+|创建一个用于读/写的文本(二进制)文件|销毁内容|创建新文件|
|a(b)+|打开一个用于读/写的文本(二进制)文件|写到结尾|创建新文件|	

* 标签  `b`  只在Windows操作系统上生效

` int fclose( FILE *stream ); `

关闭指定的文件流，其中stream指针指向目标文件流

成功时返回0，失败时返回EOF

若在 fclose 返回后使用指针 stream 的值则行为未定义

`size_t fread(void *restrict buffer,size_t size,size_t count,FILE *restrict stream);`

从给定输入流 stream 读取至多 count 个对象到数组 buffer 中

|参数|作用|
|-|-|
|buffer|指向要读取的数组中首个对象的指针|
|size|每个对象的字节大小|
|count|要读取的对象数|
|stream|读取来源的输入文件流|

