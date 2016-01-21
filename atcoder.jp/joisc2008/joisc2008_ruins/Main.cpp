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
vector<P> vec;
int N;
P fix;
int dp[130][130];
bool comp(P a,P b){
	return atan2(a.sec-fix.sec,a.fi-fix.fi)<atan2(b.sec-fix.sec,b.fi-fix.fi);
}
bool check(P a,P b,P c){
	P ba = P(a.fi-b.fi,a.sec-b.sec);
	P bc = P(c.fi-b.fi,c.sec-b.sec);
	return bc.fi*ba.sec-bc.sec*ba.fi>0;
}
int ans=0;
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		P a;
		scanf("%d %d",&a.fi,&a.sec);
		vec.pb(a);
	}
	for(int i=0;i<N;i++){
		fix = vec[i];
		vector<P> v;
		v.pb(fix);
		for(int j=0;j<N;j++){
			if(vec[j].sec>=fix.sec&&j!=i)v.pb(vec[j]);
		}
		sort(v.begin()+1,v.end(),comp);
		int m = sz(v);
		//printf("fix %d %d\n",fix.fi,fix.sec);
		/*for(int j=0;j<v.size();j++){
			printf("%d %d\n",v[j].fi,v[j].sec);
		}*/
		memset(dp,0,sizeof(dp));
		for(int j=1;j<m;j++)dp[0][j]=2;
		for(int j=0;j<m;j++){
			P p;
			for(int k=j+1;k<v.size();k++){
				for(int l=k+1;l<v.size();l++){
					if(check(v[j],v[k],v[l])){
						//printf("%d %d %d ",j,k,l);
						dp[k][l]=max(dp[k][l],dp[j][k]+1);
						//printf("%d\n",dp[k][l]);
						ans = max(ans,dp[k][l]);
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}