#include <iostream>
using namespace std;
int patient[20] = {0};

void swap(int *pa,int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
    return;
}
void quicksort(int left,int right)
{
    if (left>right)
        return;
    int i,j,t,temp;
    i = left;
    j = right;
    temp = patient[left];
    while (i!=j)
    {
        while (patient[j]>=temp && i<j)
            j--;
        while (patient[i]<=temp && i<j)
            i++;
        if (i<j)
            swap(&patient[i],&patient[j]);
    }
    patient[left] = patient[i];
    patient[i] = temp;
    quicksort (left,i-1);
    quicksort (i+1,right);
    return;
}

int main()
{
    int n(0);
    cin >> n;
    for(int i(0);i < n;i++)
        cin >> patient[i];
    
    quicksort(0,n-1);
    
    int currentTime(60),treatedPatient(0);
    while(currentTime <= 170  && treatedPatient != n)
    {
        if(patient[treatedPatient] >= currentTime)
            currentTime = patient[treatedPatient] + 10;
        else
            currentTime += 10;
        
        if (currentTime > 180)
            break;
        
        treatedPatient++;
    }

    cout << treatedPatient << endl;
    return 0;
}