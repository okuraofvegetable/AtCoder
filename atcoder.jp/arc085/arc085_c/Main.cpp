#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
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
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define MAX_V 10100
struct edge{
	int to;
	ll cap;
	int rev;
};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from,int to,ll cap){
	G[from].pb((edge){to,cap,G[to].size()});
	G[to].pb((edge){from,0,G[from].size()-1});	
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0ll&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
ll dfs(int v,int t,ll f){
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
			ll d = dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
ll max_flow(int s,int t){
	ll flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		ll f;
		while((f=dfs(s,t,INF))>0)flow+=f;
	}
}
int N,S,T;
ll a[105];
int main(){
	cin >> N;
	for(int i=1;i<=N;i++)cin >> a[i];
	S = 0, T = N+1;
	ll base = 0ll;
	for(int i=1;i<=N;i++){
		if(a[i]>=0){
			base += a[i];
			add_edge(S,i,a[i]);
			add_edge(i,T,0ll);
		}else{
			add_edge(S,i,0ll);
			add_edge(i,T,-a[i]);
		}
	}
	for(int i=1;i<=N;i++){
		for(int j=i*2;j<=N;j+=i){
			add_edge(j,i,LLINF);
		}
	}
	cout << base-max_flow(S,T) << endl;
	return 0;
}