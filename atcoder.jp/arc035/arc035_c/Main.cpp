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
#define INF 1000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M,K;
ll dist[405][405];
ll S=0ll;
void print()
{
	rep(i,N)
	{
		rep(j,N)cout << dist[i][j] << ' ';
		cout << endl;
	}
	return;
}
int main()
{
	scanf("%d %d",&N,&M);
	rep(i,N)rep(j,N)dist[i][j]=INF;
	rep(i,N)dist[i][i]=0;
	rep(i,M)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		dist[a][b]=c;
		dist[b][a]=c;
	}
	rep(k,N)rep(i,N)rep(j,N)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	rep(i,N)rep(j,i)S+=dist[i][j];
	//print();
	scanf("%d",&K);
	rep(i,K)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--;y--;
		if(dist[x][y]<=z)
		{
			printf("%lld\n",S);
			continue;
		}
		ll res = 0ll;
		rep(j,N)rep(k,N)
		{
			int D = min(dist[j][x]+dist[y][k]+z,dist[j][y]+dist[x][k]+z);
			if(dist[j][k]>D)
			{
				res+=(dist[j][k]-D);
				dist[j][k]=D;
			}
		}
		//print();
		S-=res/2;
		printf("%lld\n",S);
	}
	return 0;
}
