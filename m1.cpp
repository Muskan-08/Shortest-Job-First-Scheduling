#include<stdio.h>
#include<conio.h>
void main()
{
  int i,j,n,t,pr[20],bt[20],wt[20];
  printf("Enter number of processes : ");
  scanf("%d",&n); 
	start:
	for(i=0;i<n;i++)
	{
    	scanf("%d",&bt[i]);
    	 pr[i]=i;
  	}
  	for(i=0;i<n;i++)
  	{
  		if(bt[i]<=0)
  		{
  			printf("you have inappropriate value, do renter it");
  			goto start;
		}
  		
  	}
}
  	
