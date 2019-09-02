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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int N;
int M;
int A[1010][1010];
vector<int> g[1000100];
vector<int> topo;
int rev[1000100];
bool used[1000100];
int dp[1000100];
int encode(int a,int b){
	if(a>b)swap(a,b); 
	return N*a+b;
}
void dfs(int v){
	used[v] = true;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(used[u])continue;
		dfs(u);
	}
	topo.pb(v);
	return;
}
void tsort(){
	memset(used,false,sizeof(used));
	for(int i=0;i<M;i++){
		if(!used[i])dfs(i);
	}
	reverse(all(topo));
	memset(rev,-1,sizeof(rev));
	for(int i=0;i<topo.size();i++){
		rev[topo[i]] = i;
	}
	return;
}
bool DAGcheck(){
	for(int i=0;i<topo.size();i++){
		int a = topo[i];
		for(int j=0;j<g[a].size();j++){
			int b = g[a][j];
			if(rev[a]>rev[b])return false;
		}
	}
	return true;
}
int main(){
	cin >> N;
	M = N*N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N-1;j++){
			cin >> A[i][j];
			A[i][j]--;
			if(j>0){
				// cout << i << ',' << A[i][j-1] << " -> " << i << ',' << A[i][j] << endl;
				// cout << encode(i,A[i][j-1]) << ' ' << encode(i,A[i][j]) << endl;
				g[encode(i,A[i][j-1])].pb(encode(i,A[i][j]));
			}
		}
	}
	tsort();
	// dump(topo);
	if(!DAGcheck()){
		cout << -1 << endl;
		return 0;
	}
	int ans = 0;
	for(int i=0;i<topo.size();i++){
		int a = topo[i];
		for(int j=0;j<g[a].size();j++){
			int b = g[a][j];
			chmax(dp[b],dp[a]+1);
		}
		chmax(ans,dp[a]);
	}
	cout << ++ans << endl;
	return 0;
}
