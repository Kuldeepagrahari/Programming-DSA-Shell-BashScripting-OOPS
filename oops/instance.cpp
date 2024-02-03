#include <iostream> 
using namespace std; 

class Demo{ 
	public: 
	int a, b; 
	Demo() 
	{ 
		cout << "Default Constructor" << endl; 
	} 
	Demo(int a, int b):a(a),b(b) 
	{ 
		cout << "parameterized Constructor values-" << a << " "<< b << endl; 
	} 
	
	
	
}instance(100,200); 


int main() { 
	
	return 0; 
}
