#include <stdlib.h>
#include <stdio.h>

struct node
{
    int dist[20];
    int from[20];
} route[10];

int main()
{
    int dm[20][20], no;
    printf("No of nodes  ");
    scanf("%d",&no);
    printf("\nDistance matrix  \n");
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < no; j++)
        {
            scanf("%d",&dm[i][j]);
           /* if(dm[i][j]==-1)
            	dm[i][j]=1000;
              Set distance from i to i as 0 */
            dm[i][i] = 0;
            route[i].dist[j] = dm[i][j];
            route[i].from[j] = j;
        }
    }

    int flag;
    do
    {
        flag = 0;
        for (int i = 0; i < no; i++)
        {
            for (int j = 0; j < no; j++)
            {
                for (int k = 0; k < no; k++)
                {
                    if ((route[i].dist[j]) > (dm[i][k] + route[k].dist[j]))
                    {
                        route[i].dist[j] = route[i].dist[k] + route[k].dist[j];
                        route[i].from[j] = k;
                        flag = 1;
                    }
                }
            }
        }
    } while (flag);

    for (int i = 0; i < no; i++)
    {
        printf("\nRouter  %d  \n",i+1);
        printf("Node\tNext\tDist\n");
        for (int j = 0; j < no; j++)
        {
            if((j+1)!=(route[i].from[j]+1))
                printf("%d\t%d\t%d\n", j+1, route[i].from[j]+1, route[i].dist[j]);
            else printf("%d\t-\t%d\n", j+1, route[i].dist[j]);
        }
    }
    return 0;
}

/*
0 5 2 3 100
5 0 4 100 3
2 4 0 100 4
3 100 100 0 100
100 3 4 100 0

*/
