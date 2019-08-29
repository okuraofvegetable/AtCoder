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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int N;
int x[505];
int pos = 0;
vi ans;
void nxt(){
	while(pos<ans.size()&&ans[pos]!=-1)pos++;
}
int main(){
	cin >> N;
	ans = vi(N*N,-1);
	vector<P> vec;
	for(int i=0;i<N;i++){
		cin >> x[i];
		x[i]--;
		vec.pb(P(x[i],i+1));
	}
	sort(all(vec));
	for(int i=0;i<N;i++){
		int tar = vec[i].fi;
		int num = vec[i].sec;
		ans[tar] = num;
		for(int j=0;j<num-1;j++){
			nxt();
			ans[pos] = num;
		}	
		// cout << pos << ' ' << tar << endl;
		if(pos>tar){
			cout << "No" << endl;
			return 0;
		}
		// dump(ans);
	}
	for(int i=0;i<N;i++){
		int tar = vec[i].fi;
		int num = vec[i].sec;
		for(int j=num+1;j<=N;j++){
			nxt();
			if(pos<tar){
				cout << "No" << endl;
				return 0;
			}
			ans[pos] = num;
		}
	}
	cout << "Yes" << endl;
	dump(ans);
	return 0;
}

