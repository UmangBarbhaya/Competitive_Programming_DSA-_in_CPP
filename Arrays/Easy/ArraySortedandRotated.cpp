/*input
2
5
4 5 1 2 3
4
2 1 3 4
*/
#include<bits/stdc++.h>
using namespace std;
class ArrayCheck
{
public:
	bool isArraySortedandRotated(vector <int> &arr)
	{
		int count = 0;
		for(int i=0;i<arr.size()-1;i++)
		{
			if(arr[i]>arr[i+1])
			{
				count++;
			}
		}
		if(arr[arr.size()-1]>arr[0])
			count++;
		if(count>1)
			return false;
		return true;
	}
};
int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin >> n;
		vector <int> arr(n);
		for(int j=0;j<n;j++)
		{
			cin >>arr[j];

		}
		for(int j=0;j<n;j++)
		{
			cout <<arr[j];

		}
		ArrayCheck ac_obj;

		cout<<(bool)ac_obj.isArraySortedandRotated(arr)<<endl;
	}
	return 0;
}