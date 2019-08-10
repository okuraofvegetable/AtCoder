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
int sx,sy;
int tx,ty;
int main(){
	cin >> sx >> sy;
	cin >> tx >> ty;
	int dx = tx-sx;
	int dy = ty-sy;
	for(int i=0;i<dy;i++){
		cout << 'U';
	}
	for(int i=0;i<dx+1;i++){
		cout << 'R';
	}
	for(int i=0;i<dy+1;i++){
		cout << 'D';
	}
	for(int i=0;i<dx+1;i++){
		cout << 'L';
	}
	cout << 'U';
	cout << 'L';
	for(int i=0;i<dy+1;i++){
		cout << 'U';
	}
	for(int i=0;i<dx+1;i++){
		cout << 'R';
	}
	for(int i=0;i<dy+1;i++){
		cout << 'D';
	}
	for(int i=0;i<dx;i++){
		cout << 'L';
	}
	cout << endl;
	return 0;
}
