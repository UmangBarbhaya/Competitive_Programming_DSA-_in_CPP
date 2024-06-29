/*input
5
5 3 3 2 5
*/
#include<bits/stdc++.h>
using namespace std;
class NumberAppearsOnceOtherTwice
{
public:
	int findNumberAppearedOnce(vector<int> inputArr)
	{
		int answer = 0;
		for(int i=0;i<inputArr.size();i++)
		{
			answer^=inputArr[i];
		}
		return answer;
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
	NumberAppearsOnceOtherTwice naoot_obj;
	cout<<"Number Appeared Once: "<<naoot_obj.findNumberAppearedOnce(inputArr)<<endl;
	return 0;
}