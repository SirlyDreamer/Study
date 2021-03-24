#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main()
{
	char a[12][12];
	int visited[12][12] = {0};
	for(int i=0;i<10;i++)
	{
		visited[0][i] = 1;
		visited[11][i] = 1;
		visited[i][0] = 1;
		visited[i][11] = 1;
	}
	memset(a, '.', 144);
	int direction, x = 1, y = 1, tried = 0;
	char order = 'A';
	srand((unsigned)time(NULL));
	while (order <= 'Z')
	{
		direction = rand() % 4;
		switch (direction)
		{
		case 0:
			if (1 <= x - 1 && x - 1 <= 10 && visited[x - 1][y] == 0)
			{
				a[x][y] = order++;
				visited[x][y] = 1;
				x--;
			}
			break;
		case 1:
			if (1 <= x + 1 && x + 1 <= 10 && visited[x + 1][y] == 0)
			{
				a[x][y] = order++;
				visited[x][y] = 1;
				x++;
			}
			break;
		case 2:
			if (1 <= y - 1 && y - 1 <= 10 && visited[x][y - 1] == 0)
			{
				a[x][y] = order++;
				visited[x][y] = 1;
				y--;
			}
			break;
		case 3:
			if (1 <= y + 1 && y + 1 <= 10 && visited[x][y + 1] == 0)
			{
				a[x][y] = order++;
				visited[x][y] = 1;
				y++;
			}
			break;
		default:
			break;
		}
        if (visited[x + 1][y] + visited[x - 1][y] + visited[x][y + 1] + visited[x][y - 1] == 4)
        {
            a[x][y] = order;
			break;
        }
	}
	for (int j = 1; j <= 10; j++)
	{
		for (int k = 1; k <= 10; k++)
			printf("%c ", a[j][k]);
		printf("\n");
	}
	return 0;
}