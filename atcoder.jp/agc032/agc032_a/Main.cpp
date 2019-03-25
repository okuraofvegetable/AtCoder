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
int N;
int main(){
	cin >> N;
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin >> a[i];
		a[i]--;
	}
	vector<int> ans;
	for(int i=0;i<N;i++){
		int idx = -1;
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]==j){
				idx = j;
				break;
			}
		}
		if(idx==-1){
			cout << -1 << endl;
			return 0;
		}
		a.erase(a.begin()+idx);
		ans.pb(idx+1);
	}
	reverse(all(ans));
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}