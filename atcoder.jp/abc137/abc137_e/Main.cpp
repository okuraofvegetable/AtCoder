#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define LLINF 100000000000000
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
int N,M,P;
int A[5020],B[5010];
ll C[5010];
ll d[5010];
int main(){
	cin >> N >> M >> P;
	for(int i=0;i<M;i++){
		cin >> A[i] >> B[i] >> C[i];
		C[i] -= P;
	}
	for(int i=2;i<=N;i++){
		d[i] = -LLINF;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int a = A[j];
			int b = B[j];
			ll c = C[j];
			if(d[b]<d[a]+c){
				d[b] = d[a]+c;
			}
		}
	}
	ll prev = d[N];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int a = A[j];
			int b = B[j];
			ll c = C[j];
			if(d[b]<d[a]+c){
				// cout << a << ' ' << b << ' ' << c << endl;
				d[b] = d[a]+c;
			}
		}
	}
	if(d[N]!=prev)cout << -1 << endl;
	else cout << max(0ll,d[N]) << endl;
	return 0;
}
