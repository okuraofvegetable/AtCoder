#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n;
int ng1,ng2,ng3;
bool a[350];
int  memo[350][105];
bool rec(int x,int d)
{
	if(d>=100)return false;
	if(a[x])return false;
	if(memo[x][d]!=-1)return memo[x][d];
	if(x<=3)
	{
		return true;
	}
	return memo[x][d]=(rec(x-1,d+1)||rec(x-2,d+1)||rec(x-3,d+1));
}
int main()
{
	memset(a,false,sizeof(a));
	memset(memo,-1,sizeof(memo));
	cin >> n;
	cin >> ng1 >> ng2 >> ng3;
	a[ng1]=true;a[ng2]=true;a[ng3]=true;
	if(rec(n,0))cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
