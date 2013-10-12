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
#define EQ(a,b) (abs((a)-(b))<EPS)
double rou(double n)
{
	n*=10;
	n+=0.5;
	int m=(int)n;
	double t=m;
	t/=10;
	return t;
}
int p(double a)
{
	if(rou(a)<=1.5)return 1;
	if(rou(a)<=3.3)return 2;
	if(rou(a)<=5.4)return 3;
	if(rou(a)<=7.9)return 4;
	if(rou(a)<=10.7)return 5;
	if(rou(a)<=13.8)return 6;
	if(rou(a)<=17.1)return 7;
	if(rou(a)<=20.7)return 8;
	if(rou(a)<=24.4)return 9;
	if(rou(a)<=28.4)return 10;
	if(rou(a)<=32.6)return 11;
	if(rou(a)>=32.7)return 12;
}
string ang(double n)
{
	n/=10;
	if(11.25<=n&&n<33.75)return "NNE";
	if(33.75<=n&&n<56.25)return"NE";
	if(56.25<=n&&n<78.75)return"ENE";
	if(78.75<=n&&n<101.25)return"E";
	if(101.25<=n&&n<123.75)return"ESE";
	if(123.75<=n&&n<146.25)return"SE";
	if(146.25<=n&&n<168.75)return"SSE";
	if(168.75<=n&&n<191.25)return"S";
	if(191.25<=n&&n<213.75)return"SSW";
	if(213.75<=n&&n<236.25)return"SW";
	if(236.25<=n&&n<258.75)return"WSW";
	if(258.75<=n&&n<281.25)return"W";
	if(281.25<=n&&n<303.75)return"WNW";
	if(303.75<=n&&n<326.25)return"NW";
	if(326.25<=n&&n<348.75)return"NNW";
	return "N";
}
int main()
{
	double deg,dis;
	cin >> deg >> dis;
	dis/=60;
	if(rou(dis)<=0.2)
	{
		cout << "C 0" << endl;
		return 0;
	}
	else
	{
		cout <<ang((double)deg)<<' '<<p(dis) << endl;
	}
	return 0;
}
