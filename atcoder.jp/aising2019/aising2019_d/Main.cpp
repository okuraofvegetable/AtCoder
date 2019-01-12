#include<bits/stdc++.h>
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
int N,Q;
int A[100100];
int X[100100];
ll rui[100100];
ll U[100100];
int Count(int l,int r){ //[l,r]
	if(r<l)return 0;
	return upper_bound(A,A+N,r)-lower_bound(A,A+N,l);
}
int check(int k,int x){
	int tar = A[N-k];
	int b = abs(x-tar);
	int c = Count(x-b,min(x+b,tar));
	return c;
}
ll up(int i){
	if(i==0)return U[N-1];
	return U[N-1]-U[i-1];
}
int main(){
	cin >> N >> Q;
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<Q;i++)scanf("%d",&X[i]);
	rui[0]=A[0];
	rui[1]=A[1];
	for(int i=2;i<N;i++)rui[i]=rui[i-2]+A[i];
	U[0]=A[0];
	for(int i=1;i<N;i++)U[i]=U[i-1]+A[i];
	sort(A,A+N);
	for(int i=0;i<Q;i++){
		int l = 0 ,r = N+1;
		while(r-l>1){
			int mid = (l+r)/2;
			if(check(mid,X[i])>mid)l=mid;
			else r = mid;
		}
		//cout << "l : " << l << endl;
		ll ans = up(N-l);
		//cout << "up: " << up(N-l) << endl;
		if(check(l+1,X[i])>l){
			ans += A[N-l-1];
			if(N>=2*(l+1)+1)ans += rui[N-2*(l+1)-1];
		}else{
			if(N>=2*l+1)ans += rui[N-2*l-1];
		}
		printf("%lld\n",ans);
	}
	return 0;
}