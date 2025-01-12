/*input
*/
#include<bits/stdc++.h>
using namespace std;
class BalancedParenthesis
{
public:
	bool isValidParenthesis(string s)
	{
		stack<char> st;
		for(int i=0;i<s.size();i++)
		{
			//cout<<s[i]<<" "<<endl;
			if(s[i]=='(' || s[i]=='{' || s[i]=='[')
			{
				//cout<<s[i]<<" "<<endl;

				st.push(s[i]);
			}
			else
			{

				if(st.empty())
					return false;
				char ch = st.top();
				st.pop();
				if((s[i]==')' && ch=='(') || (s[i]==']' && ch=='[') || (s[i]=='}' && ch=='{'))
				{
					
					continue;
				}
				return false;
			}
		}
		if(st.empty())
			return true;
		return false;
		//return true;
	}
};
int main()
{
	string s = "((({{}}))";
	string s1 = "((({{}}))())";
	BalancedParenthesis bobj;
	cout<<bobj.isValidParenthesis(s)<<endl;
	cout<<bobj.isValidParenthesis(s1)<<endl;
	return 0;
}