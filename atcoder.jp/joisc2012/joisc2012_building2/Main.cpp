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
#include <cassert>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
int N;
int H[100100];
vector<int> up[100100];
vector<int> down[100100];
vector<int> g[100100];
void merge(vector<int> &a,vector<int> &b){
	if(sz(a)<sz(b))swap(a,b);
	for(int i=0;i<sz(b);i++)a[i]=min(a[i],b[i]);
}
int dfs(int v,int p){
	int res = 0;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==p)continue;
		int u = g[v][i];
		res = max(res,dfs(u,v));
		bool flag = false;
		if(sz(up[v])>sz(down[u])){
			swap(up[v],down[u]);
			flag = true;
		}
		for(int j=0;j<up[v].size();j++){
			int k = lower_bound(all(down[u]),-up[v][j])-down[u].begin();
			res = max(res,j+k+1);
			if(up[v][j]<(flag?-H[v]:H[v])){
				k = lower_bound(all(down[u]),(flag?H[v]:-H[v]))-down[u].begin();
				res = max(res,j+k+2);
			}
		}
		if(flag)swap(up[v],down[u]);
		flag = false;
		if(sz(up[u])>sz(down[v])){
			swap(up[u],down[v]);
			flag = true;
		}
		for(int j=0;j<up[u].size();j++){
			int k = lower_bound(all(down[v]),-up[u][j])-down[v].begin();
			res = max(res,j+k+1);
			if(up[u][j]<(flag?-H[v]:H[v])){
				k = lower_bound(all(down[v]),(flag?H[v]:-H[v]))-down[v].begin();
				res = max(res,j+k+2);
			}
		}
		if(flag)swap(up[u],down[v]);
		merge(up[v],up[u]);
		merge(down[v],down[u]);
	}
	vector<int>::iterator it;
	it = lower_bound(all(up[v]),H[v]);
	if(it==up[v].end())up[v].pb(H[v]);
	else *it=H[v];
	it = lower_bound(all(down[v]),-H[v]);
	if(it==down[v].end())down[v].pb(-H[v]);
	else *it=-H[v];
	res = max(res,sz(up[v]));
	res = max(res,sz(down[v]));
	return res;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&H[i]);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	printf("%d\n",dfs(0,-1));
	return 0;
}