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
const int DAT_SIZE=1<<19;
int n;
int a[200050];
vector<int> g[200050];
vector<int> euler_tour;
int id[400050],ed[400050];
struct segtree{
	int data[DAT_SIZE*2-1],datb[DAT_SIZE*2-1];
	segtree(){
		memset(data,0,sizeof(data));
		memset(datb,0,sizeof(datb));
	}
	void add(int a,int b,int x,int k,int l,int r){
		if(a>=r||b<=l)return;
		else if(a<=l&&r<=b){
			data[k]+=x;
		}else{
			datb[k]+=(min(b,r)-max(a,l))*x;
			add(a,b,x,k*2+1,l,(l+r)/2);
			add(a,b,x,k*2+2,(l+r)/2,r);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(a>=r||b<=l)return 0;
		else if(a<=l&&r<=b)return (r-l)*data[k]+datb[k];
		else{
			int res=(min(b,r)-max(a,l))*data[k];
			res+=query(a,b,k*2+1,l,(l+r)/2);
			res+=query(a,b,k*2+2,(l+r)/2,r);
			return res;
		}
	}
	void add(int a,int b,int x){
		add(a,b,x,0,0,DAT_SIZE);
	}
	int query(int a,int b){
		return query(a,b,0,0,DAT_SIZE);
	}
};
segtree seg;
void dfs(int v,int p,int &k){
	id[v]=k;
	euler_tour.pb(v);
	k++;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]!=p){
			dfs(g[v][i],v,k);
			euler_tour.pb(v);
			k++;
		}
	}
	ed[v]=k;
}
int sb[100100];
ll dp[100100];
ll efs(int v,int p){
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(u==p)continue;
		dp[v] += efs(u,v);
	}
	dp[v] += (ll)sb[v];
	return dp[v];
}
vector<ll> gg[100100];
ll ans[100100];
void ffs(int v,int p,ll pdata){
	ans[v] = dp[v]+v-sb[v]+pdata;
	ll base = pdata;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(u==p)continue;
		base += dp[u];
	}
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(u==p)continue;
		ffs(u,v,base-dp[u]+v-gg[v][i]);
	}
}
int main(){
	cin >> n;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=0;i<n;i++){
		gg[i].resize(g[i].size());
	}
	int k=0;
	dfs(0,-1,k);
	for(int i=0;i<n;i++){
		sb[i] = seg.query(id[i],ed[i]);
		for(int j=0;j<g[i].size();j++){
			int v = g[i][j];
			gg[i][j] = seg.query(id[v],ed[v]);
		}
		// cout << i << ' ' << sb[i] << endl;
		seg.add(id[i],id[i]+1,1);	
	}
	efs(0,-1);
	// for(int i=0;i<n;i++){
	// 	cout << i << ' ' << dp[i] << endl;
	// }
	ffs(0,-1,0ll);
	for(int i=0;i<n;i++){
		cout << ans[i] << endl;
	}
	return 0;
}