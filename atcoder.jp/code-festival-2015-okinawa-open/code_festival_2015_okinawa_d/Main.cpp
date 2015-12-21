#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N,M;
vector<int> g[100100];
int out[100100],in[100100];
int state[100100],cnt[100100];
void add_edge(int from,int to){
	g[from].pb(to);
	out[from]++;
	in[to]++;	
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		add_edge(b,a);
	}
	queue<int> q;
	for(int i=0;i<N;i++)if(in[i]==0){
		state[i]=-1;
		q.push(i);
	}
	while(!q.empty()){
		int a = q.front();
		q.pop();
		if(state[a]==-1){
			for(int i=0;i<g[a].size();i++){
				if(state[g[a][i]]==0){
					state[g[a][i]]=1;
					q.push(g[a][i]);
				}
			}
		}else{
			for(int i=0;i<g[a].size();i++){
				if(state[g[a][i]]==0){
					cnt[g[a][i]]++;
					if(in[g[a][i]]==cnt[g[a][i]]){
						state[g[a][i]]=-1;
						q.push(g[a][i]);
					}
				}
			}
		}
	}
	if(state[0]==1)printf("Snuke\n");
	else if(state[0]==-1)printf("Sothe\n");
	else printf("Draw\n");
	return 0;
}