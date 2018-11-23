#include <bits/stdc++.h>
#include <unordered_map>
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
string S;
string s,t;
map<pair<string,string>,int> m;
int main(){
	cin >> N;
	cin >> S;
	for(int i=0;i<N;i++){
		s+=S[i];
		t+=S[i+N];
	}
	reverse(all(t));
	for(int i=0;i<(1<<N);i++){
		string a,b;
		for(int j=0;j<N;j++){
			if((i>>j)&1)a+=t[j];
			else b+=t[j];
		}
		m[mp(a,b)]++;
	}
	ll ans = 0ll;
	for(int i=0;i<(1<<N);i++){
		string a,b;
		for(int j=0;j<N;j++){
			if((i>>j)&1)a+=s[j];
			else b+=s[j];
		}
		ans += m[mp(a,b)];
	}
	cout << ans << endl;
	return 0;
}