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
int N;
ll a[300100];
ll b[300100];
ll c[300100];
int main(){
	scanf("%d",&N);
	for(int i=0;i<3*N;i++){
		scanf("%lld",&a[i]);
	}
	priority_queue<ll,vector<ll>,greater<ll> > q;
	ll sum = 0ll;
	for(int i=0;i<N;i++){
		q.push(a[i]);
		sum += a[i];
	}
	b[N-1]=sum;
	for(int i=N;i<3*N;i++){
		if(q.top()<a[i]){
			sum -= q.top();
			q.pop();
			sum += a[i];
			q.push(a[i]);
		}
		b[i]=sum;
	}
	priority_queue<ll> pq;
	sum = 0ll;
	for(int i=3*N-1;i>=2*N;i--){
		pq.push(a[i]);
		sum += a[i];
	}
	c[2*N]=sum;
	for(int i=2*N-1;i>=0;i--){
		if(pq.top()>a[i]){
			sum -= pq.top();
			pq.pop();
			sum += a[i];
			pq.push(a[i]);
		}
		c[i]=sum;
	}
	ll ans = -LLINF;
	for(int i=N-1;i<2*N;i++){
		ans = max(ans,b[i]-c[i+1]);
	}
	cout << ans << endl;
	return 0;
}