#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
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
int main(){
	ll Q,H,S,D;
	cin >> Q >> H >> S >> D;
	ll N;
	cin >> N;
	H = min(Q*2,H);
	S = min(S,H*2);
	D = min(D,S*2);
	N*=4;
	ll cost=(N/8)*D+(N%8)/4*S+(N%4)/2*H+(N%2)*Q;
	cout << cost << endl; 
	return 0;
}