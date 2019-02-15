#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000ll
#define LLINF 2000000000000000000ll
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
#define MOD 998244353ll // prime
// How to devide :
// ModInt a(6ll);
// ModInt b(2ll);
// a *= b.exp(MOD-2ll);  -> a/=b;  result: a = 3
struct ModInt{
	ll val;
	ModInt():val(0ll){}
	ModInt(ll v):val(((v%MOD)+MOD)%MOD){}
	ModInt exp(ll y)const{
		if(!y)return ModInt(1ll);
		ModInt a = exp(y/2ll);
		a *= a;
		if(y&1)a*=(*this);
		return a;
	}
	bool operator==(const ModInt& x)const{return val==x.val;}
	inline bool operator!=(const ModInt& x)const{return !(*this==x);}
	bool operator<(const ModInt& x)const{return val<x.val;}
	bool operator>(const ModInt& x)const{return val>x.val;}
	inline bool operator>=(const ModInt& x)const{return !(*this<x);}
	inline bool operator<=(const ModInt& x)const{return !(*this>x);}
	ModInt& operator+=(const ModInt& x){if((val+=x.val)>=MOD)val-=MOD;return *this;}
	ModInt& operator-=(const ModInt& x){if((val+=MOD-x.val)>=MOD)val-=MOD;return *this;}
	ModInt& operator*=(const ModInt& x){(val*=x.val)%=MOD;return *this;}
	ModInt operator+(const ModInt& x)const{return ModInt(*this)+=x;}
	ModInt operator-(const ModInt& x)const{return ModInt(*this)-=x;}
	ModInt operator*(const ModInt& x)const{return ModInt(*this)*=x;}
};
istream& operator>>(istream&i,ModInt&x){i>>x.val;return i;}
ostream& operator<<(ostream&o,const ModInt&x){o<<x.val;return o;}
string s;
set<string> se;
queue<string> q;
ModInt dp[200100][2][3][3];
int main(){
	cin >> s;
	bool al = true;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[0])al=false;
	}
	if(al){
		cout << 1 << endl;
		return 0;
	}
	if(s.size()<=3){
		q.push(s);
		se.insert(s);
		while(!q.empty()){
			string a = q.front();
			q.pop();
			for(int i=0;i+1<a.size();i++){
				if(a[i]!=a[i+1]){
					string b = a;
					for(char c='a';c<='c';c++){
						if(c!=a[i]&&c!=a[i+1]){
							b[i]=b[i+1]=c;
							break;
						}
					}
					if(se.find(b)==se.end()){
						q.push(b);
						se.insert(b);
					}
				}
			}
		}
		cout << se.size() << endl;
		return 0;
	}
	for(int i=0;i<3;i++)dp[0][0][i][i]=ModInt(1ll);
	for(int i=0;i+1<s.size();i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					if(j==l)dp[i+1][1][l][(k+l)%3]+=dp[i][0][j][k];
					else dp[i+1][0][l][(k+l)%3]+=dp[i][0][j][k];
					dp[i+1][1][l][(k+l)%3]+=dp[i][1][j][k];
				}
			}
		}
	}
	int sk = 0;
	for(int i=0;i<s.size();i++)sk = (sk+(s[i]-'a'))%3;
	bool check = false;
	for(int i=0;i+1<s.size();i++){
		if(s[i]==s[i+1])check = true;
	}
	ModInt ans;
	for(int i=0;i<3;i++)ans += dp[s.size()-1][1][i][sk];
	if(!check)ans += ModInt(1ll);
	cout << ans << endl;
	return 0;
}