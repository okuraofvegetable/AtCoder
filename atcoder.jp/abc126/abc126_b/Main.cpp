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
int main(){
	string s;
	cin >> s;
	bool a=false,b = false;
	int u = (s[0]-'0')*10+(s[1]-'0');
	int v = (s[2]-'0')*10+(s[3]-'0');
	// /cout << u << ' ' << v << endl;
	if(1<=u&&u<=12)a=true;
	if(1<=v&&v<=12)b=true;
	if(a&&b)cout << "AMBIGUOUS" << endl;
	else if(a){
		cout << "MMYY" << endl;
	}else if(b){
		cout << "YYMM" << endl;
	}else{
		cout << "NA" << endl;
	}
	return 0;
}