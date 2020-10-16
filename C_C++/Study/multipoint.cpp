#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{    
    int n = 10;
    double** p = (double**)malloc(n * sizeof(double*));
    for (int i(0);i<n;i++)
    {
        double* a = (double*)malloc(n*sizeof(double));
        p[i] = a;
    }
    cout << p[1][2] << endl;
    return 0;
}