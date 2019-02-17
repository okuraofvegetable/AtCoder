#include <bits/stdc++.h>
using namespace std;
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
int e[705][705];
vector<int> g[705];
int col[705];
int cnt[3];
int used[705];
int dp[705][705];
bool binary_graph(int v,int c){
	col[v]=c;
	cnt[c+1]++;
	used[v]=true;
	bool ret = true;
	for(int i=0;i<g[v].size();i++){
		int u = g[v][i];
		if(used[u]){
			if(col[u]==c){
				ret=false;
			}
		}else{
			if(!binary_graph(u,-c))ret=false;
		}
	}
	return ret;
}
int N,M;
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		e[i][i]=1;
	}
	for(int i=0;i<M;i++){
		int A,B;
		cin >> A >> B;
		A--;B--;
		e[A][B]=e[B][A]=1;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(e[i][j]==0){
				g[i].pb(j);
			}
		}
	}
	bool res = true;
	vector<int> vec;
	for(int i=0;i<N;i++){
		if(!used[i]){
			cnt[0]=cnt[2]=0;
			res &= binary_graph(i,1);
			//cout << res << endl;
			//cout << cnt[0] << ' ' << cnt[2] << endl;
			if(res)vec.pb(abs(cnt[0]-cnt[2]));
		}
	}
	if(!res){
		cout << -1 << endl;
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<=700;j++){
			if(dp[i][j]==0)continue;
			dp[i+1][abs(j-vec[i])]=1;
			dp[i+1][j+vec[i]]=1;
		}
	}
	int K = -1;
	for(int i=0;i<=700;i++){
		if(dp[vec.size()][i]==1){
			K=i;
			break;
		}
	}
	//cout << K << endl;
	int C = (N+K)/2,D = (N-K)/2;
	//cout << C << ' ' << D << endl;
	cout << C*(C-1)/2+D*(D-1)/2 << endl;
	return 0;
}