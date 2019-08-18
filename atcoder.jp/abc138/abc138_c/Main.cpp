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
double rui[55];
int N;
double v[55];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> v[i];
	}
	rui[0]=1.0;
	for(int i=0;i<N;i++){
		rui[i+1] = rui[i]*0.5;
	}
	sort(v,v+N);
	double ans = 0.0;
	for(int i=0;i<N;i++){
		ans += v[i]*rui[min(N-i,N-1)];
	}
	printf("%.12f\n",ans);
	return 0;
}
