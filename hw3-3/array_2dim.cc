#include <iostream>
using namespace std;

int main()
{
    int arr[3][2] , sums[2] = {0};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>arr[i][j];
            sums[j] += arr[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        cout<< arr[i][0] << " " << arr[i][1] << endl;
    }
    for(int i=0;i<2;i++)
    {
        cout << i+1 << " 번쨰 열의 숫자의 합: " << sums[i] << endl;
    }
    return 0;
}