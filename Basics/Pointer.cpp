#include<bits/stdc++.h>
using namespace std;

int main()
{
	int num = 5;
	char ch = 'a';
	double db = 5.43;

	int *p1 = &num;                       //P is a pointer to int which stores address of num;
	cout<< p1 << " " << &num <<endl;
	cout<<&p1 << " " <<sizeof(*p1)<<endl;

	cout<<*p1 << " " << num <<endl;
	(*p1)++;                             //add a bracket else it gives wrong output;
	cout<<*p1 << " " << num <<endl;

	
	int num2 =*p1;                      //I am just assigning value

	cout<<*p1 << " " << num2 <<endl;
	num2++;                            //It is present in separate memory location
	cout<<*p1 << " " << num2 <<endl;

	int **p2 = &p1;                        //copying a pointer
	cout<<p2<<" "<<*p2 <<" "<< **p2<<endl;

	*p1 = 100;


	//pointers and arrays;
	//Integer Arrays
	cout<<"\nPointer along with Integer arrays:\n";
	int arr[5] = {1,2,3,4,5};
	cout<<"arr: "<<arr<<endl;
	cout<<"&arr: "<<&arr<<endl;
	cout<<"&arr[0]: "<<&arr[0]<<endl;

	int *ptr = arr;
	cout<<"*ptr with arr: "<<*ptr<<endl;
	//int *ptr1 = &arr;   //it fails doesn't work
	

	int *ptr2 = &arr[0];
	cout<<"*ptr with &arr[0]: "<<*ptr2<<endl;
	
	cout<<"arr: "<<arr<<endl;
	cout<<"&arr: "<<&arr<<endl;
	cout<<"&arr[0]: "<<&arr[0]<<endl;

	cout<<"\nPointer along with Character arrays:";
	cout<<"\nCharacter Pointer:";
}
