# C语言的文件读写解析操作
## 0.格式化输入输出
### `printf`的格式化输出
`%[flags][width][.prec][类型修饰]type`
|Flag|含义|width 或 prec|含义|类型修饰|含义|
|:-:|-|:-:|-|:-:|-|
|\-|左对⻬|(number)|输出的最小长度(字符数)|hh|单个字节|
|\+|在前⾯面放\+或\-|\*|""后对应的参数是字符数|h|short|
|(space)|正数留空|.(number)|小数点后的位数|l|long|
|0|0填充|.*|""后对应的参数是小数点后的位数|ll|long long|
|||||L|long double|

|type|用于|type|用于|
|:-:|-|:-:|-|
|i或d|int|g|float|
|u|unsigned int|G|float|
|o|八进制|a或A|十六进制浮点|
|x|十六进制|c|char|
|X|字母⼤写的⼗六进制|s|字符串|
|f或F|float, 6|p|指针|
|e或E|指数|n|读入/写出的个数|

### `scanf`的格式化输入
`%[flag]type`
|flag|含义|flag|含义|
|:-:|-|:-:|-|
|\*|跳过|l|long, double|
|数字|最大字符数|ll|long long|
|hh|char|L|long double|
|h|short|


|type|用于|type|用于|
|:-:|-|:-:|-|
|d|int|s|字符串|
|i|整数，可能为十六进制或八进制|[...]|所允许的字符|
|u|unsigned int|p|指针|
|o|八进制|a,e,f,g|float|
|x|十六进制|c|char|

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
    char *_ptr;         //文件输入的下一个位置
    int   _cnt;         //当前缓冲区的相对位置
    char *_base;        //文件的起始位置
    int   _flag;        //文件标志
    int   _file;        //文件的有效性验证
    int   _charbuf;     //检查缓冲区状况，若无缓冲区则不读取
    int   _bufsiz;      //文件的大小
    char *_tmpfname;    //临时文件名

};
typedef struct _iobuf FILE;
```
通过typedef定义了 文件类型 的别名： “FILE”
## 3.文件访问函数
#### ` FILE *fopen( const char *filename, const char *mode ); `  
打开文件

|参数|作用|
|:-:|-|
|filename|指定打开的文件名|
|mode|指定文件的打开方式|

返回值：

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

----

#### `int fclose( FILE *stream ); `

关闭与文件流关联的文件

|参数|作用|
|:-:|-|
|stream|指向目标文件流的指针|

返回值：

成功时返回`0`，失败时返回`EOF`

* 若在`fclose`返回后使用指针`stream`的值则行为未定义

#### `size_t fread(void *restrict buffer,size_t size,size_t count,FILE *restrict stream);`

从文件流中读取数据块

|参数|作用|
|:-:|-|
|buffer|指定存放读取内容的数组|
|size|每个对象的字节大小|
|count|要读取的对象数|
|stream|读取来源的输入文件流|

返回值:

成功时返回成功读取的对象数，若返回值小于count则代表发生错误

#### `size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );`

向文件流中写入数据块

|参数|作用|
|:-:|-|
|ptr|指定存放有写入内容的数组|
|size|每个对象的字节大小|
|count|要写入的对象数|
|stream|写入目标的输入文件流|

返回值:

成功时返回成功写入的对象数，若返回值小于count则代表发生错误

#### `int fscanf ( FILE * stream, const char * format, ... );`
从流中读取数据，并根据参数格式将它们存储到其他参数指向的位置。

|参数|作用|
|:-:|-|
|stream|指向文件流的指针|
|format|指定格式化的格式|

返回值:

成功则返回成功读取参数的个数，失败则返回EOF

#### `int fprintf ( FILE * stream, const char * format, ... );`
向文件流中写入格式化的数据

|参数|作用|
|:-:|-|
|stream|指向文件流的指针|
|format|指定格式化的格式|

返回值:

成功则返回成功写入参数的个数，失败则返回EOF