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
string s,t;
int N;
int main(){
	cin >> N;
	cin >> s;
	cin >> t;
	for(int i=0;i<N;i++){
		bool flag = true;
		for(int j=0;j<N-i;j++){
			if(s[i+j]!=t[j]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << 2*N-(N-i) << endl;
			return 0;
		}
	}
	cout << 2*N << endl;
	return 0;
}
