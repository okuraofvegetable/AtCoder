#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> T;
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
int N,M;
int k[13];
vector<int> s[13];
int p[13];
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		cin >> k[i];
		s[i].resize(k[i]);
		for(int j=0;j<k[i];j++){
			cin >> s[i][j];
			s[i][j]--;
		}
	}
	for(int i=0;i<M;i++)cin >> p[i];
	int ans = 0;
	for(int i=0;i<(1<<N);i++){
		bool flag = true;
		for(int j=0;j<M;j++){
			int cnt = 0;
			for(int l=0;l<k[j];l++){
				if((i>>s[j][l])&1)cnt++;
			}
			if(cnt%2!=p[j]){
				flag = false;
				break;
			}
		}
		if(flag)ans++;
	}
	cout << ans << endl;
	return 0;
}