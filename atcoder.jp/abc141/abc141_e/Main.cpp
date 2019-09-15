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
#define dmp(x) cerr << __LINE__ << " " << #x << " " << x << endl;
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
void fastio(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
}
typedef pair<string,int> Q;
int N;
string s;
int rk[100100];
int lcp[100100];
int main(){
	cin >> N;
	cin >> s;
	vector<Q> sa;
	for(int i=0;i<N;i++){
		sa.pb(Q(s.substr(i),i));
	}
	sort(all(sa));
	/*for(int i=0;i<N;i++){
		cout << sa[i].fi << ' ' << sa[i].sec << endl;
	}*/
	for(int i=0;i<N;i++){
		rk[sa[i].sec]=i;
	}
	for(int i=0,h=0;i<N;i++){
		if(rk[i]+1<N){
			for(int j=sa[rk[i]+1].sec;max(i,j)+h<N&&s[i+h]==s[j+h];++h);
			lcp[rk[i]+1] = h;
			if(h>0)--h;
		}
	}
	// for(int i=0;i<N;i++){
  //		cout << lcp[i] << endl;
	//}
	int ans = 0;
	for(int i=0;i<N;i++){
		int mi = 10000000;
		for(int j=i+1;j<N;j++){
			int S = sa[i].sec;
			int T = sa[j].sec;
			mi = min(mi,lcp[j]);
			// cout << mi << endl;
			ans = max(ans,min(abs(T-S),mi));
		}
	}
	cout << ans << endl;
	return 0;
}
