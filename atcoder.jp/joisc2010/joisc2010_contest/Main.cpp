#include <cstdio>
#include <cstring>
#include <cstdlib>
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M,T,X,Y;
int p[20];
int wa_num[12][1010];
int open[12][1010],accept[12][1010];
int ans[1010];
int main()
{
	scanf("%d %d %d %d %d",&N,&M,&T,&X,&Y);
	rep(i,M)scanf("%d",&p[i]);
	rep(i,Y)
	{
		int t,n,m;
		string s;
		scanf("%d %d %d",&t,&n,&m);
		n--;m--;
		cin >> s;
		if(s=="open")open[m][n]=t;
		else if(s=="incorrect")wa_num[m][n]++;
		else accept[m][n]=t;
	}
	rep(i,M)rep(j,N)
	{
		if(accept[i][j]==0)continue;
		ans[j]+=max(p[i]-(accept[i][j]-open[i][j])-120*wa_num[i][j],X);
	}
	rep(i,N)printf("%d\n",ans[i]);
	return 0;
}
