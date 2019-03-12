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
#define MAX_N 100000
bool prime[MAX_N+100];
void eratos(){
    for(int i=0;i<MAX_N;i++)prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=MAX_N;i++){
    	if(prime[i]){
    		for(int j=i*2;j<=MAX_N;j+=i)prime[j]=false;
    	}
    }
    return;
}
ll is_sq(ll x){
	ll s = (ll)sqrt((double)x);
	for(ll i=-1ll;i<=1ll;i++){
		if((s+i)*(s+i)==x){
			assert(prime[s+i]);
			return s+i;
		}
	}
	return -1ll;
}
int N;
vector<ll> p;
ll s[100100];
map<ll,int> m;
map<ll,ll> f;
int main(){
	cin >> N;
	for(int i=0;i<N;i++)cin >> s[i];
	eratos();
	for(int i=1;i<=2000;i++){
		if(prime[i])p.pb((ll)i);
	}
	bool flag = false;
	for(int i=0;i<N;i++){
		ll nf = 1ll;
		ll pa = 1ll;
		ll t = s[i];
		for(int j=0;j<p.size();j++){
			int c = 0;
			while(t%p[j]==0){
				t/=p[j];
				c++;
			}
			if((c%3)>0){
				for(int k=0;k<(c%3);k++)nf*=p[j];
				for(int k=0;k<3-(c%3);k++)pa*=p[j];
			}
		}
		if(t!=1ll){
			nf *= t;
			ll rt = is_sq(t);
			if(rt==-1ll)pa *= (t*t);
			else pa *= rt;
		}
		//cout << nf << ' ' << pa << endl;
		if(nf==1ll){
			flag = true;
			continue;
		}
		m[nf]++;
		f[nf]=pa;
	}
	map<ll,int>::iterator it;
	int ans = 0;
	int mi = 0;
	for(it=m.begin();it!=m.end();it++){
		//cout << it->fi << ' ' << it->sec << endl;
		map<ll,int>::iterator it2 = m.find(f[it->fi]);
		if(it2==m.end()){
			ans+=it->sec;
		}else{
			//cout << it2->fi << ' ' << it2->sec << endl;
			mi += max(it->sec,it2->sec);
		}
	}
	ans+=mi/2;
	if(flag)ans++;
	cout << ans << endl;
	return 0;
}