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
int H,W;
int sx,sy,gx,gy;
char f[505][505];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool used[505][505];
void dfs(int x,int y)
{
	used[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0||ny<0||nx>=H||ny>=W)continue;
		if(used[nx][ny])continue;
		if(f[nx][ny]=='#')continue;
		dfs(nx,ny);
	}
	return;
}
int main()
{
	memset(used,false,sizeof(used));
	cin >> H >> W;
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			cin >> f[i][j];
			if(f[i][j]=='s')sx=i,sy=j;
			if(f[i][j]=='g')gx=i,gy=j;
		}
	}
	dfs(sx,sy);
	/*for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)cout << (int)used[i][j];
		cout << endl;
	}*/
	if(used[gx][gy])printf("Yes\n");
	else printf("No\n");
	return 0;
}
