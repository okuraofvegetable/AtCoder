#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
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
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
char str[1050];
int main()
{
	scanf("%s",str);
	vector<char> ch;
	vector<int> num;
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		if(ch.empty()||ch.back()!=str[i])
		{
			ch.pb(str[i]);
			num.pb(1);
		}
		else num[num.size()-1]++;
	}
	for(int i=0;i<ch.size();i++)printf("%c%d",ch[i],num[i]);
	puts("");
	return 0;
}
