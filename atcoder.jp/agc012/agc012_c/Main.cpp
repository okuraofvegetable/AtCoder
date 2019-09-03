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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
template<class T>
void input(vector<T>& vec,int n){
	vec.resize(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
}
ll N;
vector<int> ans;
int main(){
	cin >> N;
	int n = 0;
	while((1ll<<(n+1))-1ll<=N)n++;
	N -= (1ll<<n)-1ll;
	bitset<40> bs(N);
	int c = bs.count();
	int d = 0;
	for(int i=1;i<=n;i++){
		if(bs[i-1]==1){
			ans.pb(n+c-d);
			d++;
		}
		ans.pb(i);
	}
	assert(d==c);
	for(int i=1;i<=n+c;i++){
		ans.pb(i);
	}
	cout << ans.size() << endl;
	dump(ans);
	return 0;
}
