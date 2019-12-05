#include <iostream>
using namespace std;

int data_size = 5;
class A{
	public:		
		A(){			
			data = new int[data_size];
			for(int i = 0; i < data_size; i++)
				data[i] = i;
			cout << "constructed\n";
		}
		~A()
		{
			for(int i = 0; i < data_size; i++)
				data[i] = 0;
			delete[] data;
			data = NULL;
			cout << "destroyed\n";
		}
        A(const A& rhs)
        {
            data = new int[data_size];
            for(int i=0;i<data_size;i++)
                data[i] = rhs.data[i];
        }
		
	private:
		int* data = NULL;

        friend ostream& operator <<(std::ostream& os, const A& a);
};

int main() {
	try{
		try{
			A a;
			throw a;
		}
		catch(A &a)
		{
			#if 1//rethrow, 아래 throw twice구문도 실행시켜 볼  것
				cout << "rethrow" << endl;
				throw;
			#else//throw twice
				cout << "throw twice" << endl;
				throw a;
			#endif
		}
	}	
	catch(A &a)
	{
		cout << "exception handled" << endl;
	}
	
	return 0;
}