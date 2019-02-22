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
string s;
int N;
int main(){
	cin >> s;
	N = s.size();
	if(s[N-1]=='1'){
		cout << -1 << endl;
		return 0;
	}
	if(s[0]=='0'){
		cout << -1 << endl;
		return 0;
	}
	for(int i=0;i<N-1;i++){
		if(s[i]!=s[N-2-i]){
			cout << -1 << endl;
			return 0;
		}
	}
	int l = N;
	for(int i=N-1;i>=1;i--){
		cout << i << ' ' << l << endl;
		if(s[i-1]=='1')l=i;
	}
	return 0;
}