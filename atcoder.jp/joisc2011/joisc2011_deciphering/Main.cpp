#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
#define MOD 10000000
int L,M;
char str[300100];
int pos[26];
int pre[300100][26];
ll dp[300100];
bool f[30][30];
int main(){
	scanf("%d",&L);
	scanf("%s",str);
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		char A,B;
		scanf(" %c %c",&A,&B);
		f[B-'A'][A-'A']=true;
	}
	memset(pos,-1,sizeof(pos));
	for(int i=0;i<L;i++){
		for(int j=0;j<26;j++){
			pre[i][j]=pos[j];
		}
		pos[str[i]-'A']=i;
	}
	for(int i=0;i<L;i++){
		dp[i]=1ll;
		for(int j=0;j<26;j++){
			if(pre[i][j]==-1)continue;
			if(!f[str[i]-'A'][j]){
				dp[i]+=dp[pre[i][j]];
				dp[i]%=MOD;
			}
		}
	}
	ll ans = 0;
	for(int i=0;i<26;i++){
		if(pos[i]!=-1){
			ans += dp[pos[i]];
			ans %= MOD;
		}
	}
	printf("%lld\n",ans);
	return 0;
}