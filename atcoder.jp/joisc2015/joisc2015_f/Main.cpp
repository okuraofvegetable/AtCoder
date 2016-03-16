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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
int N,K,M;
int S[2010],T[2010];
int type[4010],id[4010];
vector<int> zip;
int V[2010];
int to[2010],cost[2010];
bool used[2010];
vector<int> vs;
void dfs(int v){
	used[v]=true;
	vs.pb(v);
	if(to[v]!=-1)dfs(to[v]);
}
int dp[2010][2010][2];
int main(){
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0;i<N;i++){
		scanf("%d %d",&S[i],&T[i]);
		zip.pb(S[i]);zip.pb(T[i]);
	}
	S[N]=M;T[N]=0;
	N++;
	zip.pb(0);zip.pb(M);
	sort(all(zip));
	int SZ = sz(zip)-1;
	for(int i=0;i<N;i++){
		S[i] = lower_bound(all(zip),S[i])-zip.begin();
		T[i] = lower_bound(all(zip),T[i])-zip.begin();
		type[S[i]]=1;
		type[T[i]]=2;
		id[S[i]]=i;
		id[T[i]]=i;
	}
	int must = 0;
	memset(to,-1,sizeof(to));
	memset(cost,0,sizeof(cost));
	for(int i=0;i<SZ;i++){
		int val = zip[i+1]-zip[i];
		if(type[i]==1&&type[i+1]==1){
			V[id[i]]+=val;
		}else if(type[i]==1&&type[i+1]==2){
			if(id[i]==id[i+1]){
				V[id[i]]+=val;
			}else{
				to[id[i+1]]=id[i];
				cost[id[i]]=val;
			}
		}else if(type[i]==2&&type[i+1]==1){
			must += val;
		}else{
			V[id[i+1]]+=val;
		}
	}
	memset(used,false,sizeof(used));
	for(int i=1;i<SZ;i++){
		if(type[i]==1){
			if(!used[id[i]])dfs(id[i]);
		}
	}
	for(int i=0;i<=sz(vs);i++){
		for(int j=0;j<=K;j++){
			for(int k=0;k<2;k++){
				dp[i][j][k]=-INF;
			}
		}
	}
	dp[0][0][0]=0;
	int ans = 0;
	for(int i=0;i<vs.size();i++){
		for(int j=0;j<=K;j++){
			if(dp[i][j][0]!=-INF){
				chmax(dp[i+1][j][0],dp[i][j][0]);
				chmax(dp[i+1][j+1][1],dp[i][j][0]+V[vs[i]]);
			}
			if(dp[i][j][1]!=-INF){
				chmax(dp[i+1][j][0],dp[i][j][1]);
				chmax(dp[i+1][j+1][1],dp[i][j][1]+cost[vs[i]]+V[vs[i]]);
			}
			ans = max(ans,dp[i+1][j][0]);
			ans = max(ans,dp[i+1][j][1]);
		}
	}
	ans += must;
	printf("%d\n",ans);
	return 0;
}