#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> P;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000ll
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
int N;
ll A[100100];
vector<int> g[100100];
int par[100100];
int deg[100100];
ll c[100100];
ll csum[100100];
void dfs(int v,int p){
	par[v]=p;
	int cnt = 0;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(u==p)continue;
		cnt++;
		dfs(u,v);
		csum[v]+=c[u];
	}
	if(cnt>0)c[v]=2ll*A[v]-csum[v];
	else c[v]=A[v];
}
void fail(int x=-1){
	//cout << "fail: " << x << endl;
	cout << "NO" << endl;
	exit(0);
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> A[i];
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		deg[a]++;
		deg[b]++;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,-1);
	for(int i=0;i<N;i++){
		//cout << i << ' ' << c[i]  << ' ' << csum[i] << endl;
		if(i>0&&c[i]<0ll)fail();
	}
	if(deg[0]==1){
		if(c[g[0][0]]!=A[0])fail(0);
	}else{
		if(c[0]!=0)fail();
		for(int i=0;i<g[0].size();i++){
			int u = g[0][i];
			if(c[u]>A[0])fail();
		}
	}
	for(int i=1;i<N;i++){
		if(deg[i]>1&&c[i]>csum[i])fail(1);
		ll rem = 0ll;
		ll h = (csum[i]-c[i])/2ll;
		for(int j=0;j<g[i].size();j++){
			int u = g[i][j];
			if(par[i]==u)continue;
			rem += max(0ll,c[u]-h);
		}
		if(rem>c[i])fail(2);
	}
	cout << "YES" << endl;
	return 0;
}