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
int N;
string s;
int dp[305][305];
int rec(int l,int r){
	if(l>r)return 0;
	if(dp[l][r]!=-1)return dp[l][r];
	if(l==r)return dp[l][r]=1;
	int res = rec(l,r-1)+1;
	for(int i=l;i<r;i++){
		if(s[i]==s[r])res = min(res,rec(l,i)+rec(i+1,r-1));
	}
	return dp[l][r]=res;
}
int main(){
	scanf("%d",&N);
	cin >> s;
	memset(dp,-1,sizeof(dp));
	printf("%d\n",rec(0,N-1));
	return 0;
}