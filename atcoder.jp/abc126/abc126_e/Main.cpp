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
int N,M;
int X[100100],Y[100100],Z[100100];
int used[100100];
vector<int> g[100100];
void dfs(int v){
	used[v]=true;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(used[u])continue;
		dfs(u);
	}
}
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> X[i] >> Y[i] >> Z[i];
		X[i]--;Y[i]--;
		g[X[i]].pb(Y[i]);
		g[Y[i]].pb(X[i]);
	}
	memset(used,false,sizeof(used));
	int ans = 0;
	for(int i=0;i<N;i++){
		if(!used[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl;
	return 0;
}