#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,x) for(int i=0;i<x;i++)
#define EQ(a,b) (abs((a)-(b))<eps)
int f[505][505];
string s[505];
int R,C,K;
int sum(int L,int l,int r)
{
	return f[L][r]-(l==0?0:f[L][l-1]);
}
bool flower(int x,int y)
{
	int res=0;
	for(int i=x-K+1;i<=x+K-1;i++)
	{
		int s = abs(x-i);
		res += sum(i,y-(K-1-s),y+(K-1-s));
	}
	//cout << res << endl;
	return (res==2*K*K-2*K+1);
}
int main()
{
	scanf("%d %d %d",&R,&C,&K);
	rep(i,R)cin >> s[i];
	rep(i,R)rep(j,C)
	{
		if(s[i][j]=='o')f[i][j]=1;
		else f[i][j]=0;
	}
	rep(i,R)rep(j,C)f[i][j+1]+=f[i][j];
	int ans = 0;
	for(int i=K-1;i<=R-K;i++)
	{
		for(int j=K-1;j<=C-K;j++)
		{
			if(flower(i,j))ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
