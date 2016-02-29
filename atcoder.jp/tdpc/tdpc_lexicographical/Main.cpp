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
const ll MX = 1000000000000000005ll;
string s;
int next[1000100][30];
int last[30];
ll dp[1000100];
int N;
ll K;
inline void add(ll& a,ll b){
	a += b;
	if(a>MX)a=MX;
}
int main(){
	cin >> s;
	scanf("%lld",&K);
	s = '$'+s;
	N = sz(s);
	for(int i=0;i<26;i++)last[i]=N;
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<26;j++){
			next[i][j]=last[j];
		}
		if(i>0)last[s[i]-'a']=i;
	}
	for(int i=N-1;i>=0;i--){
		if(i>0)dp[i]=1ll;
		for(int j=0;j<26;j++){
			add(dp[i],dp[next[i][j]]);
		}
	}
	//for(int i=0;i<N;i++)printf("%lld ",dp[i]);
	//printf("\n");
	if(dp[0]<K){
		printf("Eel\n");
		return 0;
	}
	string ans;
	int idx = 0;
	while(K>0){
		for(int i=0;i<26;i++){
			int nid = next[idx][i];
			if(nid==N)continue;
			if(K>dp[nid])K-=dp[nid];
			else{
				ans += ('a'+i);
				idx = nid;
				K--;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}