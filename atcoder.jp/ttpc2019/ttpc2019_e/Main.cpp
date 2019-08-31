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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int ans[1010][1010];
int N;
int main(){
	cin >> N;
	if(N%2==0){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl; 
	for(int i=0;i<N;i++){
		if(i%2==0){
			for(int j=1;j<=N;j++){
				ans[i][j-1] = i*N+j;
			}
		}else{
			for(int j=1;j<=N;j++){
				ans[i][N-j] = i*N+j;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << ans[(i+j)%N][j];
			if(j+1<N)cout << ' ';
		}
		cout << endl;
	}
	return 0;
}