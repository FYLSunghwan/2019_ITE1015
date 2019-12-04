#include <iostream>
#include "My_shared_ptr.h"
using namespace std;

typedef unsigned long T;
int main()
{
	{		
		My_shared_ptr<T> a;
		cout<<a.getCount()<<endl;
		{
			My_shared_ptr<T> b(new T(5));
			cout<<a.getCount()<<endl;
			cout<<b.getCount()<<endl;
			
			if(a.get_m_obj() == b.get_m_obj())
				cout << "resource shared" << endl;
			
			a = b;//assignment operation
			cout<<a.getCount()<<endl;
			cout<<b.getCount()<<endl;
			
			if(a.get_m_obj() == b.get_m_obj())
				cout << "resource shared" << endl;
		}
		cout<<a.getCount()<<endl;
	}
	return 0;
}
