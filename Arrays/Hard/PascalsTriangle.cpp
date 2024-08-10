/*input
5 3
7
7
*/
#include<bits/stdc++.h>
using namespace std;
class PascalsTriangle
{
	public:
		int getElementAtRowAndColumn(int row, int col)
		{
			int n = row-1;
			int r = col-1;
			int result = 1;
			for(int i=0;i<r;i++)
			{	
				result = result*(n-i);
				result = result/(i+1);
			}
			return result;
		}
		vector<int> getPascalNthRow(int n)
		{
			n = n-1;
			vector<int> answer;
			int result = 1;
			answer.push_back(result);
			
			for(int i=0;i<n;i++)
			{
				result = result*(n-i);
				result = result/(i+1);
				answer.push_back(result);
			}
			return answer;
		}
		vector <vector<int>> getFirstNPascalTriangleRows(int N)
		{
			vector <vector<int>> answer;
			for(int n=0;n<N;n++)
			{
				int result = 1;
				vector<int> tempAnswer;
				tempAnswer.push_back(result);
				for(int i=0;i<n;i++)
				{
					result = result*(n-i);
					result = result/(i+1);
					tempAnswer.push_back(result);
				}
				
				answer.push_back(tempAnswer);
			}
			return answer;
		}
};
int main()
{
	PascalsTriangle ptObj;
	cout<<"Variation 1: Print the element"<<endl;
	int r, c;
	cin>>r>>c;
	cout<<"Element present at Row "<<r<<" and Column "<<c<<": "<<ptObj.getElementAtRowAndColumn(r,c)<<endl;
	cout<<"Variation 2: Print the nth row"<<endl;
	int n1;
	cin>>n1;
	vector <int> answer = ptObj.getPascalNthRow(n1);
	for(int i=0;i<answer.size();i++)
	{
		cout<<answer[i]<<" ";
	}
	cout<<endl;
	cout<<"Variation 3: Print all rows till n"<<endl;
	int n2;
	cin>>n2;
	vector<vector<int>> pascalTraingle = ptObj.getFirstNPascalTriangleRows(n2);
	for(int i=0;i<n2;i++)
	{
		vector<int> temp=pascalTraingle[i];
		for(int j=0;j<temp.size();j++)
		{
			cout<<temp[j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}