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
int main(){
	string S;
	cin >> S;
	int n=0,w=0,s=0,e=0;
	for(int i=0;i<S.size();i++){
		if(S[i]=='N')n++;
		if(S[i]=='W')w++;
		if(S[i]=='S')s++;
		if(S[i]=='E')e++;
	}
	if((n>0&&s==0)||(s>0&&n==0)||(e>0&&w==0)||(w>0&&e==0))printf("No\n");
	else printf("Yes\n");
	return 0;
}