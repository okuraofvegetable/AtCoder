#include <bits/stdc++.h>
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
#define LLINF 1000000000000000
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
vector<int> g[100100];
int col[100100];
bool used[100100];
int num[3];
bool dfs(int v,int c){
	col[v]=c;
	num[c+1]++;
	used[v]=true;
	bool flag = true;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(col[u]==c)flag = false;
		if(used[u])continue;
		if(!dfs(u,-c))flag = false;
	}
	return flag;
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int A,B;
		scanf("%d %d",&A,&B);
		A--;B--;
		g[A].pb(B);
		g[B].pb(A);
	}
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		num[0]=num[2]=0;
		if(!used[i]){
			if(dfs(i,1)){
				ans += (ll)num[0]*(ll)num[2];
			}else{
				ll s = num[0]+num[2];
				ans += s*(s-1ll)/2ll;
			}
		}
	}
	cout << ans - (ll)M << endl;
	return 0;
}