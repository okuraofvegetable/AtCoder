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
struct edge{
	int to,cost;
	edge(){}
	edge(int to,int cost):to(to),cost(cost){}
};
int N;
vector<edge> g[100100];
int col[100100];
bool used[100100];
void dfs(int v,int p,int c){
	col[v]=c;
	used[v]=true;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		int u = e.to;
		int cost = e.cost;
		if(u==p)continue;
		if(used[u])continue;
		if(cost%2==0)dfs(u,v,c);
		else dfs(u,v,1-c);
	}
}
int main(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		u--;v--;
		g[u].pb(edge(v,w));
		g[v].pb(edge(u,w));
	}
	dfs(0,-1,0);
	for(int i=0;i<N;i++)cout << col[i] << endl;
	return 0;
}