#include<bits/stdc++.h>
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
string s;
int N;
int a[100100];
bool check(int x){
	char f = 'f';
	for(int i=0;i<N;i++){
		if(a[i]>=x)continue;
		if(f=='f')f=s[i];
		else{
			if(f!=s[i])return false;
		}
	}
	return true;
}
int main(){
	cin >> s;
	N = s.size();
	for(int i=0;i<N;i++)a[i]=max(i,N-1-i);
	int l = 1,r = N+1;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))l = mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}