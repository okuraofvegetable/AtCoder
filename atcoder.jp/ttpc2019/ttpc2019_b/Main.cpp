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
template<class T>
void dump(vector<T> &vec){
	for(int i=0;i<vec.size();i++){
		cout << vec[i];
		if(i+1<vec.size())cout << ' ';
		else cout << endl;
	}
	return;
}
bool check(string s){
	for(int i=0;i+7<=s.size();i++){
		for(int j=i+4;j+3<=s.size();j++){
			if(s.substr(i,4)=="okyo"&&s.substr(j,3)=="ech"){
				return true;
			}
		}
	}
	return false;
}
int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string s;
		cin >> s;
		if(check(s))cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}