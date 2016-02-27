#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
int s[2010],t[2010];
int type[4010],id[4010];
int dp[4020][4020];
vector<int> v;
int rec(int l,int r){
	//cout << l << ' ' << r << endl;
	if(r<=l)return 0;
	if(dp[l][r]!=-1)return dp[l][r];
	if(type[l]!=0)return dp[l][r]=rec(l+1,r);
	if(type[r]!=1)return dp[l][r]=rec(l,r-1);
	int res = 0;
	if(l<=s[id[r]])res = max(res,rec(l,s[id[r]]-1)+rec(s[id[r]]+1,r-1)+1);
	if(t[id[l]]<=r)res = max(res,rec(l+1,t[id[l]]-1)+rec(t[id[l]]+1,r)+1);
	res = max(res,rec(l,r-1));
	res = max(res,rec(l+1,r));
	return dp[l][r]=res;
}
int main(){
	scanf("%d",&N);
	rep(i,N){
		scanf("%d %d",&s[i],&t[i]);
		if(s[i]>t[i])swap(s[i],t[i]);
		v.pb(s[i]);
		v.pb(t[i]);
	}
	sort(all(v));
	rep(i,N){
		s[i]=lower_bound(all(v),s[i])-v.begin();
		t[i]=lower_bound(all(v),t[i])-v.begin();
		type[s[i]]=0;
		id[s[i]]=i;
		type[t[i]]=1;
		id[t[i]]=i;
	}
	memset(dp,-1,sizeof(dp));
	printf("%d\n",rec(0,2*N-1));
	return 0;
}