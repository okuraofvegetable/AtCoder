#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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
int N,M;
ll A[100100];
P B[100100];
ll K[100100];
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++)cin >> A[i];
	ll sum = 0ll;
	ll rem = N;
	for(int i=0;i<M;i++){
		cin >> B[i].sec >> B[i].fi;
	}
	sort(A,A+N);
	sort(B,B+M);
	for(int i=M-1;i>=0;i--){
		for(int j=0;j<min(rem,B[i].sec);j++){
			K[rem-1-j]=B[i].fi;
		}
		rem -= min(rem,B[i].sec);
	}
	reverse(K,K+N);
	ll ans = 0ll;
	for(int i=0;i<N;i++){
		ans += max(A[i],K[i]);
	}
	cout << ans << endl;
	return 0;
}