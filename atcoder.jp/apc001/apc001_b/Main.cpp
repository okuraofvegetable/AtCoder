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
int N;
ll a[100100],b[100100];
void no(){
	cout << "No" << endl;
	exit(0);
}
void yes(){
	cout << "Yes" << endl;
	exit(0);
}
int main(){
	scanf("%d",&N);
	ll sum = 0ll;
	for(int i=0;i<N;i++){
		scanf("%lld",&a[i]);
		sum-=a[i];
	}
	for(int i=0;i<N;i++){
		scanf("%lld",&b[i]);
		sum+=b[i];
	}
	if(sum<0ll)no();
	ll rem = sum;
	for(int i=0;i<N;i++){
		if(b[i]<a[i])rem-=(a[i]-b[i]);
		else{
			if(b[i]%2ll!=a[i]%2ll){
				rem--;
				b[i]++;
			}
		}
	}
	if(rem%2ll==1ll)no();
	rem = sum;
	for(int i=0;i<N;i++){
		if(b[i]>a[i])rem-=(b[i]-a[i])/2ll;
	}
	if(rem<0ll)no();
	yes();
	return 0;
}