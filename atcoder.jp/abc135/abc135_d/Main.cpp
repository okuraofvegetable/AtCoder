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
ll MOD = 1000000007ll;
ll dp[100100][13];
string s;
int main(){
	cin >> s;
	dp[0][0]=1ll;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<13;j++){
			if(s[i]=='?'){
				for(int k=0;k<10;k++){
					dp[i+1][(j*10+k)%13]+=dp[i][j];
					dp[i+1][(j*10+k)%13]%=MOD;
				}
			}else{
				int k = s[i]-'0';
				dp[i+1][(j*10+k)%13]+=dp[i][j];
				dp[i+1][(j*10+k)%13]%=MOD;
			}
		}
	}
	cout << dp[s.size()][5] << endl;
	return 0;
}
