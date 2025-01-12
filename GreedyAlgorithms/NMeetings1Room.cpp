/*input
6
1 3 0 5 8 5
2 4 6 7 9 9
*/
#include<bits/stdc++.h>
using namespace std;
class Meetings
{
public:
   int start;
   int end;
   int pos;
};
class NMeetings1Room
{
private:
   bool static comparator(Meetings m1, Meetings m2)
   {
      if(m1.end<m2.end)
         return true;
      else if(m1.end>m2.end)
         return false;
      else if(m1.pos<m2.pos)
         return true;
      else
         return false;
   }
public:
   //O(nlogn)+O(2n)               O(n)
   int countMeetingsOneRoom(vector<int> start, vector<int> end, int n)
   {
      if(n==0)
         return 0;
      Meetings mObj[n];
      for(int i=0;i<n;i++)
      {
         mObj[i].start = start[i];
         mObj[i].end = end[i];
         mObj[i].pos = i+1; 
      }
      sort(mObj,mObj+n, comparator);
      int count = 1;
      int finishTime = mObj[0].end;
      for(int i=1;i<n;i++)
      {
         if(mObj[i].start > finishTime)
         {
            count++;
            finishTime = mObj[i].end;
         }
      }
      return count;
   }
};
int main()
{
   int n;
   cin>>n;
   vector<int> start(n);
   vector<int> end(n);
   for(int i = 0;i<n;i++)
   {
      cin>>start[i];
   }
   for(int i=0;i<n;i++)
   {
      cin>>end[i];
   }
   NMeetings1Room nObj;
   cout<<nObj.countMeetingsOneRoom(start,end,n);
   return 0;
}