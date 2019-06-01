#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
int n;
int a[10010],b[10010];
int c[10010];
int deg[10010];
int ans[10010];
vector<int> g[10010];
int vs[10010];
int K=0;
void dfs(int v,int p){
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(u==p)continue;
		dfs(u,v);
	}
	vs[K++]=v;
}
int main(){
	cin >> n;
	for(int i=0;i<n-1;i++){
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
		deg[a[i]]++;
		deg[b[i]]++;
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	for(int i=0;i<n;i++){
		cin >> c[i];
	}
	sort(c,c+n);
	K=0;
	dfs(0,-1);
	for(int i=0;i<n;i++){
		ans[vs[i]]=c[i];
	}
	int answer=0; 
	for(int i=0;i<n-1;i++){
		answer += c[i];
	}
	cout << answer << endl;
	for(int i=0;i<n;i++){
		cout << ans[i];
		if(i+1<n)cout << ' ';
		else cout << endl;
	}
	return 0;
}
