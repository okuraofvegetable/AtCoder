#include<bits/stdc++.h>
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
int N,K;
string s;
deque<P> q;
void push_back(int v){
	if(q.empty())q.push_back(P(v,1));
	else if(q.back().fi==v)q.back().sec++;
	else q.push_back(P(v,1));
}
void pop_front(){
	assert(!q.empty());
	if(q.front().sec==1)q.pop_front();
	else q.front().sec--;
}
void clear(){
	while(!q.empty())q.pop_back();
}
bool check(int k){
	clear();
	for(int i=0;i<N;i++){
		if(i>=k)pop_front();
		push_back(s[i]-'0');
		if(i>=k-1){
			int sz = q.size();
			if(q.front().fi==1)sz--;
			if(sz!=0&&q.back().fi==1)sz--;
			if((sz+1)/2<=K)return true;
		}
	}
	return false;
}
int main(){
	cin >> N >> K;
	cin >> s;
	int l = 1, r= N+1;
	while(r-l>1){
		int mid = (l+r)/2;
		if(check(mid))l=mid;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}