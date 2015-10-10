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
int N,X;
int val[100100];
vector<P> g[100100];
vector<int> vx;
int cnt[100100];
map<int,int> m;
void dfs(int v,int p,int d){
	val[v]=d;
	for(int i=0;i<g[v].size();i++){
		P e = g[v][i];
		if(e.fi==p)continue;
		dfs(e.fi,v,d^e.sec);
	}
}
int main(){
	scanf("%d %d",&N,&X);
	for(int i=0;i<N-1;i++){
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		x--;y--;
		g[x].pb(P(y,c));
		g[y].pb(P(x,c));
	}
	dfs(0,-1,0);
	for(int i=0;i<N;i++){
		vx.pb(val[i]);
		m[val[i]]++;
	}
	sort(all(vx));
	vx.erase(unique(all(vx)),vx.end());
	ll ans = 0ll;
	ll eq = 0ll;
	for(int i=0;i<vx.size();i++){
		int res = X^vx[i];
		if(m.find(res)!=m.end()){
			if(res==vx[i])eq += (ll)m[res]*(ll)(m[res]-1);
			else ans += (ll)m[vx[i]]*(ll)m[res];
		}
	}
	printf("%lld\n",(ans+eq)/2);
	return 0;
}
