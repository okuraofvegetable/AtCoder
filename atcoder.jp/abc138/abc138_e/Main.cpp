#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
string s,t;
int latest[30];
int nxt[100100][30];
int fs[30];
P check(int l){
	int id = l+1;
	int pos = fs[t[l]-'a'];
	if(pos==-1)return P(-1,-1);
  // cout << pos << ' ' << id << endl;
	while(id<t.size()&&pos!=-1){
		pos = nxt[pos][t[id]-'a'];
		if(pos!=-1)id++;
		// cout << pos << ' ' << id << endl;
	}
	// cout << endl;
	return P(pos,id);
}
int main(){
	cin >> s >> t;
	memset(latest,-1,sizeof(latest));
	for(int i=s.size()-1;i>=0;i--){
		for(int j=0;j<26;j++){
			nxt[i][j] = latest[j];
		}
		latest[s[i]-'a']=i;
	}
	for(int i=0;i<26;i++){
		fs[i] = latest[i];
	}
	int now = 0;
	ll ans = 0ll;
	ll prev = 0ll;
	while(now<t.size()){
		P res = check(now);
		if(res.sec<0){
			cout << -1 << endl;
			return 0;
		}
		// cout << res.fi << ' ' << res.sec << endl;
		ans += s.size();
		prev = res.fi+1;
		now = res.sec;
	}
	ans -= s.size();
	ans += prev;
	cout << ans << endl;
	return 0;
}
