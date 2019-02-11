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
int K;
int d[100100];
int main(){
	cin >> K;
	for(int i=0;i<K;i++)d[i]=INF;
	int s = 1;
	d[s]=0;
	deque<int> deq;
	deq.push_back(1);
	while(!deq.empty()){
		int prev = deq.back();
		deq.pop_back();
		int nxt = (prev+1)%K;
		if(d[nxt]>d[prev]+1){
			d[nxt]=d[prev]+1;
			deq.push_front(nxt);
		}
		nxt = (prev*10)%K;
		if(d[nxt]>d[prev]){
			d[nxt]=d[prev];
			deq.push_back(nxt);
		}
	}
	cout << d[0]+1 << endl;
	return 0;
}