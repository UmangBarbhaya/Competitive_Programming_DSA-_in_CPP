/*input
5
2 2 5 6 10
5
1 1 2 12 15
*/
#include<bits/stdc++.h>
using namespace std;
class Union
{
public:
	vector<int> findUnion(vector<int> arr1, vector<int> arr2, int n, int m)
	{
		vector<int> answer;
		int i=0;
		int j=0;
		while(i<n && j<m)
		{
			if(arr1[i]<=arr2[j])
			{
				if(answer.size()==0 || answer.back()!=arr1[i])
					answer.push_back(arr1[i]);
				i++;
			}
			else
			{
				if(answer.size()==0 || answer.back()!=arr2[j])
					answer.push_back(arr2[j]);
				j++;
			}
		}
		while(i<n)
		{
			if(answer.size()==0 || answer.back()!=arr1[i])
					answer.push_back(arr1[i]);
				i++;
		}
		while(j<m)
		{
			if(answer.size()==0 || answer.back()!=arr2[j])
					answer.push_back(arr2[j]);
				j++;
		}
		return answer;
	}

};
int main()
{
	int n,m;
	cin>>n;
	vector<int> arr1(n);
	for(int i=0; i<n;i++)
	{
		cin>>arr1[i];
	}
	cin>>m;
	vector<int> arr2(m);
	for(int i=0;i<m;i++)
	{
		cin>>arr2[i];
	}
	Union u_obj;
	vector <int> answer = u_obj.findUnion(arr1, arr2, n, m);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;

	return 0;
}