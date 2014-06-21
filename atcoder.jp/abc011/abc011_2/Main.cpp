#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
using namespace std;
char s[20];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		if(i)s[i]=tolower(s[i]);
		else s[i]=toupper(s[i]);
	}
	printf("%s\n",s);
	return 0;
}
