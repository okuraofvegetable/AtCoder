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
int N;
vector<P> v;
int main(){
	cin >> N;
	if(N%2==1){
		for(int i=1;i<=N;i++){
			for(int j=i+1;j<=N;j++){
				if(i+j!=N){
					v.pb(P(i,j));
				}
			}
		}
	}else{
		for(int i=1;i<=N;i++){
			for(int j=i+1;j<=N;j++){
				if(i+j!=N+1){
					v.pb(P(i,j));
				}
			}
		}
	}
	cout << v.size() << endl;
	for(int i=0;i<v.size();i++){
		cout << v[i].fi << ' ' << v[i].sec << endl;
	}
	return 0;
}