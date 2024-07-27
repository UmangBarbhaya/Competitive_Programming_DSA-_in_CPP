/*input
2
3
1 3 2
6
2 1 5 4 3 0
*/
#include<bits/stdc++.h>
using namespace std;
class NextPermutation
{
public:
	vector <int> findNextPermutation(vector<int> &inputArr)
	{
		/*Step 1: Reverse find breakpoint element (a[i+1] > a[i])
		 *Step 2: Find the smallest element in right greater than breakpoint element and swap
		 *	      Post swap break it
		 *   	  Note: Right side of breakpoint will be in descending order
		 *Step 3: Reverse the right side.
		 */
		int ind = -1;
		int n = inputArr.size();
		for(int i=n-2;i>=0;i--)
		{
			if(inputArr[i+1]>inputArr[i])
			{
				ind=i;
				break;
			}
		}
		if(ind == -1)
		{
			reverse(inputArr.begin(), inputArr.end());
			return inputArr;
		}

		for(int i=n-1;i>ind;i--)
		{
			if(inputArr[ind]<inputArr[i])
			{
				swap(inputArr[i], inputArr[ind]);
				break;
			}
		}
		reverse(inputArr.begin()+ind+1, inputArr.end());
		return inputArr;

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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> inputArr(n);
		for(int i=0;i<n;i++)
		{
			cin>>inputArr[i];
		}
		NextPermutation npObj;
		vector<int> outputArr = npObj.findNextPermutation(inputArr);
		print(outputArr);

	}
	return 0;
}