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
int N;
ll a[405];
ll dp[405][405];
ll rui[405];
ll sum(int l,int r){
	if(l==0)return rui[r];
	else return rui[r]-rui[l-1];
}
ll rec(int l,int r){
	if(l==r)return 0;
	if(dp[l][r]!=-1ll)return dp[l][r];
	ll ret = LLINF;
	for(int i=l;i<r;i++){
		ret = min(ret,rec(l,i)+rec(i+1,r)+sum(l,r));
	}
	return dp[l][r]=ret;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	rui[0]=a[0];
	for(int i=1;i<N;i++)rui[i]=rui[i-1]+a[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)dp[i][j]=-1ll;
	}
	cout << rec(0,N-1) << endl;
	return 0;
}