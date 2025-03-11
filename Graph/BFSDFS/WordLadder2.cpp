#include<bits/stdc++.h>
using namespace std;
class WordLadder2
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        
        vector<string> tempVec;
         
        tempVec.push_back(beginWord);
        q.push(tempVec);

        int level=0;
        vector<vector<string>> ans;
        while(!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();
            if(vec.size()>level)
            {
                level++;
                for(int i=0;i<tempVec.size();i++)
                {
                    wordSet.erase(tempVec[i]);
                }
            }
            string latestString = vec.back();
            if(latestString==endWord)
            {
            	if(ans.size()==0)
                	ans.push_back(vec);
                else if(ans[0].size()==vec.size())
                	ans.push_back(vec);
            }
            for(int i=0;i<latestString.size();i++)
            {
                char original = latestString[i];
                for(char c = 'a';c<='z';c++)
                {
                    latestString[i] = c;
                    if(wordSet.find(latestString)!=wordSet.end())
                    {
                        vec.push_back(latestString);
                        q.push(vec);
                        tempVec.push_back(latestString);
                        vec.pop_back();
                    }
                }
                latestString[i]=original;
            }
        }
        return ans;
    }
};
int main()
{
	WordLadder2 wobj;
	vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string beginWord = "der", endWord = "dfs";
	vector<vector<string>> answer = wobj.findLadders(beginWord, endWord, wordList);
	for(int i=0;i<answer.size();i++)
	{
		for(int j = 0;j<answer[i].size();j++)
		{
			cout<<answer[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}