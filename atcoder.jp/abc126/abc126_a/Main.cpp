#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	string s;
	int n,k;
	cin >> n >> k;
	cin >> s;
	s[k-1]=s[k-1]-'A'+'a';
	cout << s << endl;
	return 0;
}