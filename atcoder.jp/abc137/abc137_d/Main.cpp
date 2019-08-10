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
int N,M;
P job[100100]; 
set<int> s;
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> job[i].sec >> job[i].fi;
	}
	sort(job,job+N,greater<P>());
	for(int i=0;i<M;i++){
		s.insert(i);
	}
	int ans = 0;
	for(int i=0;i<N;i++){
		int b = M-job[i].sec;
		set<int>::iterator it = s.upper_bound(b);
		if(it!=s.begin()){
			it--;
			ans += job[i].fi;
			s.erase(it);
		}
	}
	cout << ans << endl;
	return 0;
}
