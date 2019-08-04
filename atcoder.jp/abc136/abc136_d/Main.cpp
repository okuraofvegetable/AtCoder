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
string s;
int N;
int ans[100100];
int main(){
	cin >> s;
	N = s.size();
	int ch = 0;
	int pre = 0;
	for(int i=0;i<=s.size();i++){
		if((i==s.size())||(i>0&&(s[i-1]!=s[i]))){
			ch++;
		}
		if(ch==2){
			int l=0,r=0;
			for(int j=pre;j<i;j++){
				if(s[j]=='L')l++;
				else r++;
			}
			
			//cout << l << ' ' << r << endl;
			ans[pre+r-1] += (r+1)/2;
			//cout << pre+r-1 << ',' << (r+1)/2  << endl;
			ans[pre+r] += (r)/2;
			//cout << pre+r << ',' << r/2  << endl;
			ans[pre+r-1] += (l)/2;
			//cout << pre+r-1 << ',' << l/2  << endl;
			ans[pre+r] += (l+1)/2;
			//cout << pre+r << ',' << (l+1)/2  << endl;
			pre = i;
			ch = 0;
		}
	}

	for(int i=0;i<N;i++){
		cout << ans[i];
		if(i+1<N)cout << ' ';
		else cout << endl;
	}
	return 0;
}