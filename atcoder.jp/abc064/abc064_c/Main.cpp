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
int b[13];
int main(){
	int N;
	cin >> N;
	vi a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
		b[a[i]/400]++;
	}
	int ans = 0;
	for(int i=0;i<8;i++){
		if(b[i]>0)ans++;
	}
	int k = 0;
	for(int i=8;i<13;i++){
		k += b[i];
	}
	cout << max(1,ans) << ' ' << ans+k << endl;	
	return 0;
}