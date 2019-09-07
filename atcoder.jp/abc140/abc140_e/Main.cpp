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
int N;
int p[100100];
int rev[100100];
ll ans = 0ll;
vector<P> vec;
set<int> s;
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> p[i];
		rev[p[i]] = i;
		vec.pb(P(p[i],i));
	}
	sort(all(vec));
	for(int i=N-1;i>0;i--){
		s.insert(vec[i].sec);
		auto it = s.lower_bound(rev[i]);
		ll R,L;
		if(it==s.end()){
			R = N-rev[i];
			it--;	
			L = *it;
			if(it==s.begin())L++;
			else{
				it--;
				L = L-(*it);
			}
			ans += (ll)i*(R*L);
		}else if(it==s.begin()){
			L = rev[i]+1;
			auto nxt = it;
			nxt++;
			if(nxt==s.end()){
				R = N-(*it);
			}else{
				R = (*nxt)-(*it);
			}
			ans += (ll)i*(R*L);
		}else{
			auto nxt = it;
			nxt++;
			auto prev = it;
			prev--;
			L = rev[i]-(*prev);
			if(nxt==s.end()){
				R = N-(*it);
			}else{
				R = (*nxt)-(*it);
			}
			ans += (ll)i*(R*L);

			R = (*it)-rev[i];
			L = *prev;
			if(prev==s.begin())L++;
			else{
				auto pp = prev;
				pp--;
				L = L-(*pp);
			}
			ans += (ll)i*(R*L);
		}
	}
	cout << ans << endl;
	return 0;
}
