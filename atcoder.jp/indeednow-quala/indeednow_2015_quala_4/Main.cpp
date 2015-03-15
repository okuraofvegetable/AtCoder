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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int now[7][7];
P goal[50];
int H,W,ans = 24;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dist(P a,P b){return abs(a.fi-b.fi)+abs(a.sec-b.sec);}
int rem()
{
	int res = 0;
	rep(i,H)rep(j,W)
	{
		if(now[i][j]==0)continue;
		res += dist(P(i,j),goal[now[i][j]]);
	}
	return res;
}
void dfs(int t,int x,int y)
{
	int r = rem();
	if(r==0)
	{
		ans = min(ans,t);
		return;
	}
	if(t+r>=ans)return;
	rep(i,4)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>=H||ny<0||ny>=W)continue;
		swap(now[x][y],now[nx][ny]);
		dfs(t+1,nx,ny);
		swap(now[x][y],now[nx][ny]);
	}
	return;
}
int main()
{
	cin >> H >> W;
	int st=0,sx,sy;
	rep(i,H)rep(j,W)
	{
		cin >> now[i][j];
		if(now[i][j]==0)sx=i,sy=j;
	}
	repn(i,1,H+1)repn(j,1,W+1)goal[(i-1)*W+j]=P(i-1,j-1);
	dfs(st,sx,sy);
	cout << ans << endl;
	return 0;
}
