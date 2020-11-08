#include <stdio.h>
#include <string.h>
int main(void)
{
	int n,i,ans,tmp;
	char cmd[6];
	int dice[6];
	// while(1)
	{
		ans = 1;
		for(i=0;i<6;i++)
		{
			dice[i] = i+1;
		}
		scanf("%d",&n);
		if(n == 0)return 0;
		for(i=0;i<n;i++)
		{
			scanf("%s",cmd);
			if(strcmp(cmd,"North") == 0)
			{
				tmp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[4];
				dice[4] = tmp;
				ans += dice[0];
			}
			else if(strcmp(cmd,"East") == 0)
			{
				tmp = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[2];
				dice[2] = dice[0];
				dice[0] = tmp;
				ans += dice[0];
			}
			else if(strcmp(cmd,"West") == 0)
			{
				tmp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[3];
				dice[3] = tmp;
				ans += dice[0];
			}
			else if(strcmp(cmd,"South") == 0)
			{
				tmp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
				ans += dice[0];
			}
			else if(strcmp(cmd,"Right") == 0)
			{
				tmp = dice[1];
				dice[1] = dice[2];
				dice[2] = dice[4];
				dice[4] = dice[3];
				dice[3] = tmp;
				ans += dice[0];
			}
			else if(strcmp(cmd,"Left") == 0)
			{
				tmp = dice[1];
				dice[1] = dice[3];
				dice[3] = dice[4];
				dice[4] = dice[2];
				dice[2] = tmp;
				ans += dice[0];
			}
			else
			{
				printf("ERROR\n");
				return 0;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
