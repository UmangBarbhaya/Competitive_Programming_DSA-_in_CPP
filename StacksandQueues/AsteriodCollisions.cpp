/*input
10
4 7 1 1 2 -3 -7 17 15 -16
*/
#include<bits/stdc++.h>
using namespace std;
class AsteriodCollision
{
public:
	vector<int> getAsteriodAfterCollision(vector<int> arr)
	{
		int n = arr.size();
		vector<int> st;
		for(int i=0;i<n;i++)
		{
			if(arr[i]>0)
			{
				st.push_back(arr[i]);
			}
			else
			{
				while(!st.empty() && st.back()>0 && st.back()<abs(arr[i]))
				{
					st.pop_back();
				}
				if(!st.empty() && st.back()==abs(arr[i]))
				{
					st.pop_back();
				}
				else if(st.empty()||st.back()<0)
				{
					st.push_back(arr[i]);
				}
			}
		}
		return st;
	}
};
void print(vector<int> arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	AsteriodCollision aObj;
	print(aObj.getAsteriodAfterCollision(arr));
	return 0;
}