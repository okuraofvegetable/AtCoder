#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
vector<int> g[100100];
int d[100100][3];
int N,M,S,T;
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int u,v;
		cin >> u >> v;
		u--;v--;
		g[u].pb(v);
	}
	cin >> S >> T;
	S--;T--;
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			d[i][j]=INF;
		}
	}
	d[S][0]=0;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,S*3));
	while(!q.empty()){
		P a = q.top();
		q.pop();
		int v = a.sec/3;
		int m = a.sec%3;
		int dis = a.fi;
		for(int i=0;i<g[v].size();i++){
			int u = g[v][i];
			if(d[u][(m+1)%3]>dis+1){
				d[u][(m+1)%3]=dis+1;
				q.push(P(d[u][(m+1)%3],u*3+(m+1)%3));
			}
		}
	}
	int ans = d[T][0];
	if(ans==INF)cout << -1 << endl;
	else cout << ans/3 << endl;
	return 0;
}