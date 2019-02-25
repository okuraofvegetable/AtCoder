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
int rui[100100];
#define MAX_N 200100
struct BIT{
	ll bit[MAX_N+1];
	void init(){
		memset(bit,0,sizeof(bit));
	}
	void add(int i,ll x){
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		i++;
		ll res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
	ll sum(int l,int r){// [l,r]
		if(l==0)return sum(r);
		else return sum(r)-sum(l-1);
	}
};
const int GETA = 100000;
P solve(char c){
	BIT bit;
	bit.init();
	for(int i=0;i<s.size();i++){
		if(s[i]==c)rui[i]=1;
		else rui[i]=-1;
	}
	for(int i=0;i<s.size();i++){
		rui[i+1]+=rui[i];
	}
	bit.add(GETA,1);
	int b = -1;
	for(int i=1;i<s.size();i++){
		if(bit.sum(GETA+rui[i]-1)>0){
			b=i;
			break;
		}
		bit.add(GETA+rui[i-1],1);
	}
	if(b==-1)return P(-1,-1);
	if(rui[b]>0)return P(0,b);
	for(int i=0;i<b;i++){
		if(rui[i]<rui[b]){
			return P(i+1,b);
		}
	}
}
int main(){
	cin >> s;
	for(int i=0;i<27;i++){
		char c = 'a'+i;
		P ans = solve(c);
		if(ans.fi!=-1){
			//cout << c << endl;
			cout << ans.fi+1 << ' ' << ans.sec+1 << endl;
			return 0;
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}