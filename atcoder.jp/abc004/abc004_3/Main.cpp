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
deque<int> deq;
int N;
void shift_L(){
	int a = deq.front();
	deq.pop_front();
	deq.push_back(a);
}
int main(){
	for(int i=1;i<=6;i++)deq.pb(i);
	cin >> N;
	int M = N/5;
	for(int i=0;i<(M%6);i++)shift_L();
	int L = N%5;
	for(int i=0;i<L;i++){
		swap(deq[i],deq[i+1]);
	}
	for(int i=0;i<6;i++)cout << deq[i];
	cout << endl;
	return 0;
}