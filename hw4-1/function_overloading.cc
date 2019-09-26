#include <iostream>
#include <string>

using namespace std;

int add(int a, int b)
{
    return a+b;
}

string add(string a, string b)
{
    return a+"-"+b;
}

int main()
{
    int n1, n2;
    string s1, s2;
    cin>>n1>>n2>>s1>>s2;
    cout<<add(n1,n2)<<endl<<add(s1,s2)<<endl;
    return 0;
}