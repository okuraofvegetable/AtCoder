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
ll N,K;
ll R;
int a[100100];
deque<int> q;
int main(){
	cin >> N >> K >> R;
	if((N-K)*(N-K+1ll)/2ll<R){
		cout << "No Luck" << endl;
		return 0;
	}
	ll rem = R;
	for(ll i=N-K;i>=1;i--){
		if(rem>=i){
			a[N-K+1-i]=1;
			rem-=i;
		}
	}
	for(int i=N-K+1;i<=N;i++)q.push_back(i);
	for(int i=N-K;i>=1;i--){
		if(a[i]==1)q.push_back(i);
		else q.push_front(i);
	}
	for(int i=0;i<q.size();i++){
		printf("%d",q[i]);
		if(i+1<q.size())printf(" ");
		else printf("\n");
	}
	return 0;
}