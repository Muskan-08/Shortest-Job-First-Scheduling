#include<stdio.h>
//#include<conio.h>
void main()
{
  int i,j,n,pr[20],bt[20],wt[20],avwt,avtt,temp,tt[20];
  printf("Enter number of processes : ");
  scanf("%d",&n); 
	start:
	for(i=0;i<n;i++)
	{
	    printf("Enter burst time for process :%d ",i);
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
    FILE *f;
   f=fopen("BURST.txt","w");
   for(i=0;i<n;i++)
   fprintf(f,"\t %d",bt[i]);
   fclose(f);
   printf("\nProcess \t Burst time \n");
   for(i=0;i<n;i++)
              {
  	printf("\t%d\t\t %d\n", pr[i],bt[i]);
             }
for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(bt[j]>bt[j+1])
      {
        temp= bt[j];
        bt[j] = bt[j+1];
        bt[j+1] = temp;
        
        temp=pr[j];
        pr[j] = pr[j+1];
        pr[j+1] = temp;
       }
     }
   }
   
   printf("Process ID \t Burst time \t Waiting time \t Turnaround Time \n");
   for(i=0;i<n;i++)
   {
       wt[i] = 0;
       tt[i] = 0;
     for(j=0;j<i;j++)
     {
       wt[i] = wt[i] + bt[j];
     }
     tt[i] = wt[i] + bt[i];
     avwt = avwt+ wt[i];
     avtt = avtt+ tt[i];
     printf("\t%d\t\t %d \t\t %d \t\t %d\n", pr[i], bt[i], wt[i], tt[i]);
   }
   avwt= avwt/n;
   avtt= avtt/n;
   printf("Average waiting time : %d\n",avwt);
   printf("Average turnaround time : %d",avtt);
   
 }
  	
