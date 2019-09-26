#include <string>
#include <iostream>

using namespace std;

int main()
{
    string fr, ed, news;
    cin>>fr>>ed;
    news = fr+ed;
    cout<<news<<endl;
    cout<<news.front()<<endl;
    cout<<news.back()<<endl;
    return 0;
}