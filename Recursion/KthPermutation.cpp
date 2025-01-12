/*input
4 17
*/
#include<bits/stdc++.h>
using namespace std;
class KthPermutation
{
/*
n = 4 
There are n! permutations. So there are 24 permutations
We want the 3rd permutation.
Brute force solution is to get all permutation recursively. and the get the k-1 permutation from the vector

Optimal solution
Find the value in the first place, then recursively find it in the 2nd, 3rd and 4th place
k= 17,   0th based indexing k=k-1 = 16
First position
0th index 1 {2,3,4}   0th - 5th index     With 1 at first postion there are 3! cases = 6 possible answer
1st index 2 {1,3,4}   6th - 11th index    With 2 at first postion there are 3! cases = 6 possible answer  
2nd index 3 {1,2,4}   12th - 17th index   With 3 at first postion there are 3! cases = 6 possible answer       k/(n-1)! = 16/6 = 2
3rd index 4 {1,2,3}   18th - 23rd index   With 4 at first postion there are 3! cases = 6 possible answer

16th means 16/6 = 2 i.e.:0th, 1st, 2nd position value is 3

Second position
k=k%(n-1)! = 16%6 = 4 
0th index 3  1  {2,4}    0th - 1st index     With 1 at second postion there are 2! cases = 2 possible answer    
1st index 3  2  {1,4}    2nd - 3rd index     With 2 at second postion there are 2! cases = 2 possible answer
2nd index 3  4  {1,2}    4th - 5th index     With 4 at second postion there are 2! cases = 2 possible answer   k/(n-2)! = 4/2 = 2

position = k/(n-2)! = 4/2 = 2


Third position
k=k%(n-2)! = 4%2= 0

0th index 3 4 1 {2} 0th    k=k/(n-3)! = 0/1 = 0    
1st index 3 4 2 {1} 1st 

k=k/(n-3)! = 0/1 = 0

answer = 3 4 1 2
*/
public:
	string getPermutation(int n, int k) {
        string ans;
        vector <int> numbers;
        //first get the n-1 factorial
        int fact = 1;
        for(int i=1;i<=(n-1);i++)
        {
        	fact=fact*i;
        	numbers.push_back(i);

        }
        numbers.push_back(n);
        k = k - 1;
        while(true)
        {
        	ans = ans+to_string(numbers[k/(fact)]);
        	numbers.erase(numbers.begin()+k/fact);
        	if(numbers.size()==0) break;
        	k=k%fact;
        	fact=fact/numbers.size();
        }

        return ans;
    }
};
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	KthPermutation kObj;
	string answer = kObj.getPermutation(n,k);
	cout<<answer<<endl;
}