#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
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
#define EQ(a,b) (abs((a)-(b))<EPS)
char f[1010][1010];
int a=0,b=0,c=0,w,h;
int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
void bfs(int i,int j)
{
	int cnt=1;
	queue<P> q;
	q.push(mp(i,j));
	f[i][j]='.';
	while(!q.empty())
	{
		P a=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			int nx=a.fi+dx[i],ny=a.sec+dy[i];
			if(nx>=h||nx<0||ny>=w||ny<0)continue;
			if(f[nx][ny]=='.')continue;
			f[nx][ny]='.';
			cnt++;
			q.push(mp(nx,ny));
		}
	}
	if(cnt%12==0&&cnt/12==(((int)sqrt(cnt/12))*((int)sqrt(cnt/12))))a++;
	if(cnt%16==0&&cnt/16==(((int)sqrt(cnt/16))*((int)sqrt(cnt/16))))b++;
	if(cnt%11==0&&cnt/11==(((int)sqrt(cnt/11))*((int)sqrt(cnt/11))))c++;
	return;
}
int main()
{
	cin >> h >> w;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> f[i][j];
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(f[i][j]=='o')bfs(i,j);
		}
	}
	printf("%d %d %d\n",a,b,c);
	return 0;
}
