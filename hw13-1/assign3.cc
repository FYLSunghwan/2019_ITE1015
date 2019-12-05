#include <iostream>
using namespace std;

class A
{
};
class B : public A
{
};
class C : public B
{
};
  
int main(){
	int n;
	cout << "input num(0~2):";
	cin >> n;	
	
	try{
		if(n == 0)
			throw new A;
		else if(n == 1)	
			throw new B;
		else if (n ==2)
			throw new C;
		else
			throw string("invalid input");
	} catch(C* c) {
        cout << "throw new C has been called";
    } catch(B* b) {
        cout << "throw new B has been called";
    } catch(A* a) {
        cout << "throw new A has been called";
    } catch(string& s) {
        cout << s;
    }

	//implement here
		
	return 0;
}
