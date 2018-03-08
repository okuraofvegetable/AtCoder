#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
int N,A,B;
ll sum[55];
ll v[55];
ll a[55],b[55];
ll C[55][55];
ll nCr(int n,int r){
	if(C[n][r]!=-1ll)return C[n][r];
	if(r==0||n==r)return C[n][r]=1ll;
	return C[n][r]=nCr(n-1,r-1)+nCr(n-1,r);
}
int main(){
	scanf("%d %d %d",&N,&A,&B);
	for(int i=0;i<N;i++)scanf("%lld",&v[i]);
	sort(v,v+N);
	a[N-1]=1;
	for(int i=N-2;i>=0;i--){
		if(v[i]==v[i+1])a[i]=a[i+1]+1;
		else a[i]=1;
	}
	b[0]=a[0];
	for(int i=1;i<N;i++){
		if(v[i]==v[i-1])b[i]=b[i-1];
		else b[i]=a[i];
	}
	/*for(int i=0;i<N;i++)cout << a[i] << ' ';
	cout << endl;
	for(int i=0;i<N;i++)cout << b[i] << ' ';
	cout << endl;*/
	sum[0]=0;
	for(int i=1;i<=N;i++){
		sum[i]=sum[i-1]+v[N-i];
	}
	for(int i=0;i<=50;i++){
		for(int j=0;j<=50;j++){
			C[i][j]=-1ll;
		}
	}
	printf("%.12f\n",(double)sum[A]/(double)A);
	if(a[N-A]==A){
		ll ans = 0ll;
		for(int i=A;i<=B;i++){
			if(b[N-A]<i)break;
			ans+=nCr(b[N-A],i);
		}
		cout << ans << endl;
	}else{
		cout << nCr(b[N-A],a[N-A]) << endl;
	}
	return 0;
}