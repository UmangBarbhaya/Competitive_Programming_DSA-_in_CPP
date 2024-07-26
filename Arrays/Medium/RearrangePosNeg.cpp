/*input
4
1 2 -4 -5
6
1 2 -4 -5 3 4
*/
#include<bits/stdc++.h>
using namespace std;
class RearrangePosNeg
{
public:
	vector <int> rearrangeEqualPosNeg(vector<int> arr)
	{
		vector <int> ans(arr.size());
		int pos=0,neg=1;
		for(int i=0;i<arr.size();i++)
		{
			if(arr[i]>0)
			{
				ans[pos] = arr[i];
				pos+=2;
			}
			else
			{
				ans[neg] = arr[i];
				neg+=2;
			}
		}
		return ans;
	}
	void rearrangeUnequalPosNeg(vector <int> &arr)
	{
		//this method can also be used by equal case
		vector <int> pos;
		vector <int> neg;
		for(int i=0;i<arr.size();i++)
		{
			if(arr[i]>=0)
				pos.push_back(arr[i]);
			else
				neg.push_back(arr[i]);
		}
		if(pos.size()>neg.size())
		{
			for(int i=0;i<neg.size();i++)
			{
				arr[2*i] = pos[i];
				arr[2*i+1] = neg[i]; 
			}
			int index = 2*neg.size();
			for(int i=neg.size();i<pos.size();i++)
			{
				arr[index] = pos[i];
				index++;
			}
		}
		else
		{
			for(int i=0;i<pos.size();i++)
			{
				arr[2*i] = pos[i];
				arr[2*i+1] = neg[i]; 
			}
			int index = 2*pos.size();
			for(int i=pos.size();i<neg.size();i++)
			{
				arr[index] = neg[i];
				index++;
			}
		}
	}
};
void print(vector <int> arr)
{
	for(int i = 0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{	
	RearrangePosNeg rpn_obj;
	cout<<"Equal positive and negative element: ";
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<int> ans = rpn_obj.rearrangeEqualPosNeg(arr);
	print(ans);
	cout<<"Unequal positive and negative element: ";
	int m;
	cin>>m;
	vector <int> arr1(m);
	for(int i=0;i<m;i++)
	{
		cin>>arr1[i];
	}
	rpn_obj.rearrangeUnequalPosNeg(arr1);
	print(arr1);
	return 0;
}