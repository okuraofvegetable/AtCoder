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
	if(K>(N-1)*(N-2)/2){
		cout << -1 << endl;
		return 0;
	}
	int m = (N-1)*(N-2)/2-K;
	cout << N-1+m << endl;
	int cnt = 0;
	for(int i=1;i<=N-1;i++)cout << i << ' ' << N << endl;
	for(int i=1;i<=N-1;i++){
		for(int j=i+1;j<=N-1;j++){
			if(cnt>=m)continue;
			cnt++;
			cout << i << ' ' << j << endl;
		}
	}
	return 0;
}