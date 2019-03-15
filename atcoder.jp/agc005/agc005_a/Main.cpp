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
string s;
int main(){
	cin >> s;
	stack<char> st;
	for(int i=0;i<s.size();i++){
		if(s[i]=='S')st.push(s[i]);
		else{
			if(!st.empty()&&st.top()=='S'){
				st.pop();
			}else{
				st.push(s[i]);
			}
		}
	}
	int ans = 0;
	while(!st.empty()){
		ans++;
		st.pop();
	}
	cout << ans << endl;
	return 0;
}