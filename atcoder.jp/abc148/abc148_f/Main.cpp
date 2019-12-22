#include <bits/stdc++.h>
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
#define MAX_N 101000
#define MAX_LOG_V 20
int N,root=0;
vector<int> g[MAX_N];
int parent[MAX_LOG_V][MAX_N];
int depth[MAX_N];
void dfs(int v,int p,int d){
	depth[v]=d;
	parent[0][v]=p;
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]!=p){
			dfs(g[v][i],v,d+1);
		}
	}
	return;
}
void init(){
	dfs(root,-1,0);
	//dfs();
	for(int i=0;i<MAX_LOG_V-1;i++){
		for(int v=0;v<N;v++){
			if(parent[i][v]==-1)parent[i+1][v]=-1;
			else parent[i+1][v]=parent[i][parent[i][v]];
		}
	}
	return;
}
int lca(int u,int v){
	if(depth[u]>depth[v])swap(u,v);
	for(int i=MAX_LOG_V-1;i>=0;i--){
		if(((depth[v]-depth[u])>>i)&1)v=parent[i][v];
	}
	if(u==v)return u;
	for(int i=MAX_LOG_V-1;i>=0;i--){
		if(parent[i][u]!=parent[i][v]){
			u=parent[i][u];
			v=parent[i][v];
		}
	}
	return parent[0][u];
}

int main(){
	cin >> N;
  int U,V;
  cin >> U >> V;
  U--;V--;
  root = V;
	for(int i=0;i<N-1;i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    g[a].pb(b);
    g[b].pb(a);

	}
	init();
  int ans = 0;
  for(int i=0;i<N;i++){
    if(g[i].size()==1&&i!=root){
      int c = lca(i,U);
      // cout << i << endl;
      // cout << c << endl;
      if(c==U){
        ans = max(ans,depth[i]-1);
      }else{
        int A = depth[c];
        int B = depth[U]-depth[c];
        // cout << A << ' ' << B << endl;
        if(A>B){
          ans = max(ans,depth[i]-1);
        }
      }
    }
  }
  cout << ans << endl;
	return 0;
}

