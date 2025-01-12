/*input
4
1 3 5 7
5
0 2 6 8 9
*/
#include<bits/stdc++.h>
using namespace std;
class MergeSortedArrays
{
	public:
		void twoPointer(vector<int> &arr1, vector<int> &arr2)
		{
			int n = arr1.size();
			int m = arr2.size();
			int i=n-1;
			int j=0;
			while(i>=0 && j<m)
			{
				if(arr1[i]> arr2[j])
				{
					swap(arr1[i],arr2[j]);
					j++;
					i--;
				}
				else
					break;
			}
			sort(arr1.begin(),arr1.end());
			sort(arr2.begin(),arr2.end());
		}
		void gapMethod(vector<int> &arr1, vector<int> &arr2)
		{
			int n = arr1.size();
			int m = arr2.size();
			int len = n+m;
			int gap = len/2 + len%2;
			while(gap>0)
			{
				int left = 0;
				int right = gap;
				while(right<len)
				{
					if(left<n && right<n)
					{
						swapIfGreater(arr1,arr1,left,right);
					}
					else if(left<n && right>=n)
					{
						swapIfGreater(arr1,arr2,left,right-n);
					}
					else if(left>=n && right>=n)
					{
						swapIfGreater(arr2,arr2,left-n,right-n);
					}
					left++;
					right++;
				}
				if(gap==1)
					break;
				gap=gap/2 + gap%2;
			}
		}
		private:
		void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int i,int j)
		{
			if(arr1[i]>arr2[j])
				swap(arr1[i],arr2[j]);
		}
};
void print(vector<int> arr1, vector<int> arr2)
{
	for(int i=0;i<arr1.size();i++)
	{
		cout<<arr1[i]<<" ";
	}
	for(int j=0;j<arr2.size();j++)
	{
		cout<<arr2[j]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n,m;
	cin>>n;
	vector<int> arr1(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	cin>>m;
	vector<int> arr2(m);
	for(int j=0;j<m;j++)
	{
		cin>>arr2[j];
	}
	MergeSortedArrays msaObj;
	//msaObj.twoPointer(arr1, arr2);
	msaObj.gapMethod(arr1, arr2);
	print(arr1, arr2);
}