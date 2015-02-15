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
typedef unsigned long long ull;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
const ull B = 1000000007ull;
ull hash(string s,int a,int b)
{
	ull res = 0ull;
	for(int i=a;i<a+b;i++)
	{
		res *= B;
		res += s[i]-'A'+4;
	}
	return res;
}
int dp[150100];
int N;
vector<ull> dna;
string target;
ull BB[30];
int main()
{
	BB[0]=1ll;
	for(int i=1;i<30;i++)BB[i]=BB[i-1]*B;
	scanf("%d",&N);
	cin >> target;
	rep(i,N)
	{
		string s;
		cin >> s;
		dna.pb(hash(s,0,(int)s.size()));
	}
	SORT(dna);
	dp[0]=0;
	for(int i=1;i<=(int)target.size();i++)dp[i]=INF;
	ull h=0ull;
	for(int i=1;i<=(int)target.size();i++)
	{
		h*=B;
		h+=target[i-1]-'A'+4;
		if(binary_search(all(dna),h))dp[i]=1;
	}
	for(int i=2;i<=(int)target.size();i++)
	{
		int t = INF;
		h = target[i-1]-'A'+4;
		for(int j=2;j<=20;j++)
		{
			if(i-j<0)break;
			h += BB[j-1]*(target[i-j]-'A'+4);
			t = min(t,dp[i-j+1]);
			if(binary_search(all(dna),h))dp[i]=min(dp[i],t+1);
		}
	}
	printf("%d\n",dp[(int)target.size()]);
	return 0;
}
