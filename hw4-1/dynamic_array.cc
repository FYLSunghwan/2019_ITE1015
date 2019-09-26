#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int* ars = new int[n];
    for(int i=0;i<n;i++)
        ars[i] = i;
    for(int i=0;i<n;i++)
        cout<<ars[i]<<" ";
    cout<<endl;
    delete[] ars;
    return 0;
}