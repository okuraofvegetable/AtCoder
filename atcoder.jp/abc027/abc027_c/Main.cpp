#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
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
ll N;
/*map<ll,int> m;
bool dfs(ll x){
	map<ll,int>::iterator it=m.find(x);
	if(it!=m.end()){
		if(it->sec==1)return true;
		else return false; 
	}
	if(x>N){
		return true;
	}
	bool flag;
	flag = true;
	flag &= dfs(2ll*x);
	flag &= dfs(2ll*x+1ll);
	return !flag;
}*/
int main(){
	cin >> N;
	if(N==1){
		cout << "Aoki" << endl;
		return 0;
	}
	ll a = 1ll;
	ll r = 4ll;
	while(1){
		if(N<=a+r){
			cout << "Takahashi" << endl;
			break;
		}else if(N<=a+r*2ll){
			cout << "Aoki" << endl;
			break;
		}else{
			a += 2ll*r;
			r*=4ll;
		}
	}
	return 0;
}