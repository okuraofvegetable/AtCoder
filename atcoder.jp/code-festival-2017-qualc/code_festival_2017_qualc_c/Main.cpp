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
int main(){
	string s;
	string S;
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='x'){
			S+=s[i];
		}
	}
	string T = S;
	reverse(all(T));
	if(S!=T){
		cout << -1 << endl;
		return 0;
	}
	int l = 0, r = s.size()-1;
	int ans = 0;
	while(l<r){
		if(s[l]==s[r]){
			l++;
			r--;
		}else{
			if(s[l]=='x'){
				ans++;
				l++;
			}else{
				ans++;
				r--;
			}
		}
	}
	cout << ans << endl;
}