#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
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
int a[100100];
bool used[100100];
priority_queue<int,vector<int>,greater<int> > p,q;
int K=0;
void dfs(int v){
	used[v]=true;
	p.push(a[v]);
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(!used[u])dfs(u);
	}
}
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++)cin >> a[i];
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	ll ans = 0;
	for(int i=0;i<N;i++){
		if(!used[i]){
			K++;
			dfs(i);
			ans += p.top();
			p.pop();
			while(!p.empty()){
				q.push(p.top());
				p.pop();
			}
		}
	}
	if(K==1){
		printf("0\n");
		return 0;
	}
	if(N-2*(K-1)<0){
		printf("Impossible\n");
		return 0;
	}
	for(int i=0;i<K-2;i++){
		ans += q.top();
		q.pop();
	}
	cout << ans << endl;
	return 0;
}