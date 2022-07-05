//LEAKY BUCKET

#include<stdio.h>
#include<stdlib.h>

struct packet{
	int time;
	int size;
} p[50];

void main()
{
	int i,n,m,k=0;
	int bsize,bfilled,outrate;
	
	printf("Enter the bucket size\t");
	scanf("%d",&bsize);
	printf("Enter the output rate\t");
	scanf("%d",&outrate);
	
	printf("Number of packets\t");
	scanf("%d",&n);
	
	printf("Enter the time and size\n");
	for(i=0;i<n;i++)	
		scanf("%d%d",&p[i].time,&p[i].size);
	
	
	m=p[n-1].time;
	i=1;
	k=0;
	bfilled=0;
	
	while(i<=m || bfilled!=0)
	{
		printf("\nAt time %d",i);
		while(p[k].time<=i && k<n)
		{
			if(bsize>=bfilled+p[k].size)
			{
				bfilled=bfilled + p[k].size;
				printf("\n%d bytes packet added",p[k].size);
				k++;
			}
			else
			{
				printf("\n%d bytes packet is discarded",p[k].size);
				k++;
			}
		}
		
		if(bfilled==0)
			printf("\nNo packet to transmit");
		else if(bfilled>=outrate)
		{
			bfilled=bfilled-outrate;
			printf("\n%d bytes transferred",outrate);
		}
		else
		{
			printf("\n%d bytes transferred",bfilled);
			bfilled=0;
		}
		printf("\nIn the bucket %d bytes\n",bfilled);
		i++;
	}

}
