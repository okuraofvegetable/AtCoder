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
#define INF 1000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define MAX_V 10100
struct edge{int to,cap,rev;};
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];
void add_edge(int from,int to,int cap){
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
			if(e.cap>0&&level[e.to]<0){
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f){
	if(v==t)return f;
	for(int &i=iter[v];i<G[v].size();i++){
		edge &e=G[v][i];
		if(e.cap>0&&level[v]<level[e.to]){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for(;;){
		bfs(s);
		if(level[t]<0)return flow;
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0)flow+=f;
	}
}
int H,W;
string str[104];
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++)cin >> str[i];
	int S = 0,T = H+W+1;
	// 0,1...H,H+1...H+W,H+W+1
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(str[i][j]=='o'){
				add_edge(i+1,H+j+1,1);
				add_edge(H+j+1,i+1,1);
			}
			if(str[i][j]=='S'){
				add_edge(S,i+1,INF);
				add_edge(S,H+j+1,INF);
			}
			if(str[i][j]=='T'){
				add_edge(i+1,T,INF);
				add_edge(H+j+1,T,INF);
			}
		}
	}
	int ans = max_flow(S,T);
	if(ans>=INF)cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}