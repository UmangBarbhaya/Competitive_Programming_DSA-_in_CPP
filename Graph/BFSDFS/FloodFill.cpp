#include<bits/stdc++.h>
using namespace std;
class FloodFill
{
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
		if(image[sr][sc]==color)
		{
			return image;
		}  
		int m = image.size();
		int n = image[0].size();
		int oldcolor = image[sr][sc];
		image[sr][sc] = color;
		queue<pair<int,int>> q;
		q.push({sr,sc});
		int xaxis[] = {1,-1,0,0};
		int yaxis[] = {0,0,-1,1};
		while(!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for(int i=0;i<4;i++)
			{
				int x1 = x+xaxis[i];
				int y1 = y+yaxis[i];
				if(x1>=0 && x1<m && y1>=0 && y1<n && image[x1][y1]==oldcolor)
				{
					image[x1][y1]=color;
					q.push({x1,y1});
				}
			}


		}
		return image;
    }
};
int main()
{
	return 0;
}