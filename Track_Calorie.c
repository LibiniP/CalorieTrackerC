// C Programming
// Design a system to track and suggest additional physical activities based on the calories burnt during various exercises, helping participants meet daily calorie-burning goals.
#include<stdio.h>
#include<string.h>

int main() {
  int n;
  FILE *fp;
  fp=fopen("labfile.txt","w");
  if(fp==NULL)
  {
   printf("Error opening the file.\n");
   return 1;
  } 
  int diff=0;
  char s[20];
  printf("Enter the number of participants \n");
  scanf("%d",&n);
  fprintf(fp,"%d\n",n);
  printf("Data written to file successfully \n");
  fclose(fp);

  int cal; int dur; int fn; int total=0;
  int durt; int calt; 
  int durt1,durt2,durt3,durt4,durt5;
  int calt1,calt2,calt3,calt4,calt5;
  int totalt1,totalt2,totalt3,totalt4,totalt5;
  printf("Enter Duration and Calorie Burnt for Running \n");
  scanf("%d%d",&durt1,&calt1);
  totalt1=durt1*calt1;
  printf("Enter Duration and Calorie Burnt for Cycling \n");
  scanf("%d%d",&durt2,&calt2);
  totalt2=durt2*calt2;
  printf("Enter Duration and Calorie Burnt for Yoga \n");
  scanf("%d%d",&durt3,&calt3);
  totalt3=durt3*calt3;
  printf("Enter Duration and Calorie Burnt for Swimming \n");
  scanf("%d%d",&durt4,&calt4);
  totalt4=durt4*calt4;
  printf("Enter Duration and Calorie Burnt for Pushups \n");
  scanf("%d%d",&durt5,&calt5);
  totalt5=durt5*calt5;
  int i;
  for(i=0;i<n;i++)
  { 
	dur=0; cal=0;total=0;int sum=0;
	printf("Enter the Name of participant %d \n",i+1);
	scanf("%s",s);
	printf("Participant %d. %s \n",i+1,s);
        int j=0;
        for(j=1;j<=7;j++)
        {
	printf("Enter your Day %d activity :\n 1.Running\n2.Cycling\n3.Yoga\n4.Swimming\n5.Pushups\n",j);
	int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        	case 1:printf("Running \nEnter the total duration(5-120 minutes) and calories burnt (100-1000 cal) \n");
			scanf("%d%d",&dur,&cal);
			total = dur*cal;
			sum+=total;
                	printf("Total calories burnt = %d \n",total);
  			diff=totalt1-total;
			if(diff<=0)
				printf("No additional activity required \n ");
			else
			{	if(diff<=totalt2)
				  printf("Suggested activity is cycling \n");
				if(diff<=totalt3)
				  printf("Suggested activity is Yoga \n");
				if(diff<=totalt4)
				  printf("Suggested activity is swimming \n");
				if(diff<=totalt5)
				  printf("Suggested activity is pushups \n");					
			}
                break;
		case 2:printf("Cycling \nEnter the total duration(5-120 minutes) and calories burnt (100-1000 cal) \n");
			scanf("%d%d",&dur,&cal);
			total = dur*cal;
               		 printf("Total calories burnt = %d \n",total);
			sum+=total;
                         diff=totalt2-total;
			if(diff<=0)
				printf("No additional activity required \n");
			else
			{	if(diff<=totalt1)
				  printf("Suggested activity is running \n");
				if(diff<=totalt3)
				  printf("Suggested activity is Yoga \n");
				if(diff<=totalt4)
				  printf("Suggested activity is swimming \n");
				if(diff<=totalt5)
				  printf("Suggested activity is pushups \n");					
			}
                break;
		case 3:printf("Yoga \nEnter the total total duration(5-120 minutes) and calories burnt (100-1000 cal) \n");
			scanf("%d%d",&dur,&cal);
			total = dur*cal;
                	printf("Total calories burnt = %d \n",total);
			diff=totalt3-total;
			sum+=total;
			if(diff<=0)
				printf("No additional activity required  \n");
			else
			{	if(diff<=totalt1)
				  printf("Suggested activity is running  \n");
				if(diff<=totalt2)
				  printf("Suggested activity is cycling \n");
				if(diff<=totalt4)
				  printf("Suggested activity is swimming  \n");
				if(diff<=totalt5)
				  printf("Suggested activity is pushups  \n");					
			}
                break;
		case 4:printf("Swimming \nEnter the total duration(5-120 minutes) and calories burnt (100-1000 cal)  \n");
			scanf("%d%d",&dur,&cal);
			total = dur*cal;
                	printf("Total calories burnt = %d  \n",total);
			diff=totalt4-total;
			sum+=total;
			if(diff<=0)
				printf("No additional activity required  \n");
			else
			{	if(diff<=totalt1)
				  printf("Suggested activity is running  \n");
				if(diff<=totalt3)
				  printf("Suggested activity is Yoga  \n");
				if(diff<=totalt2)
				  printf("Suggested activity is cycling  \n");
				if(diff<=totalt5)
				  printf("Suggested activity is pushups  \n");					
			}
                break;
		case 5:printf("Pushups \nEnter the total duration(5-120 minutes) and calories burnt (100-1000 cal)  \n");
			scanf("%d%d",&dur,&cal);
			total = dur*cal;
               		 printf("Total calories burnt = %d  \n",total);
			diff=totalt5-total;
			sum+=total;
			if(diff<=0)
				printf("No additional activity required  \n");
			else
			{	if(diff<=totalt2)
				  printf("Suggested activity is cycling  \n");
				if(diff<=totalt3)
				  printf("Suggested activity is Yoga  \n");
				if(diff<=totalt4)
				  printf("Suggested activity is swimming  \n");
				if(diff<=totalt1)
				  printf("Suggested activity is running  \n");					
			}
                break;
		default:printf("Enter a valid activity  \n");
		break;
	} 
    }
	printf("Total Calories burnt in a week= %d \n",sum);
	fp=fopen("labfile.txt","a");
 	if(fp==NULL)
  	{
  	 printf("Error opening the file.\n");
  	 return 1;
 	} 
      fprintf(fp,"%s: %d\n",s,sum);
     if(fp!=NULL) fclose(fp);
      printf("Data Written Successfully \n");
  }
}
