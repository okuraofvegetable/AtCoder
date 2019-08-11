#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
int main(){
	int N;
	cin >> N;
	vi A(N+1);
	vi B(N);
	for(int i=0;i<N+1;i++){
		cin >> A[i];
	}
	for(int i=0;i<N;i++){
		cin >> B[i];
	}
	int pre = 0;
	ll ans = 0;
	for(int i=0;i<N+1;i++){
		ans += min(pre,A[i]);
		A[i] -= min(pre,A[i]);
		ans += min(B[i],A[i]);
		pre = B[i]-min(B[i],A[i]);
	}
	cout << ans << endl;	
	return 0;
}
