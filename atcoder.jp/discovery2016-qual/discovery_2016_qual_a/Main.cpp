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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int n;
int main(){
	cin >> n;
	string s = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
	for(int i=0;i<s.size();i++){
		cout << s.substr(i,1);
		if((i+1)%n==0)cout << endl;
	}
	if(sz(s)%n!=0)cout << endl;
	return 0;
}