#include <stdio.h>
#define num_element 150
int main(void)
{
	int i,n,m;
	char array[num_element];
	char a[2];
	char b[2];
	char input[2];
	//while(1)
	{
		for(i=0;i<num_element;i++)
		{
			array[i] = i;
		}
		scanf("%d",&n);
		if(n == 0)return 0;
		for(i=0;i<n;i++)
		{
			scanf("%s %s",a,b);
			array[a[0]] = b[0];
		}
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%s",input);
			printf("%c",array[input[0]]);
		}
		printf("\n");
	}
	return 0;
}
