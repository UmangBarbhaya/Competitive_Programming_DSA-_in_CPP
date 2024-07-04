/*input
2
2 1
1 2
7 3
1 2 3 4 5 6 7
*/
#include<bits/stdc++.h>
using namespace std;
class ArrayOperation
{
	public:
		void rotateArrayRightK(vector <int> &nums, int k)
		{
			k=k%nums.size();
			reverseArray(nums,0,nums.size()-1);
			reverseArray(nums,0,k-1);
			reverseArray(nums,k,nums.size()-1);
		}
		void rotateArrayLeftK(vector <int> &nums, int k)
		{
			k=k%nums.size();
			reverseArray(nums,0,k-1);
			reverseArray(nums,k,nums.size()-1);
			reverseArray(nums,0,nums.size()-1);
		}
	//private:
		void reverseArray(vector <int> &nums, int start, int end)
		{
			while(start<end)
			{
				int temp = nums[start];
				nums[start] = nums[end];
				nums[end] = temp;
				start++;
				end--;
			}
		}
};
void print(vector <int> &nums)
{
	for(int i=0;i<nums.size();i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<"\n";
}
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int k,n;
		cin>>n;
		cin>>k;
		vector <int> nums(n);
		for(int j=0;j<n;j++)
		{
			cin>>nums[j];
		}
		ArrayOperation ao_obj;
		cout<<"Rotating Array From Left\n";
		ao_obj.rotateArrayLeftK(nums,k);
		print(nums);

		sort(nums.begin(),nums.end());
		ao_obj.rotateArrayRightK(nums,k);
		cout<<"Rotating Array From Right\n";
		print(nums);

	}
	return 0;
}