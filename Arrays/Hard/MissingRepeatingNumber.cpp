/*input
6
4 3 6 2 1 1
*/
#include<bits/stdc++.h>
using namespace std;
class MissingRepeatingNumber
{
public:
	vector<int> getUsingMathsFormula(vector<int> arr)
	{
		int n = arr.size();
		long long arrsum = 0;
	    long long arrsumSquare=0;
	    for(int i=0;i<n;i++)
		{
			arrsum+=arr[i];
			arrsumSquare+=arr[i]*arr[i];
		}
		long long sumFormula = n*(n+1)/2;
		long long sumSquareFormula = n*(n+1)*(2*n+1)/6;
		long long sum1 = sumFormula-arrsum;
		long long sum2 = (sumSquareFormula-arrsumSquare)/sum1;

		long long missing = (sum1+sum2)/2;
		long long repeating = missing-sum1;
		return {(int)missing, (int)(repeating)};
	}
	vector<int> getUsingXOR(vector<int> arr)
	{
		int n = arr.size();
		
		int totalXOR = 0;
		for(int i=0;i<n;i++)
		{
			totalXOR^=arr[i];
			totalXOR^=(i+1);
		}
		int rightBitOne = 0;
		while(1)
		{
			if((totalXOR & 1<<rightBitOne) !=0)
				break;
			rightBitOne++;
		}
		int one=0;
		int zero=0;
		for(int i=0;i<n;i++)
		{
			if((arr[i] & 1<<rightBitOne) !=0)
			{
				one = one^arr[i];
			}
			else
			{
				zero = zero ^ arr[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if((i & 1<<rightBitOne) !=0)
			{
				one = one^i;
			}
			else
			{
				zero = zero ^ i;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(arr[i]==one)
				return {zero,one};
		}
		return{one,zero};
	}
};
int main()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	MissingRepeatingNumber mrnObj;
	vector<int> answer = mrnObj.getUsingMathsFormula(arr);
	cout<<answer[0]<<" "<<answer[1]<<endl;
	vector<int> answer1 = mrnObj.getUsingXOR(arr);
	cout<<answer1[0]<<" "<<answer1[1]<<endl;
}

