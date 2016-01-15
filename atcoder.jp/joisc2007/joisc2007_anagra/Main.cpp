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
int a[22];
string s;
int cnt[30];
ll fac[22];
int main(){
	cin >> s;
	for(int i=0;i<s.size();i++){
		a[i] = s[i]-'A';
		cnt[a[i]]++;
	}
	fac[0]=1ll;
	for(int i=1;i<=20;i++)fac[i]=fac[i-1]*(ll)i;
	ll ans = 0ll;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<30;j++){
			if(a[i]<=j)break;
			if(cnt[j]==0)continue;
			ll ret = fac[sz(s)-i-1];
			cnt[j]--;
			for(int k=0;k<30;k++)ret/=fac[cnt[k]];
			ans += ret;
			cnt[j]++;
		}
		cnt[a[i]]--;
	}
	cout << ans+1 << endl;
	return 0;
}