#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 1000000000
#define LLINF 1000000000000000ll
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
int N;
int l[10];
int A[4];
int m[10];
int ans = INF;
int func(vector<int> v,int X){
	int M = v.size();
	int ret = INF;
	for(int i=1;i<(1<<M);i++){
		int cnt = 0;
		int res = 0;
		int sum = 0;
		for(int j=0;j<M;j++){
			if((i>>j)&1){
				cnt++;
				sum+=l[v[j]];
			}
		}
		res += 10*(cnt-1);
		res += abs(sum-X);
		ret = min(ret,res);
	}
	return ret;
}
void dfs(int d){
	if(d==N){
		int res = 0;
		for(int i=0;i<3;i++){
			vector<int> vec;
			for(int j=0;j<N;j++){
				if(m[j]==i)vec.pb(j);
			}
			if(vec.size()==0)return;
			res += func(vec,A[i]);
		}
		ans = min(ans,res);
		return;
	}
	for(int i=0;i<3;i++){
		m[d]=i;
		dfs(d+1);
	}
}
int main(){
	cin >> N;
	for(int i=0;i<3;i++)cin >> A[i];
	for(int i=0;i<N;i++)cin >> l[i];
	dfs(0);
	cout << ans << endl;
	return 0;
}