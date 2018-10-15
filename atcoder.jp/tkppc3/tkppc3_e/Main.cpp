#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 20000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int n;
int main(){
	cin >> n;
	double ans = 0.0;
	double g = 1.0;
	double res = 0.0;
	for(int i=0;i<n;i++){
		if(i>0)g *= (double)(n-i);
		g /= (double)n;
		res += g;
	}
	ans = res*(double)n/2.0*(double)(n+1);
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}