#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> T;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef multiset<int>::iterator msi;
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
int a[3];
int cnt[3];
int main(){
	for(int i=0;i<3;i++){
		cin >> a[i];
		cnt[a[i]%2]++;
	}
	int ans = 0;
	if(cnt[0]==0||cnt[1]==0){
		sort(a,a+3);
		ans += (a[2]-a[0])/2;
		ans += (a[2]-a[1])/2;
 	}else{
		ans++;
		if(cnt[0]==1){
			for(int i=0;i<3;i++){
				if(a[i]%2==1)a[i]++;
			}
		}else{
			for(int i=0;i<3;i++){
				if(a[i]%2==0)a[i]++;
			}
		}
		sort(a,a+3);
		ans += (a[2]-a[0])/2;
		ans += (a[2]-a[1])/2;
	}
	cout << ans << endl;
	return 0;
}