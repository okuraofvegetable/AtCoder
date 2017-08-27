#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
ll cnt[30];
int main(){
	string s;
	cin >> s;
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'a']++;
	}
	ll N = (ll)s.size();
	ll ans = N*(N-1)/2;
	for(int i=0;i<26;i++)ans -= cnt[i]*(cnt[i]-1)/2;
	cout << ++ans << endl;
	return 0;
}