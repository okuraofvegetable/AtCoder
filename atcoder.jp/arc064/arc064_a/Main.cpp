#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
typedef long long ll;
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
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,x;
int a[100100];
int b[100100];
int main(){
	cin >> N >> x;
	for(int i=0;i<N;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	for(int i=0;i<N-1;i++)b[i]+=b[i+1];
	ll ans = 0ll;
	for(int i=0;i<N-1;i++){
		if(b[i]>x){
			int c = min(a[i+1],b[i]-x);
			ans += c;
			b[i]-=c;
			b[i+1]-=c;
		}	
	}
	for(int i=0;i<N-1;i++)if(b[i]>x)ans += b[i]-x;
	cout << ans << endl;
	return 0;
}