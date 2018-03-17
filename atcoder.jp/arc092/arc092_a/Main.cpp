#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007ll
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
struct bipartite_matching
{
	const static int MAX_V=210;
	int V;
	vector<int> G[MAX_V];
	int match[MAX_V];
	bool used[MAX_V];
	void init(int v){
		V = v;
	}
	void add_edge(int u,int v){
		G[u].pb(v);
		G[v].pb(u);
	}
	bool dfs(int v){
		used[v]=true;
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i],w=match[u];
			if(w<0||!used[w]&&dfs(w)){
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	int matching(){
		int res=0;
		memset(match,-1,sizeof(match));
		for(int v=0;v<V;v++){
			if(match[v]<0){
				memset(used,0,sizeof(used));
				if(dfs(v))res++;
			}
		}
		return res;
	}
};
bipartite_matching bp;
int N;
int a[105],b[105],c[105],d[105];
int main(){
	cin >> N;
	bp.init(2*N);
	for(int i=0;i<N;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0;i<N;i++){
		cin >> c[i] >> d[i];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(a[i]<c[j]&&b[i]<d[j]){
				bp.add_edge(i,j+N);
			}
		}
	}
	cout << bp.matching() << endl;
	return 0;
}