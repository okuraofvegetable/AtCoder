#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
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
vector<int> g[4010];
int dist[4010];
void add_edge(int a,int b){
	g[a].pb(b);
	g[b].pb(a);
}
void dfs(int v,int p,int d){
	dist[v]=d;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==p)continue;
		dfs(g[v][i],v,d+1);
	}
}
int main(){
	cin >> N >> K;
	for(int i=0;i<N-1;i++){
		int A,B;
		cin >> A >> B;
		A--;B--;
		add_edge(A,N+i);
		add_edge(N+i,B);
	}
	int ans = N;
	for(int i=0;i<=2*N-2;i++){
		memset(dist,0,sizeof(dist));
		dfs(i,-1,0);
		int cnt = 0;
		for(int j=0;j<N;j++){
			if(dist[j]>K)cnt++;
		}
		ans = min(ans,cnt);
	}
	cout << ans << endl;
	return 0;
}