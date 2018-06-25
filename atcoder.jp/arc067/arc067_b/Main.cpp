#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007ll
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
ll A,B;
int X[100100];
ll dp[100100];
int main(){
	scanf("%d %lld %lld",&N,&A,&B);
	for(int i=0;i<N;i++){
		scanf("%d",&X[i]);
	}
	dp[0]=0;
	for(int i=1;i<N;i++)dp[i]=LLINF;
	for(int i=1;i<N;i++){
		dp[i]=min(dp[i-1]+A*(ll)(X[i]-X[i-1]),dp[i-1]+B);
	}
	cout << dp[N-1] << endl;
	return 0;
}