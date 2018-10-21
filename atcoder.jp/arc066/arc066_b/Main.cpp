#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
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
ll MOD = 1000000007ll;
ll N;
map<ll,ll> m;
ll rec(ll n){
	if(n<0ll)return 0ll;
	if(n==0ll)return 1ll;
	map<ll,ll>::iterator it = m.find(n);
	if(it!=m.end())return it->sec;
	return m[n]=(rec(n/2-1)+rec(n/2-!(n&1))+rec(n/2))%MOD;
}
int main(){
	cin >> N;
	cout << rec(N) << endl;
	return 0;
}