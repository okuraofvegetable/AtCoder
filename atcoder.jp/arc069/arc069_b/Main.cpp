#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
#define MOD 1000000007ll
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N;
string s;
string sw = "SW";
int d[100100];
int cir(int pos){
	return (pos+N)%N;
}
bool check(int pos){
	if(d[pos]==0){
		if(s[pos]=='o'&&d[cir(pos-1)]!=d[cir(pos+1)])return false;
		if(s[pos]=='x'&&d[cir(pos-1)]==d[cir(pos+1)])return false;
	}else{
		if(s[pos]=='o'&&d[cir(pos-1)]==d[cir(pos+1)])return false;
		if(s[pos]=='x'&&d[cir(pos-1)]!=d[cir(pos+1)])return false;
	}
	return true;
}
string solve(int a,int b){
	d[0]=a;
	d[1]=b;
	for(int i=1;i<N-1;i++){
		if(d[i]==0){
			if(s[i]=='o')d[i+1]=d[i-1];
			else d[i+1]=!d[i-1];
		}else{
			if(s[i]=='o')d[i+1]=!d[i-1];
			else d[i+1]=d[i-1];
		}
	}
	if(check(0)&&check(N-1)){
		string res = "";
		for(int i=0;i<N;i++)res+=sw[d[i]];
		return res;
	}else{
		return "-1";
	}
}
int main(){
	cin >> N;
	cin >> s;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			string res = solve(i,j);
			if(res!="-1"){
				cout << res << endl;
				return 0;
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}