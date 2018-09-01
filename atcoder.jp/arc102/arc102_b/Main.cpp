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
int L;
struct edge{
	int f,t,c;
	edge(){}
	edge(int f,int t,int c):f(f),t(t),c(c){}
};
vector<edge> ans;
int main(){
	cin >> L;
	int s = 0;
	while((1<<(s+1))<=L)s++;
	for(int i=1;i<=s;i++){
		ans.pb(edge(i,i+1,1<<(i-1)));
		ans.pb(edge(i,i+1,0));
	}
	for(int i=0;i<s;i++){
		if((L>>i)&1){
			ans.pb(edge(i+1,s+1,(L>>(i+1))<<(i+1)));
		}
	}
	cout << s+1 << ' ' << ans.size() << endl;
	for(int i=0;i<ans.size();i++){
		cout << ans[i].f << ' ' << ans[i].t << ' ' << ans[i].c << endl;
	}
	return 0;
}