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
string S[2];
int Q;
int a[2][100100];
int b[2][100100];
int main(){
	cin >> S[0];
	cin >> S[1];
	for(int i=0;i<2;i++){
		for(int j=0;j<S[i].size();j++){
			if(S[i][j]=='A')a[i][j+1]=1;
			else b[i][j+1]=1;
		}
		for(int j=0;j<S[i].size();j++){
			a[i][j+1]+=a[i][j];
			b[i][j+1]+=b[i][j];
		}
	}
	cin >> Q;
	for(int i=0;i<Q;i++){
		int A,B,C,D;
		cin >> A >> B >> C >> D;
		int k = a[0][B]-a[0][A-1]+2*(b[0][B]-b[0][A-1]);
		int l = a[1][D]-a[1][C-1]+2*(b[1][D]-b[1][C-1]);
		if(k%3==l%3)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}