/*input
336
*/
#include<bits/stdc++.h>
using namespace std;
int countDigits(int n)
{
	int answer=0;	
	int temp=n;
	while(temp>0)
	{
		int digit = temp%10;
		temp=temp/10;
		if(digit!=0 && n%digit==0)
			answer++;
	}
	return answer;
}
int main()
{
	int n;
	cin>>n;
	cout<<countDigits(n)<<endl;
	return 0;
}