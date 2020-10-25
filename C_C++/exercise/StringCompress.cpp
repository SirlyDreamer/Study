#include <iostream>
#include <cstring>

using namespace std;

string compress(char* str)
{
    if (strlen(str) == 0)
        return;

    char compressedString[65535] = {0};
    char *point = str;
    char current('\0');
    int num(0);
    int index(0);

    while(*point != '\0')
    {
        current = *point;
        while(*point == current)
        {
            num++;
            point++;
        }

        compressedString[index++] = current;
        compressedString[index++] = num + '0';
        
        num = 0;
    }

    if (strlen(str) <= strlen(compressedString))
        return str;
    else
        return compressedString;
}

int main()
{
    char string[65535] = {0};
    cin >> string;
    cout << compress(string);
    return 0;
}