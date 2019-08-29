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
int N;
int a[100100];
vi g[100100];
int rec(int v){
	vi ret;
	for(int i=0;i<g[v].size();i++){
		ret.pb(rec(g[v][i]));
	}
	if(ret.size()==0)return 0;
	sort(all(ret),greater<int>());
	for(int i=0;i<ret.size();i++){
		ret[i] += i+1;
	}
	int res = *max_element(all(ret));	
	// cout << v << ' ' << res << endl;
	return res;
}
int main(){
	cin >> N;
	for(int i=1;i<N;i++){
		cin >> a[i];
		a[i]--;
		g[a[i]].pb(i);
	}
	cout << rec(0) << endl;
	return 0;
}
