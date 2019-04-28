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
int N;
int A[100100];
int l[100100];
int r[100100];
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	l[0]=A[0];
	r[N-1]=A[N-1];
	for(int i=1;i<N;i++){
		l[i] = __gcd(l[i-1],A[i]);
	}
	for(int i=N-2;i>=0;i--){
		r[i] = __gcd(r[i+1],A[i]);
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		if(i==0){
			ans = max(ans,r[i+1]);
		}else if(i==N-1){
			ans = max(ans,l[i-1]);
		}else{
			ans = max(ans,__gcd(l[i-1],r[i+1]));
		}
	}
	cout << ans << endl;
	return 0;
}