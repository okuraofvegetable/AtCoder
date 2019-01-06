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
int N;
ll a[20][20];
ll p[1<<16];
ll dp[1<<16];
ll rec(int S){
	if(S==0)return dp[0]=0ll;
	if(dp[S]!=-LLINF)return dp[S];
	ll ret = -LLINF;
	for(int i=S;i>0;i=(i-1)&S){
		ret = max(ret,rec(S^i)+p[i]);
	}
	return dp[S]=ret;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<(1<<N);i++){
		vector<int> vec;
		for(int j=0;j<N;j++){
			if((i>>j)&1)vec.pb(j);
		}
		int s = vec[0];
		int pre = i-(1<<s);
		ll add = 0ll;
		for(int j=1;j<vec.size();j++)add+=a[s][vec[j]];
		p[i] = p[pre]+add;
	}
	for(int i=0;i<(1<<N);i++)dp[i]=-LLINF;
	cout << rec((1<<N)-1) << endl;

	return 0;
}