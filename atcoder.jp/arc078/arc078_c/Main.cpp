#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
ll p[15];
bool query(ll x){
	cout << "? " << x << endl;
	char c;
	cin >> c;
	return c=='Y';
}
bool query(ll x,int d,ll y){
	if(x!=0ll)cout << "? " << x << d << y << endl;
	else if(d!=0ll)cout << "? " << d << y << endl;
	else cout << "? " << y << endl;
	char c;
	cin >> c;
	return c=='Y';
}
void find(ll x){
	cout << "! " << x << endl;
	exit(1);
}
int f(int dig,int L,ll offset){
	int l = (dig==0)?0:-1, r = 9;
	while(r-l>1){
		int mid = (l+r)/2;
		if(query(offset,mid,p[L-dig]-1ll))r=mid;
		else l = mid;
	}
	return r;
}
int main(){
	p[0]=1ll;
	for(int i=1;i<=10;i++)p[i]=p[i-1]*10ll;
	if(query(p[9])){
		int k = 1;
		while(!query(p[k]-1ll))k++;
		find(p[k-1]);
	}
	int l = 1, r = 10;
	while(r-l>1){
		int mid = (l+r)/2;
		if(query(p[mid-1]))l=mid;
		else r = mid;
	}
	ll os = 0ll;
	for(int i=0;i<l;i++){
		int d = f(i,l,os);
		//cout << "digit " << d << endl;
		os = os*10ll+(ll)d;
	}
	find(os);
	return 0;
}