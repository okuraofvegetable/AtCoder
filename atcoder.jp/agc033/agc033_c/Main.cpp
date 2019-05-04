#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
vector<int> g[200100];
int N;
P dfs(int v,int p){
	P res = P(0,v);
	for(int i=0;i<g[v].size();i++){
		if(g[v][i]==p)continue;
		P a = dfs(g[v][i],v);
		a.fi++;
		res = max(res,a);
	}
	return res;
}
int main(){
	cin >> N;
	for(int i=0;i<N-1;i++){
		int x,y;
		cin >> x >> y;
		x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	int v = 0;
	P a = dfs(0,-1);
	P b = dfs(a.sec,-1);
	if(b.fi%3==1)cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}