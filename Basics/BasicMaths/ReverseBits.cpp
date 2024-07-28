/*input
1
*/
#include<bits/stdc++.h>
using namespace std;
long reverseBits(long n) {
    // Write your code here.
    long answer=0;
    for(int i=0;i<32;i++)
    {
        answer = answer | (n&1); 
        answer=answer<<1;
        n=n>>1;
    }
    return answer;
}
int main()
{
	long n;
	cin>>n;
	cout<<reverseBits(n)<<endl;
	return 0;
}