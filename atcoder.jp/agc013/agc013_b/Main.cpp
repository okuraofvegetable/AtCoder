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
int A[100100],B[100100];
int deg[100100];
vector<int> g[100100];
bool used[100100];
void add_edge(int a,int b){
	g[a].pb(b);
	g[b].pb(a);
	deg[a]++;
	deg[b]++;
}
void dfs(int v,vector<int> &ans){
	used[v] = true;
	ans.pb(v);
 	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(used[u])continue;
		dfs(u,ans);
		break;
	}
}
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> A[i] >> B[i];
		A[i]--;B[i]--;
		add_edge(A[i],B[i]);
	}
	for(int i=0;i<N;i++){
		if(deg[i]==1){
			vector<int> ans;
			dfs(i,ans);
			cout << ans.size() << endl;
			for(int i=0;i<ans.size();i++){
				cout << ans[i]+1;
				if(i<ans.size()-1)cout << ' ';
				else cout << endl;
			}
			return 0;
		}
	}
	used[0]=true;
	vector<int> A,B;
	int a = 0;
	int b = -1;
	dfs(a,A);
	for(int i=0;i<g[a].size();i++){
		if(!used[g[a][i]]){
			b = g[a][i];
			break;
		}
	}
	if(b!=-1){
		dfs(b,B);
		reverse(all(A));
		cout << A.size()+B.size() << endl;
		for(int i=0;i<A.size();i++){
			cout << A[i]+1 << ' ';
		}
		for(int i=0;i<B.size();i++){
			cout << B[i]+1;
			if(i<B.size()-1)cout << ' ';
			else cout << endl;
		}
		return 0;
	}else{
		cout << A.size() << endl;
		for(int i=0;i<A.size();i++){
			cout << A[i]+1 << ' ';
		}
	}
	return 0;
}