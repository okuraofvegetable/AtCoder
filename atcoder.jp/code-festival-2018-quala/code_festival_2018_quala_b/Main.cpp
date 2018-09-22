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
int N,M,A,B;
int L[105];
int R[105];
int c[105];
int main(){
	cin >> N >> M >> A >> B;
	for(int i=0;i<M;i++){
		cin >> L[i] >> R[i];
		L[i]--;
		R[i]--;
		for(int j=L[i];j<=R[i];j++){
			c[j]=1;
		}
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(c[i]==0)ans+=B;
		else ans+=A;
	}
	cout << ans << endl;
	return 0;
}