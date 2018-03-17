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
int a[200100],b[200100];
int A[200100],B[200100];
int solve(int k){
	int K = (1<<k);
	for(int i=0;i<N;i++)B[i]=b[i]%K;
	sort(B,B+N);
	int res = 0;
	for(int i=0;i<N;i++){
		if(N%2==1){
			if((a[i]>>k)&1)res^=1;
			if((b[i]>>k)&1)res^=1;
		}
		int idx = lower_bound(B,B+N,K-(a[i]%K))-B;
		res ^= ((N-idx)&1);
	}
	return res;
}
int main(){
	scanf("%d",&N);
	int ans = 0;
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	for(int i=0;i<30;i++){
		ans += solve(i)<<i;
	}
	printf("%d\n",ans);
	return 0;
}