#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef multiset<int>::iterator msi;
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
set<string> ss;
int main(){
	string s;
	int K;
	cin >> s;
	cin >> K;
	if(s.size()>5){
		for(int i=0;i<s.size();i++){
			for(int j=1;j<=5;j++){
				ss.insert(s.substr(i,j));
			}
		}
	}else{
		for(int i=0;i<s.size();i++){
			for(int j=1;j<=s.size()-i;j++){
				ss.insert(s.substr(i,j));
			}
		}
	}
	set<string>::iterator it = ss.begin();
	for(int i=0;i<K-1;i++)it++;
	cout << *it << endl;
	return 0;
}