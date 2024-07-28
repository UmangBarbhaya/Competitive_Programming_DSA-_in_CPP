# include<iostream>
using namespace std;
class Variables
{
	public:
		int instanceVariable;
		static int staticVariable;
		int func()
		{
			int localVariable = 30;
			return localVariable;
		}
};
int main()
{
	Variables obj1;
	Variables obj2;
	obj1.instanceVariable = 10;
	obj2.instanceVariable = 20;
	cout<<"Obj1 instanceVariable: " << obj1.instanceVariable <<endl;
	cout<<"Obj2 instanceVariable: " << obj2.instanceVariable <<endl;
	cout<<"Obj1 Local Variable: "<<obj1.func()<<endl;
	cout<<"Obj2 Local Variable: "<<obj2.func()<<endl;
	//cout<<obj1.staticVariable <<endl;

	
	
	return 0;
}