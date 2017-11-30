#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
int n;
vector<int> vec;
bool f(int x){
	int s = vec[0];
	for(int i=0;i<3;i++){
		if(x&1)s+=vec[i+1];
		else s-=vec[i+1];
		x >>= 1;
	}
	//cout << s << endl;
	return (s==7);
}
void print(int x){
	cout << vec[0];
	for(int i=0;i<3;i++){
		if(x&1)cout << "+";
		else cout << "-";
		cout << vec[i+1];
		x >>= 1;
	}
	cout << "=7" << endl;
}
int main(){
	cin >> n;
	for(int i=0;i<4;i++){
		vec.pb(n%10);
		n/=10;
	}
	reverse(all(vec));
	for(int i=0;i<(1<<3);i++){
		if(f(i)){
			print(i);
			return 0;
		}
	}	
	return 0;
}