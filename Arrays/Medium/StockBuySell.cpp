/*input
2
6
7 1 3 5 6 4
6
7 5 4 3 2 1
*/
#include<bits/stdc++.h>
using namespace std;
class StockBuySell
{
public:
	int calculateMaxProfit(vector<int> inputArr)
	{
		int maxProfit = 0;
		int minPrice = INT_MAX;
		for(int i=0; i<inputArr.size(); i++)
		{
			minPrice = min(inputArr[i], minPrice);
			maxProfit = max(maxProfit, inputArr[i]-minPrice);
		}
		return maxProfit;
	}
};
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
		StockBuySell sbc_obj;
		cout<<"Maximum Profit: "<<sbc_obj.calculateMaxProfit(inputArr)<<endl;
	}
	return 0;
}