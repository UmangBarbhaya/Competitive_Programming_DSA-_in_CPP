/*input
3
5
0 0 1 2 3
5
1 2 3 0 0
5
0 1 0 3 12
*/
#include<bits/stdc++.h>
using namespace std;
class MoveZeros
{
public:
	void moveZerostoEnd(vector<int> &inputArr)
	{
		int zero = -1; //Keep tracks of zero
		for(int i=0; i<inputArr.size(); i++)
		{
			if(inputArr[i] == 0)
			{
				zero = i;
				break;
			}
		}
		if(zero==-1)
			return;

		//Now I need to look after zero + 1 pointer
		
		for(int i=zero+1; i<inputArr.size();i++)
		{
			if(inputArr[i] != 0)
			{
				swap(inputArr, i , zero);
				zero++;

			}
		}
	}
	void swap(vector<int> &arr,int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
};
void arrprint(vector<int> &arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t-- > 0)
	{
		int n;
		cin>>n;
		vector<int> inputArr(n);
		for(int i=0;i<n;i++)
		{
			cin>>inputArr[i];
		}
		cout<<"Input Array: ";
		arrprint(inputArr);
		MoveZeros mz_obj;
		mz_obj.moveZerostoEnd(inputArr);
		cout<<"Output Array: ";
		arrprint(inputArr);

	}

	return 0;
}