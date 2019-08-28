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
int p[200100];
vi a,b,c;
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> p[i];
	}
	a.resize(N);
	b.resize(N);
	c.resize(N);
	for(int i=0;i<N;i++){
		c[p[i]-1] = i;
	}	
	a[0] = 1;
	b[0] = c[0]-1;
	for(int i=1;i<N;i++){
		int diff = c[i]-c[i-1];
		if(diff>=0){
			a[i] = a[i-1]+diff+1;
			b[i] = b[i-1]-1;
		}else{
			a[i] = a[i-1]+1;
			b[i] = b[i-1]+diff-1;
		}
	}
	int g = b[N-1];
	for(int i=0;i<N;i++){
		cout << a[i];
		if(i+1<N)cout << ' ';
		else cout << endl;
	}
	for(int i=0;i<N;i++){
		cout << b[i]-g+1;
		if(i+1<N)cout << ' ';
		else cout << endl;
	}
	return 0;
}
