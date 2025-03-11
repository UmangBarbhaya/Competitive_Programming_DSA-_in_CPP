#include<bits/stdc++.h>
using namespace std;
class WordLadder2
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        //Two steps we need to do
        //Step1: get the hashmap of word length
        unordered_map<string, int> map;
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        map[beginWord] = 1;
        wordSet.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            int level = map[word];
            for(int i=0;i<word.size();i++)
            {
                char original = word[i];
                for(char c = 'a';c<='z';c++)
                {
                    word[i]=c;
                    if(wordSet.find(word)!=wordSet.end())
                    {
                        q.push(word);
                        wordSet.erase(word);
                        map[word] = level+1;
                    }
                }
                word[i] = original;
            }
        }
        //Step 2 do a dfs backtrace;
        vector<vector<string>> ans;
        vector<string> ansList;
        ansList.push_back(endWord);
        if(map.find(endWord)!=map.end())
        {
            dfs(beginWord, endWord, ansList, ans, map);
        }
        return ans;
    }
private:
    void dfs(string beginWord, string currWord, vector<string>& ansList, vector<vector<string>> &ans, unordered_map<string, int> map)
    {
        if(currWord==beginWord)
        {
            
            reverse(ansList.begin(), ansList.end());
            
           ans.push_back(ansList);
           reverse(ansList.begin(), ansList.end());
            return;
        }
        int level = map[currWord];
        for(int i=0;i<currWord.size();i++)
        {
            char original = currWord[i];
            for(char c ='a';c<='z';c++)
            {
                currWord[i] = c;
                if(map.find(currWord)!=map.end() && map[currWord] == level-1)
                {
                    ansList.push_back(currWord);
                    dfs(beginWord,currWord,ansList, ans, map);
                    ansList.pop_back();
                }
            }
            currWord[i] = original;
        }

    }
};
int main()
{
	WordLadder2 wobj;
	vector<string> wordList = {"hot", "cog", "dog", "lot", "log","dot","hit"};
    string beginWord = "hit", endWord = "cog";
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