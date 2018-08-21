#include<bits/stdc++.h>
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
int N,Z,W;
int a[2010];
int dp[2010][2];
int rec(int k,int p){
	if(dp[k][p]!=-1)return dp[k][p];
	int res;
	if(p==0){
		res = 0;
		for(int i=k+1;i<N;i++){
			res = max(res,rec(i,!p));
		}
		if(k==0)res = max(res,abs(W-a[N-1]));
		else res = max(res,abs(a[k-1]-a[N-1]));
	}else{
		res = INF;
		for(int i=k+1;i<N;i++){
			res = min(res,rec(i,!p));
		}
		res = min(res,abs(a[k-1]-a[N-1]));
	}
	return dp[k][p]=res;
}
int main(){
	cin >> N >> Z >> W;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout << rec(0,0) << endl;
	return 0;
}