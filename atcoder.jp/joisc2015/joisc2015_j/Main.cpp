#include <bits/stdc++.h>
#include "navigation_lib.h"
using namespace std;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
vector<int> g[100100];
int f[100100];
void flag(int I,int V){
	f[I]=V;
	Flag(I,V);
}
void dfs(int v,int p){
	if(p==-1)flag(v,0);
	else{
		if(p>v)flag(v,f[p]);
		else flag(v,f[p]^1);
	}
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]!=p)dfs(g[v][i],v);
	}
}
void Anna(int K,int N,int T,int A[],int B[]){
	for(int i=0;i<N-1;i++){
		g[A[i]].pb(B[i]);
		g[B[i]].pb(A[i]);
	}
	dfs(T,-1);
}
void Bruno(int K,int S,int F,int L,int P[],int Q[]){
	int ans = -1;
	for(int i=0;i<L;i++){
		if(P[i]>S&&Q[i]==F)ans = P[i];
		if(P[i]<S&&Q[i]!=F)ans = P[i];
	}
	if(ans==-1)Answer(S);
	else Answer(ans);
}