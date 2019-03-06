#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
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
#define MAX_N 100100
struct BIT{
	ll bit[MAX_N+1];
	void add(int i,ll x){
		i++;
		while(i<=MAX_N){
			bit[i]+=x;
			i+=i&-i;
		}
		return;
	}
	ll sum(int i){
		i++;
		ll res=0;
		while(i>0){
			res+=bit[i];
			i-=i&-i;
		}
		return res;
	}
	ll sum(int l,int r){// [l,r]
		if(l==0)return sum(r);
		else return sum(r)-sum(l-1);
	}
}bit;
string s;
string A[2],B[2];
string S,T;
int cnt[30];
set<int> se[30];
int c[30];
int N;
ll ans = 0ll;
ll solve(){
	ll res = 0ll;
	for(int i=0;i<S.size();i++){
		bit.add(i,1);
		se[S[i]-'a'].insert(i);
	}
	for(int i=0;i<T.size();i++){
		set<int>::iterator it = se[T[i]-'a'].begin();
		bit.add(*it,-1);
		res += bit.sum(*it);
		se[T[i]-'a'].erase(it);
	}
	return res;
}
inline int asc(int x){
	return s[x]-'a';
}
int main(){
	cin >> s;
	N = s.size();
	for(int i=0;i<s.size();i++){
		cnt[s[i]-'a']++;
	}
	int odd = 0;
	int center = -1;
	for(int i=0;i<26;i++){
		if(cnt[i]%2==1){
			odd++;
			center = i;
		}
	}
	if(odd>1){
		cout << -1 << endl;
		return 0;
	}
	if(odd==1){
		for(int i=0;i<N;i++){
			c[asc(i)]++;
			if(asc(i)==center&&c[center]==(cnt[center]+1)/2){
				center = i;
				break;
			}
		}
		if(center>N/2){
			center = N-1-center;
			reverse(all(s));
		}
	}
	int p = 0,q = 0;
	memset(c,0,sizeof(c));
	for(int i=0;i<2;i++){
		A[i].resize(N);
		B[i].resize(N);
	}
	int flag = 0;
	for(int i=0;i<(N+1)/2;i++){
		c[asc(i)]++;
		if(i==center){
			ans += q;
			flag = 1;
			continue;
		}
		if(c[asc(i)]<=cnt[asc(i)]/2){
			ans+=q+flag;
			A[0][p++]=s[i];
		}else{
			A[1][q++]=s[i];
		}
	}
	A[0].resize(p);
	A[1].resize(q);
	p=0;q=0;
	memset(c,0,sizeof(c));
	for(int i=0;i<N/2;i++){
		c[asc(N-1-i)]++;
		if(c[asc(N-1-i)]<=cnt[asc(N-1-i)]/2){
			ans+=q;
			B[0][p++]=s[N-1-i];
		}else{
			B[1][q++]=s[N-1-i];
		}
	}
	B[0].resize(p);
	B[1].resize(q);
	reverse(all(B[1]));
	reverse(all(A[1]));
	ans += ((ll)A[1].size()+(ll)flag)*(ll)B[1].size();
	S = A[0]+B[1];
	T = B[0]+A[1];
	//cout << A[0] << ' ' << A[1] << endl;
	//cout << B[0] << ' ' << B[1] << endl;
	//cout << S << endl;
	//cout << T << endl;
	ans += solve();
	cout << ans << endl;
	return 0;
}