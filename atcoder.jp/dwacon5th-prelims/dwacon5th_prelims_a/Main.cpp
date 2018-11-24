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
int a[105];
int main(){
	cin >> N;
	double ave = 0.0;
	for(int i=0;i<N;i++){
		cin >> a[i];
		ave += a[i];
	}
	ave /= (double)N;
	int ans = 0;
	double diff = 100000.0;
	for(int i=0;i<N;i++){
		if(diff-eps>abs(ave-(double)a[i])){
			ans = i;
			diff = abs(ave-(double)a[i]);
		}
	}
	cout << ans << endl;
	return 0;
}