# C语言格式化输入输出-转换说明符的用法

本文主要介绍C语言中格式化输入输出语句中转换说明(conversition specification)的用法

## `printf` `sprintf` `fprintf`的转换说明符

`%[flags][width][.prec][类型修饰]type`

|  flags  | 含义                                                         |
| :-----: | :----------------------------------------------------------- |
|   \-    | 左对齐                                                       |
|   \+    | 有符号值为正数时，则在值前面加上正号；若为负，则在值前面加上负号 |
| _space_ | 有符号值为正数时，则在值前面显示空格；若为负，则在值前面加上负号 |
|    0    | 对于数值格式，使用0代替空格填充不足的字符；对于整数格式，如果使用了`-`标志或者指定精度，则该flag不起作用 |
|    #    | 把结果转换成另一种格式。<br>如果为%o，则以0开始；<br>如果为%x或%X，则以0x或0X开始；<br>对于所有浮点类型，强制保留小数点；<br>对于%g或%G格式，则使其包含尾随0 |

|  width   | 含义                                       |   .prec   | 含义                                                         |
| :------: | ------------------------------------------ | :-------: | ------------------------------------------------------------ |
| _number_ | 输出的**最小**长度(字符数)                 | ._number_ | 输出的精度。<br>对于%e，%E和%f而言，表示小数点右边数字的位数<br>对于%g，%G而言，表示有效数字最大位数<br>对于%s而言，表示待打印字符的最大数量<br>对于整型，表示待打印数字的最小位数<br>单独使用`.`与`.0`的作用相同 |
|    \*    | _number_的值由待打印项列表中对应的变量决定 |    .\*    | _number_的值由待打印项列表中对应的变量决定                   |

类型修饰用于改变type所指的变量的显示形式，其组合关系如下表所示

| 类型修饰 |      d i      |        u o x X         | f F e E g G a A |   c    |    s     |   p   |       n        |
| :------: | :-----------: | :--------------------: | :-------------: | :----: | :------: | :---: | :------------: |
|  (none)  |      int      |      unsigned int      |     double      |  int   |  char*   | void* |      int*      |
|    hh    |  signed char  |     unsigned char      |                 |        |          |       |  signed char*  |
|    h     |   short int   |   unsigned short int   |                 |        |          |       |   short int*   |
|    l     |   long int    |   unsigned long int    |                 | wint_t | wchar_t* |       |   long int*    |
|    ll    | long long int | unsigned long long int |                 |        |          |       | long long int* |
|    j     |   intmax_t    |       uintmax_t        |                 |        |          |       |   intmax_t*    |
|    z     |    size_t     |         size_t         |                 |        |          |       |    size_t*     |
|    t     |   ptrdiff_t   |       ptrdiff_t        |                 |        |          |       |   ptrdiff_t*   |
|    L     |               |                        |   long double   |        |          |       |                |

注：

(1) `intmax_t` 和`uintmax_t`定义在`stdint.h`中，是128位的整数类型

(2) `size_t`定义在`stddef.h`中(`stdio.h`已经包含该头文件)，是`sizeof()`的值的类型

(3) `ptrdiff_t`是表示两个指针差值的类型


| type | 用于                                                         | type | 用于                                                         |
| :--: | ------------------------------------------------------------ | :--: | ------------------------------------------------------------ |
| i或d | int                                                          | a或A | 十六进制浮点数                                               |
|  u   | unsigned int                                                 |  c   | char                                                         |
|  o   | 无符号八进制整数                                             |  C   | ISO宽字符类型(wchar_t)                                       |
| x或X | 无符号十六进制整数(X使用大写)                                |  s   | char*字符串                                                  |
| f或F | 浮点数类型(默认保留六位小数)                                 |  p   | 指针(输出十六进制地址)                                       |
| e或E | 显示为科学计数法(保留六位小数)                               |  n   | 不输出任何字符，但是会将到该位置前输出的字符数存入后面对应的指针(默认为int*)所指的变量中 |
| g或G | 根据数值不同自动选择是否使用科学计数法表示(不含尾随0),长度更短者优先 |  %   | 输出字符'%'                                                  |

## `scanf` `sscanf` `fscanf`的转换说明符

`%[*][width][length]specifier`

| \*和width | 含义                                                         |
| :-------: | ------------------------------------------------------------ |
|    \*     | 跳过对应的输入项<br>(例如在语句`scanf("%*d %*d %d",&n);`中，仅将读取到的第三个整数存入变量`n`中，前两个值被忽略) |
| _number_  | 最大字符数。输入达到最大字符数或第一次遇到空白字符时将停止   |

length即类型修饰部分，与specifier的搭配情况如下表所示
| length |d i|u o x | f e g a | c s \[\] \[\^\] | p | n|
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
|(none)| int*| unsigned int*| float*|char* | void** |int*|
|hh|signed char*| unsigned char* ||||signed char*|
|h | short int* | unsigned short int* |||        |short int*|
|l | long int* | unsigned long int* | double* | wchar_t* || long int*|
|ll| long long int* | unsigned long long int* |||  |long long int*|
|j | intmax_t* | uintmax_t* |||        |intmax_t*|
|z |size_t*| size_t* ||| |size_t*|
|t | ptrdiff_t* | ptrdiff_t* |||  |ptrdiff_t*|
|L ||  |long double*||||

|      specifier      | 用于                                                         |
| :------------: | ------------------------------------------------------------ |
|       i        | 把输入解释整数，自动识别进制（输入以0x开头则为十六进制，以0开头则为八进制，以1到9开头则为十进制） |
|      d或u      | 把输入解释为十进制整数(d表示有符号，u表示无符号)             |
|       o        | 把输入解释为有符号八进制整数                                 |
|       x        | 把输入解释为有符号十六进制整数                               |
|       s        | 字符串（从第一个非空白字符开始，到下一个空白字符之前的所有字符都是输入） |
|       p        | 把输入解释成指针（地址）                                     |
|    a,e,f,g     | 把输入解释成浮点数（十进制或十六进制）                       |
|       c        | 把输入解释成char字符（不忽略空白字符）                       |
| [_chatacters_]和\[^_characters_\] | 扫描集，仅读取包含在\[\]中的字符，排除包含在\[\^\]中的字符，在第一个不匹配于\[\]中字符（或匹配于\[\^\]中字符）的位置停止，最终读入字符组成字符串，存入列表中对应的指针所指的连续内存空间中。<br>**注意：仅适用于字符型变量** |

