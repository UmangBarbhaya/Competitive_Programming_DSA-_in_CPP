/*input
6
10 5 2 5 10 10
*/
#include<bits/stdc++.h>
using namespace std;
class CountFrequency
{
public:
	void countFreq(vector<int> arr)
	{
		int n =arr.size();
		unordered_map<int, int> map;
		for(int i=0;i<n;i++)
		{
			map[arr[i]]++;
		}
		for(auto it: map)
		{
			cout<<it.first<<" "<<it.second<<endl;
		}
	}

};
int main()
{
	int n;
	cin>>n;
	vector<int> inputArr(n);
	for(int i=0;i<n;i++)
	{
		cin>>inputArr[i];
	}
	CountFrequency cfObj;
	cfObj.countFreq(inputArr);
	return 0;
}