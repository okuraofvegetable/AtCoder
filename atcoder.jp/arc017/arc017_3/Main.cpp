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
#define LLINF 4000000000000000000LL
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
int N,X,M;
int w[40];
map<int,int> m,m2;
int main(){
	cin >> N >> X;
	for(int i=0;i<N;i++)cin >> w[i];
	M = (N+1)/2;
	for(int i=0;i<(1<<M);i++){
		int sum = 0;
		for(int j=0;j<M;j++){
			if((i>>j)&1){
				sum += w[j];
			}
		}
		m[sum]++;
	}
	for(int i=0;i<(1<<(N-M));i++){
		int sum = 0;
		for(int j=0;j<(N-M);j++){
			if((i>>j)&1){
				sum += w[M+j];
			}
		}
		m2[sum]++;
	}
	int ans = 0;
	map<int,int>::iterator it;
	for(it=m.begin();it!=m.end();it++){
		map<int,int>::iterator it2 = m2.find(X-(it->fi));
		ans += (it->sec)*(it2->sec);
	}
	cout << ans << endl;
	return 0;
}