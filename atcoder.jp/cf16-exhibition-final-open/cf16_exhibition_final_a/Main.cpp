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
const ll MOD = 1000000007ll;
int N;
int a[100100],b[100100];
int sa[100100],sb[100100];
struct event{
	int type;
	int sign;
	int pos;
	event(){}
	event(int t,int s,int x):type(t),sign(s),pos(x){}
	bool operator < (const event& a) const{
		return pos < a.pos;
	}
};
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&b[i]);
	}
	sort(a,a+N);
	sort(b,b+N);
	vector<event> es;
	for(int i=0;i<N;i++){
		if(a[i]<b[i]){
			sb[i] = 1 ;
		}else{
			sa[i] = 1;
		}
		es.pb(event(0,sa[i],a[i]));
		es.pb(event(1,sb[i],b[i]));
	}
	sort(es.begin(),es.end());
	ll A = 0ll, B = 0ll;
	ll ans = 1ll;
	for(int i=0;i<es.size();i++){
		event e = es[i];
		if(e.type==0){
			if(e.sign==0){
				A++;
			}else{
				ans = ans*B%MOD;
				B--;
			}
		}else{
			if(e.sign==0){
				B++;
			}else{
				ans = ans*A%MOD;
				A--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}