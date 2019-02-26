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
int n;
int v[100100];
int cnt[2][100100];
priority_queue<P> p,q;
int main(){
	cin >> n;
	for(int i=0;i<n;i++)cin >> v[i];
	for(int i=0;i<n;i++){
		cnt[i%2][v[i]]++;
	}
	for(int i=0;i<=100000;i++){
		if(cnt[0][i]>0)p.push(P(cnt[0][i],i));
		if(cnt[1][i]>0)q.push(P(cnt[1][i],i));
	}
	P a = p.top(), b = q.top();
	//cout << a.fi << ' ' << a.sec << endl;
	//cout << b.fi << ' ' << b.sec << endl;
	p.pop();q.pop();
	if(a.sec!=b.sec){
		cout << n - a.fi -b.fi << endl;
		return 0;
	}
	int ans = INF;
	if(p.empty())ans = min(ans,n-b.fi);
	else ans = min(ans,n-b.fi-(p.top()).fi);
	if(q.empty())ans = min(ans,n-a.fi);
	else ans = min(ans,n-a.fi-(q.top()).fi);
	cout << ans << endl;
	return 0;
}