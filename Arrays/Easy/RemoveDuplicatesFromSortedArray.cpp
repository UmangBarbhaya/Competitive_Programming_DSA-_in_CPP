/*input
2
1
1
5
1 1 2 2 3
*/
#include<bits/stdc++.h>
using namespace std;
class ArrayOperations
{
public:
	int removeDuplicatedFromSortedArray(vector <int> &nums)
	{
		int i = 0;
		for(int j=1; j<nums.size();j++)
		{
			if(nums[i]!=nums[j])
			{
				i++;
				nums[i] = nums[j];
			}
		}
		return i+1;
	}
};
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector <int> nums(n);
		for(int j=0;j<n;j++)
		{
			cin >>nums[j];
		}
		ArrayOperations ao_obj;
		int answer = ao_obj.removeDuplicatedFromSortedArray(nums);
		for(int k=0; k<answer; k++)
		{
			cout<<nums[k]<<" ";
		}
		cout<<""<<endl;
	}
	return 0;
}