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
#define sq(x) ((x)*(x))
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
string s;
int X[2];
vector<int> v[2];
int dir = 1;
bool flag = false;
bool dp[2][8001];
bool check(int k){
	int sum = 0;
	for(int i=0;i<v[k].size();i++)sum += v[k][i];
	if(sum<X[k])return false;
	if((sum-X[k])%2==1)return false;
	int sel = (sum-X[k])/2;
	if(sel>sum)return false;
	int n = v[k].size();
	memset(dp,0,sizeof(dp));
	dp[0][0]=true;
	for(int i=0;i<n;i++){
		for(int j=0;j<=8000;j++){
			dp[(i+1)%2][j]=false;
			if(dp[i%2][j])dp[(i+1)%2][j]=true;
			if(k==0&&i==0)continue;
			if(j-v[k][i]>=0&&dp[i%2][j-v[k][i]])dp[(i+1)%2][j]=true;
		}
	}
	return dp[n%2][sel];
}
int main(){
	cin >> s;
	cin >> X[0] >> X[1];
	v[0].pb(0);
	for(int i=0;i<s.size();i++){
		if(s[i]=='T'){
			dir*=-1;
			flag = true;
		}else{
			if(dir==1){
				if(flag){
					v[0].pb(1);
					flag = false;
				}else{
					v[0].back()++;
				}
			}else{
				if(flag){
					v[1].pb(1);
					flag = false;
				}else{
					v[1].back()++;
				}
			}
		}
	}
	/*for(int j=0;j<2;j++){
		for(int i=0;i<v[j].size();i++){
			cout << v[j][i] << ' ';	
		}
		cout << endl;
	}*/
	if(check(0)&&check(1))printf("Yes\n");
	else printf("No\n");
	return 0;
}