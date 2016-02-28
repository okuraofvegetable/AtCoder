#include<bits/stdc++.h>
using namespace std;
typedef pair<double,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 1000000007
int D;
string s;
ll dp[10010][100][2];
int main(){
	scanf("%d",&D);
	cin >> s;
	dp[0][0][1]=1ll;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<D;j++){
			int c = s[i]-'0';
			for(int k=0;k<c;k++){
				dp[i+1][(j+k)%D][0]+=dp[i][j][1];
				dp[i+1][(j+k)%D][0]%=MOD;
			}
			dp[i+1][(j+c)%D][1]+=dp[i][j][1];
			dp[i+1][(j+c)%D][0]%=MOD;
			for(int k=0;k<10;k++){
				dp[i+1][(j+k)%D][0]+=dp[i][j][0];
				dp[i+1][(j+k)%D][0]%=MOD;
			}
		}
	}
	ll ans = (dp[sz(s)][0][0]+dp[sz(s)][0][1]+MOD-1)%MOD;
	printf("%lld\n",ans);
	return 0;
}