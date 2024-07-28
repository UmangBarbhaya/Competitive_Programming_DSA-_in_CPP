/*input
-123
*/
#include<bits/stdc++.h>
using namespace std;
int reverseNum(int num);
int main()
{
	int n;
	cin>>n;
	cout<<reverseNum(n)<<endl;
}
int reverseNum(int num)
{
	int ans = 0;
	while(num!=0)
	{
		int rem = num%10;
		if(num>INT_MAX/10 || (num==INT_MAX/10 && rem>INT_MAX%10))
			return 0;
		if(num<INT_MIN/10 || (num==INT_MIN/10 && rem<INT_MIN%10))
			return 0;
		num = num/10;
		ans = ans*10+rem;
	}
	return ans;
}

