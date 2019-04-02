#include<bits/stdc++.h>
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
int N,M,Q;
vector<int> g[100100];
int v[100100],d[100100],c[100100];
int dp[100100][12];
void rec(int v,int d,int q){
	if(dp[v][d]!=-1)return;
	if(d<0)return;
	dp[v][d]=q;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		rec(u,d-1,q);
	}
	rec(v,d-1,q);
}
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}
	memset(dp,-1,sizeof(dp));
	for(int i=Q-1;i>=0;i--){
		rec(v[i],d[i],i);
	}
	for(int i=0;i<N;i++){
		if(dp[i][0]==-1)cout << 0 << endl;
		else cout << c[dp[i][0]] << endl;
	}
	return 0;
}