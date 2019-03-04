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
int K,N;
void print(vector<int> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
int main(){
	cin >> K >> N;
	vector<int> ans;
	if(K%2==0){
		ans.pb(K/2);
		for(int i=0;i<N-1;i++)ans.pb(K);
		print(ans);
		return 0;
	}
	for(int i=0;i<N;i++){
		ans.pb((K+1)/2);
	}
	for(int i=0;i<N/2;i++){
		if(ans.back()==1){
			ans.pop_back();
		}else{
			ans.back()--;
			while(ans.size()<N)ans.pb(K);
		}
	}
	print(ans);
	return 0;
}