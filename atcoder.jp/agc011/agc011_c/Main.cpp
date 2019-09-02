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
int N,M;
vector<int> g[100100];
bool used[100100];
int col[100100];
bool flag;
int k;
void dfs(int v,int c){
	used[v] = true;
	k++;
	col[v] = c;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(used[u]){
			if(col[u]==col[v])flag = false;
		}else{
			dfs(u,1-c);
		}
	}
	return;
}
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(used,false,sizeof(used));
	ll ans = 0ll;
	ll X = 0ll, Y = 0ll ,Z = 0ll;
	for(int i=0;i<N;i++){
		if(!used[i]){
			k = 0;
			flag = true;	
			dfs(i,0);
			if(k==1){
				ans++;
				Z++;
			}else{
				if(!flag){
					ans++;
					Y++;
				}else{
					ans+=2;
					X++;
				}
			}
		}
	} 
	/*cout << ans << endl;
	cout << X << endl;
	cout << Y << endl;
	cout << Z << endl;*/
	ans += 2ll*X*(X-1ll);
	ans += Y*(Y-1ll);
	ans += 2ll*X*Y;
	ans += Z*(Z-1ll);
	ans += 2ll*Z*((ll)N-Z);
	cout << ans << endl;
	return 0;
}
