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
#define MAX_N 4010
struct BIT{
	ll bit[MAX_N+1];
	void init(){
		memset(bit,0,sizeof(bit));
	}
	void add(int i,ll x){
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		if(i<0)return 0ll;
		i++;
		ll res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
}bit;
int N;
char c[4010];
int  a[4010];
int B[2010],W[2010];
int L[4010];
int dp[2010][2010];
int main(){
	scanf("%d",&N);
	for(int i=0;i<2*N;i++){
		scanf(" %c %d",&c[i],&a[i]);
		if(c[i]=='B')B[a[i]]=i;
		else W[a[i]]=i;
	}
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(i+j>0)dp[i][j]=INF;
		}
	}	
	for(int i=0;i<=N;i++){
		bit.init();
		for(int j=i+1;j<=N;j++)bit.add(B[j],1);
		for(int j=1;j<=N;j++)bit.add(W[j],1);
		for(int j=0;j<=N;j++){
			if(j>0)bit.add(W[j],-1);
			chmin(dp[i+1][j],dp[i][j]+(int)bit.sum(B[i+1]-1));
			chmin(dp[i][j+1],dp[i][j]+(int)bit.sum(W[j+1]-1));
			//cout << dp[i][j] << ' ';
		}
		//cout << endl;
	}
	cout << dp[N][N] << endl;
	return 0;
}