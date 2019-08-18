#include <bits/stdc++.h>
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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
void dump(int* ptr,int length){
	for(int i=0;i<length;i++){
		cout << *(ptr+i);
		if(i+1<length)cout << ' ';
		else cout << endl;
	}
}
int N;
int a[55],b[55];
struct edge{
	int to,mod;
	edge(){}
	edge(int to,int mod):to(to),mod(mod){}
};
vector<edge> g[55];
bool s[55];
bool w[55];
bool used[55];
void dfs(int v){
	// cout << v << ' ';
	used[v] = true;
	for(int i=0;i<g[v].size();i++){
		edge e = g[v][i];
		if(s[e.mod]&&!used[e.to])dfs(e.to);
	}
}
bool check(){
	for(int i=0;i<N;i++){
		memset(used,false,sizeof(used));
		dfs(a[i]);
		// cout << endl;
		// cout << b[i] << ' ' << used[b[i]] << endl;
		if(!used[b[i]])return false;
	}
	return true;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	for(int i=0;i<N;i++){
		cin >> b[i];
	}
	for(int i=1;i<=50;i++){
		for(int j=i;j<=50;j++){
			// cout << j << " mod: " << i << " to: " << j%i << endl;
			g[j].pb(edge(j%i,i));
		}
	}
	for(int i=50;i>0;i--){
		for(int j=50;j>0;j--){
			s[j] = w[j];
		}
		// for(int j=1;j<=50;j++){
		// 	cout << w[j] << ' ';
		// }
		// cout << endl;
		for(int j=1;j<i;j++)s[j] = true;
		if(!check())w[i]=true;
	}
	for(int i=1;i<=50;i++){
		s[i] = w[i];
	}
	if(!check()){
		cout << -1 << endl;
	}else{
		ll ans = 0ll;
		for(int i=1;i<=50;i++){
			if(w[i])ans += (1ll<<i);
		}
		cout << ans << endl;
	}
	return 0;
}
