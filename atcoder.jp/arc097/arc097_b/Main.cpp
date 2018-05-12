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
vector<int> g[100100];
int N,M;
int p[100100];
int x[100100],y[100100];
bool used[100100];
vector<int> vec;
set<int> s;
void dfs(int v){
	used[v]=true;
	vec.pb(v);
	s.insert(p[v]);
	for(int i=0;i<g[v].size();i++){
		if(used[g[v][i]])continue;
		dfs(g[v][i]);
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&p[i]);
		p[i]--;
	}
	for(int i=0;i<M;i++){
		scanf("%d %d",&x[i],&y[i]);
		x[i]--;y[i]--;
		g[x[i]].pb(y[i]);
		g[y[i]].pb(x[i]);
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(used[i])continue;
		vec.clear();
		s.clear();
		dfs(i);
		for(int j=0;j<vec.size();j++){
			if(s.find(vec[j])!=s.end())ans++;
		}
	}
	cout << ans << endl;
	return 0;
}