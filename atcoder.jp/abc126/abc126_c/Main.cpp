#include<bits/stdc++.h>
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
int N,K;
int main(){
	cin >> N >> K;
	double ans = 0.0;
	for(int i=1;i<=N;i++){
		int k = 0;
		int cur = i;
		while(cur<K){
			cur *= 2;
			k++;
		}
		double res = 1.0/(double)N;
		for(int j=0;j<k;j++)res *= 0.5;
		ans += res;
	}
	printf("%.12f\n",ans);
	return 0;
}