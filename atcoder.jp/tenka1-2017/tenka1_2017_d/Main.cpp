#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef pair<ll,P> T;
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
int N,K;
int A[100100];
int B[100100];
const int MAX = 30;
ll sum(int k){
	ll s = 0ll;
	for(int i=0;i<N;i++){
		if((k|A[i])==k)s+=B[i];
	}
	return s;
}
int main(){
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d %d",&A[i],&B[i]);
	}
	ll ans = sum(K);
	for(int i=0;i<MAX;i++){
		int k = K;
		if((k>>i)&1){
			k>>=i;
			k^=1;
			k<<=i;
			k^=((1<<i)-1);
			ans = max(ans,sum(k));
		}
	}
	cout << ans << endl;
	return 0;
}