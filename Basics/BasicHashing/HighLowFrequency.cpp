/*input
10
10 3 5 5 4 4 10 10 10 10
*/
#include<bits/stdc++.h>
using namespace std;
class HighLowFrequency
{
public:
	void findHighLowFreqElem(vector<int> arr)
	{
		int n = arr.size();
		unordered_map <int,int> map;
		for(int i=0;i<n;i++)
		{
			map[arr[i]]++;
		}
		int maxele=INT_MIN;
		int minele=INT_MAX;
		int minfreq=INT_MAX;
		int maxfreq=INT_MIN;
		for(auto it: map)
		{
			if(it.second>maxfreq)
			{
				maxfreq = it.second;
				maxele = it.first;
			}
			if(it.second<minfreq)
			{
				minfreq = it.second;
				minele = it.first;
			}
		}
		cout<<"Max Frequency: "<<maxele<<" "<<maxfreq<<endl;
		cout<<"Min Frequency: "<<minele<<" "<<minfreq<<endl;
	}
};
int main()
{
	int n;
	cin>>n;
	vector <int> inputArr(n);
	for(int i=0;i<n;i++)
	{
		cin>>inputArr[i];
	}
	HighLowFrequency hlfObj;
	hlfObj.findHighLowFreqElem(inputArr);
	return 0;
}