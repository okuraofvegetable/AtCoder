#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
ll dp[3010][3010][2];
int N;
int a[3010];
ll rec(int l,int r,int t){
	if(r<l)return 0ll;
	if(dp[l][r][t]!=-LLINF)return dp[l][r][t];
	if(t==0){
		return dp[l][r][t]=max(rec(l+1,r,!t)+a[l],rec(l,r-1,!t)+a[r]);
	}else{
		return dp[l][r][t]=min(rec(l+1,r,!t)-a[l],rec(l,r-1,!t)-a[r]);	
	}
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<2;k++){
				dp[i][j][k]=-LLINF;
			}
		}
	}
	cout << rec(0,N-1,0) << endl;
	return 0;
}