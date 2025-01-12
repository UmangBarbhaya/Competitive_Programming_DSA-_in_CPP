/*input
5
4 5 2 10 8
*/
#include<bits/stdc++.h>
using namespace std;
class GreaterSmallerElements
{
	/*
	1 5 2 3
	-1 
	*/
	public:
		vector<int> PSE(vector<int> arr)
		{
			stack<int> st;
			vector<int> pse(arr.size());
			for(int i=0;i<arr.size();i++)
			{
				while(!st.empty() && st.top()>=arr[i])
				{
					st.pop();
				}
				if(st.empty())
				{
					pse[i] = -1;
				}
				else
				{
					pse[i] = st.top();
				}
				st.push(arr[i]);
			}
			return pse;
		}
		vector<int> NSE(vector<int> arr)
		{
			int n = arr.size();
			vector<int> nse(n);
			stack <int> st;
			for(int i=n-1;i>=0;i--)
			{
				while(!st.empty() && st.top()>=arr[i])
				{
					st.pop();
				}
				if(st.empty())
				{
					nse[i]=-1;
				}
				else
				{
					nse[i] = st.top();
				}
				st.push(arr[i]);
			}
			return nse;
		}
		vector<int> PGE(vector<int> arr)
		{
			int n = arr.size();
			vector<int> pge(n);
			stack<int> st;
			for(int i = 0;i<n;i++)
			{
				while(!st.empty() && st.top()<=arr[i])
				{
					st.pop();
				}
				if(st.empty())
				{
					pge[i]=-1;
				}
				else
				{
					pge[i]=st.top();
				}
				st.push(arr[i]);
			}
			return pge;
		}
		vector<int> NGE(vector<int> arr)
		{
			int n = arr.size();	
			stack<int> st;
			vector<int> nge(n);
			for(int i=n-1;i>=0;i--)
			{
				while(!st.empty() && st.top()<=arr[i])
				{
					st.pop();
				}
				if(st.empty())
				{
					nge[i] = -1;
				}
				else
				{
					nge[i] = st.top();
				}
				st.push(arr[i]);
			}
			return nge;
		}

		vector<int> NGECircular(vector<int> arr)
		{
			int n = arr.size();
			stack <int> st;
			vector<int> ngec(n);
			for(int i=2*n-1;i>=0;i--)
			{
				while(!st.empty() && st.top()<=arr[i%n])
				{
					st.pop();
				}
				if(i<n)
				{
					if(st.empty())
					{
						ngec[i] = -1;
					}
					else
					{
						ngec[i] = st.top();
					}
				}
				st.push(arr[i%n]);
			}
			return ngec;
		}

		vector<int> PGECircular(vector<int> arr)
		{
			int n = arr.size();
			stack <int> st;
			vector<int> ngec(n);
			for(int i=-1*(n);i<n;i++)
			{
				while(!st.empty() && st.top()<=arr[(i+n)%n])
				{
					st.pop();
				}
				if(i>=0)
				{
					if(st.empty())
					{
						ngec[i] = -1;
					}
					else
					{
						ngec[i] = st.top();
					}
				}
				st.push(arr[(i+n)%n]);
			}
			return ngec;
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
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	GreaterSmallerElements gsObj;
	cout<<"PSE: ";
	print(gsObj.PSE(arr));
	cout<<"NSE: ";
	print(gsObj.NSE(arr));
	cout<<"PGE: ";
	print(gsObj.PGE(arr));
	cout<<"NGE: ";
	print(gsObj.NGE(arr));
	cout<<"NGECircular: ";
	print(gsObj.NGECircular(arr));
	cout<<"PGECircular: ";
	print(gsObj.PGECircular(arr));
	return 0;
}
