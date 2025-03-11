#include<bits/stdc++.h>
using namespace std;
class WordLadder1
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordset(wordList.begin(), wordList.end());
		queue<pair<string,int>> q;
		q.push({beginWord,1});
		while(!q.empty())
		{
			string currString = q.front().first;
			int currseq = q.front().second;
			q.pop();
			if(currString == endWord)
			{
				return currseq;
			}
			for(int i = 0;i< currString.size();i++)
			{
				char original = currString[i];
				for(char c='a'; c<='z';c++)
				{
					currString[i]=c;
					if(wordset.find(currString)!=wordset.end())
					{
						wordset.erase(currString);
						q.push({currString, currseq+1});
					}
				}
				currString[i]=original;
			}
		}
		return 0;
        
    }
};
int main()
{
	vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
 
    WordLadder1 wobj;
 
    int ans = wobj.ladderLength(startWord, targetWord, wordList);
 
    cout << ans;
    cout << endl;
    return 0;
	return 0;
}