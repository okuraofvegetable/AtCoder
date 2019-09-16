#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,int> T;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define emplace_back
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
template<class t,class u>
ostream& operator << (ostream& os,pair<t,u> p){
	return os << p.fi << ',' << p.sec;
}
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
ll A[200100];
bool check(ll K){
	vector<P> vec;
	vec.pb(P(0,A[0]));
	for(int i=1;i<N;i++){
		//dump(vec);
		if(A[i-1]<A[i]){
			vec.pb(P(0,A[i]-A[i-1]));
		}else{
			ll tmp = A[i-1]-A[i];
			while(tmp>0){
				P a = vec.back();
				vec.pop_back();
				if(tmp<a.sec){
					vec.pb(P(a.fi,a.sec-tmp));	
					tmp = 0;
				}else{
					tmp -= a.sec;
				}
			}
			P a = vec.back();
			vec.pop_back();
			if(a.fi==K-1){
				while(!vec.empty()){
					if(vec.back().fi!=K-1)break;
					a.sec += vec.back().sec;
					vec.pop_back();
				}
				if(vec.empty())return false;
				P b = vec.back();
				vec.pop_back();
				assert(b.fi<K-1);
				if(b.sec>1)vec.pb(P(b.fi,b.sec-1));
				vec.pb(P(b.fi+1,1));
				vec.pb(P(0,a.sec));
			}else{
				if(a.sec>1)vec.pb(P(a.fi,a.sec-1));
				vec.pb(P(a.fi+1,1));
			}
			/*ll sum = 0ll;
			for(int j=0;j<vec.size();j++){
				sum += vec[j].sec;
			}
			if(sum!=A[i]){
				cout << sum << ' ' << A[i] << endl;
			}*/
		}
	}
	return true;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	ll l = 0ll,r = 1000000000000000ll;
	while(r-l>1ll){
		ll mid = (l+r)/2ll;
		if(check(mid))r = mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}
