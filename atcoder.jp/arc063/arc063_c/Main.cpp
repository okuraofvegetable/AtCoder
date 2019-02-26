#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,K;
int root;
vector<int> g[100100];
int p[100100];
P seg[100100];
int ans[100100];
int depth[100100];
P merge(P a,P b){
	P res;
	res.fi = max(a.fi,b.fi);
	res.sec = min(a.sec,b.sec);
	return res;
}
P lap(P a){
	a.fi--;
	a.sec++;
	return a;
}
bool incl(P a,int x){
	if(a.fi<=x&&x<=a.sec)return true;
	else return false;
}
void pre_dfs(int v,int par,int d){
	depth[v]=d;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==par)continue;
		pre_dfs(g[v][i],v,d+1);
	}
}
void dfs(int v,int par){
	seg[v] = P(-INF,INF);
	if(p[v]!=-1)seg[v].fi=seg[v].sec=p[v];
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==par)continue;
		dfs(g[v][i],v);
		seg[v] = merge(seg[v],lap(seg[g[v][i]]));
	}
}
void restore(int v,int par){
	if(p[v]!=-1)ans[v]=p[v];
	if(par!=-1){
		if(incl(seg[v],ans[par]+1))ans[v]=ans[par]+1;
		else ans[v]=ans[par]-1;
	}
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==par)continue;
		restore(g[v][i],v);
	}
}
int main(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(p,-1,sizeof(p));
	cin >> K;
	for(int i=0;i<K;i++){
		int v;
		cin >> v;
		v--;
		cin >> p[v];
		root = v;
	}
	pre_dfs(root,-1,0);
	int parity = (p[root]+depth[root])%2;
	for(int i=0;i<N;i++){
		if(p[i]==-1)continue;
		if((p[i]+depth[i])%2!=parity){
			cout << "No" << endl;
			return 0;
		}
	}
	dfs(root,-1);
	for(int i=0;i<N;i++){
		if(seg[i].sec<seg[i].fi){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	restore(root,-1);
	for(int i=0;i<N;i++)cout << ans[i] << endl;
	return 0;
}