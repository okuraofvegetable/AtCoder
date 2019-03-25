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
int H,W;
string s[505];
string a[505],b[505];
int main(){
	cin >> H >> W;
	for(int i=0;i<H;i++){
		cin >> s[i];
		a[i]=b[i]=s[i];
	}
	for(int i=0;i<H;i++){
		if(i%2==0){
			for(int j=1;j<W-1;j++){
				a[i][j]='#';
			}
		}else{
			for(int j=1;j<W-1;j++){
				b[i][j]='#';
			}
		}
		a[i][0]='#';
		b[i][W-1]='#';
	}
	for(int i=0;i<H;i++)cout << a[i] << endl;
	cout << endl;
	for(int i=0;i<H;i++)cout << b[i] << endl;
	return 0;
}