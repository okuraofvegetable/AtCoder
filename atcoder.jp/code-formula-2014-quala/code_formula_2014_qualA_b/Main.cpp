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
#define EQ(a,b) (abs((a)-(b))<eps)
char a[11];
int main()
{
	int c,b;
	cin >> c >> b;
	for(int i=0;i<10;i++)a[i]='x';
	for(int i=0;i<c;i++)
	{
		int k;
		cin >> k;
		a[k]='.';
	}
	for(int i=0;i<b;i++)
	{
		int k;
		cin >> k;
		a[k]='o';
	}
	cout << a[7] << ' ' << a[8] << ' ' << a[9] << ' ' << a[0] << endl;
	cout << ' ' << a[4] << ' ' << a[5] << ' ' << a[6] << endl;
	cout << "  " << a[2] << ' ' << a[3]  << endl;
	cout << "   " << a[1] << endl;
	return 0;
}
