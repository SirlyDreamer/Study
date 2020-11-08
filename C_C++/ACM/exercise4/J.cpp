#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<char,char> Reserve { {'A','A'},{'M','M'},{'Y','Y'},{'B',' '},{'N',' '},{'Z','5'},{'C',' '},{'O','O'},{'1','1'},{'D',' '},{'P',' '},{'2','S'},{'E','3'},{'Q',' '},{'3','E'},{'F',' '},{'R',' '},{'4',' '},{'G',' '},{'S','2'},{'5','Z'},{'H','H'},{'T','T'},{'6',' '},{'I','I'},{'U','U'},{'7',' '},{'J','L'},{'V','V'},{'8','8'},{'K',' '},{'W','W'},{'9',' '},{'L','J'},{'X','X'} };
    string target;
    string::iterator left;
    string::iterator right;
    bool mirroredString(true);
    bool palindrome(true);
    while (cin >> target)
    {
        mirroredString = true;
        palindrome = true;
        left = target.begin();
        right = target.end()-1;
        while (left <= right)
        {
            if(*left != Reserve.at(*right))
                mirroredString = false;
            if(*left != *right)
                palindrome = false;
            left++;
            right--;
        }
        if (!palindrome && !mirroredString)
            cout << target+" -- is not a palindrome." << endl << endl;
        else if (palindrome && !mirroredString)
            cout << target+" -- is a regular palindrome." << endl << endl;
        else if (!palindrome && mirroredString)
            cout << target+" -- is a mirrored string." << endl << endl;
        else if (palindrome && mirroredString)
            cout << target+" -- is a mirrored palindrome." << endl << endl;
    }
    return 0;
}