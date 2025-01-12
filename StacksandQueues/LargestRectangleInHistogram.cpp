/*input
6
2 1 5 6 2 3
*/
#include<bits/stdc++.h>
using namespace std;
class LargestRectangleHistogram
{
	/*
	      | 
	    | |
	    | |
	    | |   |
	|   | | | |
	| | | | | |

	Appoach 1 find the previous smaller element and the next smaller element in the histogram
	get the indexes left and right
	area = (right-left-1)*arr[i] O(5n)  O(2n)
	*/
public:
	long long findAreaOfLargestRectangle(vector<int> arr)
	{
		int n = arr.size();
		int maxArea=0;
		stack<int> st;
		for(int i=0;i<n;i++)
		{
			while(!st.empty() && (i == n || arr[st.top()]>=arr[i]))
			{
				int height = arr[st.top()];
				st.pop();
				int width;
				if(st.empty())
				{
					width=i;
				}
				else
				{
					width = i-st.top()-1;
				}
				maxArea = max(maxArea, width*height);
			}
			st.push(i);

		}

		return maxArea;
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
	LargestRectangleHistogram lObj;
	cout<<lObj.findAreaOfLargestRectangle(arr)<<endl;
	return 0;
}