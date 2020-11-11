#include <iostream>
#include <string>
using namespace std;

struct number{
    string str;
    int time;
};

int main()
{
    int N(0),num(0);
    char sign(0);
    string temp;
    cin >> N;
    number* numbers = new number[N];
    for (int i(0);i<N;i++)
    {
        cin >> temp;
        //字符串处理：删除前导0
        sign = temp.at(0);
        if (sign == '+' || sign == '-')
            temp.erase(0,1); //先删除符号
        temp.erase(0,temp.find_first_not_of('0'));  //删除所有的0
        if (temp.empty())
            temp = "0";
        else if(sign == '-')
            temp = sign + temp;
        //字符串比较，若存在则次数加一，否则入库
        if (num == 0)
        {
            numbers[num].str = temp;
            numbers[num].time = 1;
            num++;
        }
        for (int j(0);j < num;j++)
        {
            if (temp == numbers[j].str)
            {
                numbers[j].time++;
                break;
            }
            if (j == num-1)
            {
                numbers[num].str = temp;
                numbers[num].time = 1;
                num++;
            }
        }
    }
    int indexOfMax(0);
    for (int i(0);i<num;i++)
        if (numbers[i].time > numbers[indexOfMax].time)
            indexOfMax = i;
    if (num == 1)
        cout << "no" << endl;
    else
        cout << numbers[indexOfMax].str << endl;
    return 0;
}