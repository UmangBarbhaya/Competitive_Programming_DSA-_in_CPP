/*input
aabb
*/
#include<bits/stdc++.h>
using namespace std;
class PalindromicPartitioning
{
/*
You are given a string s, partition it in such a way that every substring is a palindrome. Return all such palindromic partitions of s.
Output
{a,a,b,b}, {a,a,bb}, {aa,b,b}, {aa,bb}


														aabb
								a|abb									aa|bb 				aab|b (X)        aabb| (X)

					a|a|bb     a|ab|b(x)  	a|abb|(x)          aa|b|b   	aa|bb|

	a|a|b|b 		a|a|bb|                                    aa|b|b|       return true

	return true		return true                               return true


*/
private:
	bool isPalindrome(string s, int low, int high)
	{
		while(low<high)
		{
			if(s[low++]!=s[high--])
				return false;
		}
		return true;
	}
	void generatePP(vector<vector<string>> &answer,vector<string> &temp, string s, int ind)
	{
		if(ind == s.size())
		{
			answer.push_back(temp);
			return;
		}
		for(int i=ind;i<s.size();i++)
		{
			if(!isPalindrome(s, ind, i)) continue;
			temp.push_back(s.substr(ind, i-ind+1));
			generatePP(answer,temp, s, i+1);
			temp.pop_back();
		}
	}
public:
	vector<vector<string>> getPalinPart(string s)
	{
		vector<vector<string>> answer;
		vector<string> temp;
		generatePP(answer,temp, s, 0);
		return answer;
	}
};
int main()
{
	string s;
	cin>>s;
	PalindromicPartitioning pObj;
	vector<vector<string>> answer = pObj.getPalinPart(s);
	for(int i=0;i<answer.size();i++)
	{
		for(int j=0;j<answer[i].size();j++)
		{
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}