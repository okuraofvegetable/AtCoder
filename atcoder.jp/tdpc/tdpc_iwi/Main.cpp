#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> T;
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
string s;
int N;
int erasable[305][305];
int dp[305][305];
int culc(int l,int r){
	if(l>r)return 0;
	int& res = erasable[l][r];
	if(res!=-2)return res;
	if((r-l+1)%3!=0)return res=-1;
	if(s[l]!='i'||s[r]!='i')return res=-1;
	if(s[l+1]=='w'){
		int ret = culc(l+2,r-1);
		if(ret>=0)return res = ret+1;
	}
	if(s[r-1]=='w'){
		int ret = culc(l+1,r-2);
		if(ret>=0)return res = ret+1;
	}
	for(int i=l;i<r;i++){
		int L = culc(l,i),R = culc(i+1,r);
		if(L>=0&&R>=0)return res = L+R;
	}
	return res = -1;
}
int rec(int l,int r){
	int& res = dp[l][r];
	if(res!=-1)return res;
	res = 0;
	for(int i=l;i<r;i++){
		res = max(res,rec(l,i)+rec(i+1,r));
	}
	for(int i=l;i<=r;i++){
		res = max(res,culc(l,i));
		res = max(res,culc(i,r));
	}
	return res;
}
int main(){
	cin >> s;
	N = sz(s);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			erasable[i][j]=-2;
			dp[i][j]=-1;
		}
	}
	printf("%d\n",rec(0,N-1));
	return 0;
}