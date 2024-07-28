#include<iostream>
using namespace std;
int global = 1;
int main()
{
	int local = 2;
	cout<<"Global variable: "<<global<<endl;
	cout<<"Local Variable: "<<local<<endl;

	int global = 3;
	cout<<"Local Variable same name as global takes precedence:" <<global<<endl;
	cout<<"Accessing Global: "<<::global<<endl;
	return 0;
}