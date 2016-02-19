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
#define LLINF 100000000000000000ll
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
string s;
int J[200100],O[200100],I[200100];
map<P,int> m;
int main(){
	scanf("%d",&N);
	cin >> s;
	for(int i=1;i<=N;i++){
		if(s[i-1]=='J')J[i]++;
		if(s[i-1]=='O')O[i]++;
		if(s[i-1]=='I')I[i]++;
	}
	for(int i=1;i<=N;i++){
		J[i]+=J[i-1];
		O[i]+=O[i-1];
		I[i]+=I[i-1];
	}
	m[P(0,0)]=0;
	int ans = 0;
	for(int i=1;i<=N;i++){
		map<P,int>::iterator it = m.find(P(O[i]-J[i],I[i]-J[i]));
		if(it==m.end()){
			m[P(O[i]-J[i],I[i]-J[i])]=i;
		}else{
			ans = max(ans,i - it->sec);
		}
	}
	printf("%d\n",ans);
	return 0;
}