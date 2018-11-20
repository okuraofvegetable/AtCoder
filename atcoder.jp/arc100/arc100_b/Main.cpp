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
int N;
ll A[200100];
ll B[200100];
int sp(int l,int r){ //[l,r]
	ll b = (B[r+1]-B[l])/2ll+B[l];
	int k = lower_bound(B+l+1,B+r+1,b)-B;
	return k-2;
}
ll sum(int l,int r){
	return B[r+1]-B[l];
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lld",&A[i]);
		B[i+1]=A[i];
	}
	for(int i=0;i<=N;i++){
		B[i+1]+=B[i];
		//printf("%lld ",B[i]);
	}
	//printf("\n");
	ll ans = LLINF;
	for(int i=1;i<N-1;i++){ //[0..i][i+1..N-1]
		int kl = sp(0,i);
		int kr = sp(i+1,N-1);
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				int L = kl+j;
				int R = kr+k;
				//printf("[%d,%d] [%d,%d] [%d,%d] [%d,%d]\n",0,L,L+1,i,i+1,R,R+1,N-1);
				vector<ll> v;
				v.pb(sum(0,L));
				v.pb(sum(L+1,i));
				v.pb(sum(i+1,R));
				v.pb(sum(R+1,N-1));
				sort(all(v));
				ans = min(ans,v[3]-v[0]);
			}
		}
		//printf("\n");
	}
	cout << ans << endl;
	return 0;
}