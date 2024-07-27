/*input
3
3 0 1
*/
#include<bits/stdc++.h>
using namespace std;
class MissingNumbers
{
	public:
		int findMissingNumber(vector<int> inputArr)
		{
			int n = inputArr.size();
			long formulaSum = n*(n+1)/2;
			long sum = 0;
			for(int i=0;i<n;i++)
			{
				sum+=inputArr[i];
			}
			return (int)(formulaSum-sum);
		}
};
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	MissingNumbers mn_obj;
	cout<<"MissingNumber is: "<<mn_obj.findMissingNumber(arr);
	return 0;
}