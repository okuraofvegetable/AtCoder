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
const ll MOD = 1000000007ll;
int N;
int D[55];
bool check(int x){
	int l = x, r = 24-x;
	for(int i=0;i<N;i++){
		if(r<l)return false;
		if(D[i]>=l){
			l = D[i]+x;
		}else{
			if(24-D[i]>r||24-D[i]<l)return false;
			r = 24-D[i]-x;
		}
	}
	return true;
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&D[i]);
		D[i] = min(D[i],24-D[i]);
 	}
 	sort(D,D+N);
	int l = 0, r = 13;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))l = mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}