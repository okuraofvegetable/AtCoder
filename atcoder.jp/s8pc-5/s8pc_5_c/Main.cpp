#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define LLINF 1000000000000000
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
void no(){
	printf("No\n");
}
void yes(){
	printf("Yes\n");
}
void solve(string s){
	int n = s.size();
	n /= 4;
	int a=0,b=0;
	int c=0,d=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='('){
			if(c<n){
				a++;c++;
			}else{
				b--;
				if(b<0){
					no();
					return;
				}
			}
		}else{
			if(d<n){
				b++;d++;
			}else{
				a--;
				if(a<0){
					no();
					return;
				}
			}
		}
	}
	if(a==0&&b==0)yes();
	else no();
	return;
}
int main(){
	int Q;
	cin >> Q;
	for(int i=0;i<Q;i++){
		string s;
		cin >> s;
		solve(s);
	}
	return 0;
}