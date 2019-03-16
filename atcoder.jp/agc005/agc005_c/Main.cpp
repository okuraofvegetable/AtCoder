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
int N;
int a[105];
int cnt[105];
int r=0;
void fail(){
	cout << "Impossible" << endl;
	exit(0);
	return;
}
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
		r = max(r,a[i]);
	}
	if(r&1){
		for(int i=0;i<N;i++){
			a[i]=a[i]*2-r;
			if(a[i]<0)fail();
			cnt[a[i]]++;
		}
		if(cnt[1]!=2)fail();
		for(int i=3;i<=r;i+=2){
			if(cnt[i]<2)fail();
		}
		cout << "Possible" << endl;
	}else{
		r/=2;
		for(int i=0;i<N;i++){
			a[i]-=r;
			if(a[i]<0)fail();
			cnt[a[i]]++;
		}
		if(cnt[0]!=1)fail();
		for(int i=1;i<=r;i++){
			if(cnt[i]<2)fail();
		}
		cout << "Possible" << endl;
	}
	return 0;
}