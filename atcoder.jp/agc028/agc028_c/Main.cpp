#include <bits/stdc++.h>
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
int A[100100],B[100100];
int N;
vector<P> v;
bool used[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i] >> B[i];
		v.pb(P(A[i],i));
		v.pb(P(B[i],i));
	}
	ll ans = LLINF;
	chmin(ans,accumulate(A,A+N,0ll));
	chmin(ans,accumulate(B,B+N,0ll));
	sort(all(v));
	bool flag = false;
	for(int i=0;i<N;i++){
		if(used[v[i].sec]){
			flag = true;
			break;
		}
		used[v[i].sec]=true;
	}
	ll ret = 0ll;
	for(int i=0;i<N;i++)ret += v[i].fi;
	if(flag)chmin(ans,ret);
	else{
		for(int i=0;i<N;i++){
			chmin(ans,ret+max(A[i],B[i])-((v[N-1].sec==i)?v[N-2].fi:v[N-1].fi));
		}
	}
	cout << ans << endl;
	return 0;
}