#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
int N;
int a[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	int ans = -INF;
	for(int i=0;i<N;i++){
		int S=-INF,T=-INF;
		for(int j=0;j<N;j++){
			if(i==j)continue;
			int l = min(i,j);
			int r = max(i,j);
			int s = 0, t = 0;
			for(int i=0;i<=r-l;i++){
				if(i%2==0)s+=a[i+l];
				else t+=a[i+l];
			}
			if(T<t){
				S=s;
				T=t;
			}
		}
		chmax(ans,S);
	}
	cout << ans << endl;
	return 0;
}