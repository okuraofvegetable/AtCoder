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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int H,W;
string s[10];
int a[10],b[10];
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++){
		cin >> s[i];
	}
	for(int i=0;i<H;i++){
		a[i] = 100;
		b[i] = -1;
		for(int j=0;j<W;j++){
			if(b[i]!=-1&&b[i]+1<j&&s[i][j]=='#'){
				cout << "Impossible" << endl;
				return 0;
			}
			if(s[i][j] == '#'){
				a[i] = min(j,a[i]);
				b[i] = max(j,b[i]);
			}
		}
	}
	for(int i=1;i<H;i++){
		if(a[i]!=b[i-1]){
				cout << "Impossible" << endl;
				return 0;
		}
	}
	cout << "Possible" << endl;	
	return 0;
}
