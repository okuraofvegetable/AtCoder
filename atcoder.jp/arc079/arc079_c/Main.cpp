#include <bits/stdc++.h>
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
ll a[55];
ll ans = 0ll;
priority_queue<ll> p,q;
void solve(){
	while(q.top()>=N){
		ans++;
		p.push(q.top()-N);
		q.pop();
		while(!q.empty()){
			p.push(q.top()+1);
			q.pop();
		}
		swap(p,q);
	}
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> a[i];
	for(int i=0;i<N;i++)q.push(a[i]);
	while(1){
		ll L = q.top();
		vector<ll> v;
		ll cnt = 0ll;
		while(!q.empty()&&L-q.top()<=N+1){
			v.pb(q.top());
			q.pop();
			cnt++;
		}
		if(!q.empty()){
			ll op = (L-q.top())/(N+1ll);
			if(q.top()+op*cnt<N){
				for(int i=0;i<v.size();i++)q.push(v[i]);
				solve();
				break;
			}
			ans += op*cnt;
			while(!q.empty()){
				p.push(q.top()+op*cnt);
				q.pop();
			}
			for(int i=0;i<v.size();i++){
				p.push(v[i]-(N+1ll-cnt)*op);
			}
			swap(p,q);
		}else{
			if(L>N*N){
				ans += (L-N*N)*N;
				for(int i=0;i<v.size();i++)q.push(v[i]-(L-N*N));
			}else{
				for(int i=0;i<v.size();i++)q.push(v[i]);
				solve();
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}