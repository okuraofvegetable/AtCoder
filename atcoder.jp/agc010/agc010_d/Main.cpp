#include <bits/stdc++.h>
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
int N;
int a[100100];
int main(){
	cin >> N;
	int cnt = 0;
	for(int i=0;i<N;i++){
		cin >> a[i];
		if(a[i]%2==0)cnt++;
	}
	if(cnt%2==1)cout << "First" << endl;
	else{
		int r = 0;
		while(1){
			int c = 0;
			int g = 0;
			int odd = -1;
			for(int i=0;i<N;i++){
				// cout << a[i] << ' ';
				if(a[i]%2==1){
					c++;
					g = __gcd(g,a[i]-1);
					odd = a[i];
				}else{
					g = __gcd(g,a[i]);
				}
			}
			if(c!=1)break;
			if(odd==1)break;
			for(int i=0;i<N;i++){
				if(a[i]%2==1)a[i]--;
				a[i] /= g;
			}
			c = 0;
			for(int i=0;i<N;i++){
				if(a[i]%2==0)c++;
			}
			if(c%2==0)r++;
			else break;
		}
		if(r%2==0)cout << "Second" << endl;
		else cout << "First" << endl;
	}
	return 0;
}