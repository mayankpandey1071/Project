#include <stdio.h>
#include <stdlib.h>

void Menu()
{
	 printf("Tennis Final Matches Simulator\n\n");
	 printf("1. Press 1 to start the similation\n");
	  printf("2. Press 2 to quit\n");
	   printf("Optiom: \t"); 
}

int MatchResult()
{  
      
    return rand()%6; 
}
void TheVictor(int spain[],int Russia[],int winN,int spP[],int RsP[])
{    int cmpR,cmpS;
     int i,BestPlayerS,BestPlayerR,setS=0,setR=0,MaxS=0,MaxR=0;
     for(i=0;i<4;i++)
	{
		setS+=spain[i];
		if(MaxS<spain[i])
		{
			MaxS=spain[i];
			BestPlayerS=i+1;
		}
		if(MaxR<Russia[i])
		{
			MaxR=Russia[i];
			BestPlayerR=i+1;
		}
		setR+=Russia[i];
	}
	printf("\n\nAnnouncing the champion :\n");
	printf("-------------------------------------\n");
	printf("Number of Match Victory: Spain %d Vs Russia %d \n",winN,16-winN);
	if (winN==8)
	{
		printf("Draw ! We should compare the set victory of each team:\n");
		printf("Number of set Victory: Spain %d Vs Russia %d \n",setS,setR);
		if (setS==setR)
		{
			printf("Draw ! We should compare the set victory of best playes of each team:\n");
			printf("Number of set Victory of the best player: Spain %d Vs Russia %d \n",MaxS,MaxR);
			if(MaxS==MaxR)
			{
				printf("Draw ! Final match between the best players of each team shlould decide the best team :\n");
	printf("PLAYER %d of Spain %d Vs. %d PLAYER %d of Russia\n",BestPlayerS,spP[BestPlayerS-1],BestPlayerS,RsP[BestPlayerR-1],BestPlayerR);
	                 if (spP[BestPlayerS-1]==RsP[BestPlayerR-1])
	                 {
	                 	cmpS=rand()%6;
	                 	cmpR=rand()%6;
					 }
	                 else
	                 {
	                 cmpS=spP[BestPlayerS-1];
			          cmpR=RsP[BestPlayerR-1];	
					 }
				
			}
			else
			{
			cmpS=MaxS;
			cmpR=MaxR;
		    }
		}
		else
		{
		cmpS=setS;
		cmpR=setR;
	    }
		
	}
	else
	{
	cmpS=winN;
		cmpR=16-winN;	
	}
	
		printf("\nThe champion of 2047 tennis champio league is:\n");
		if(cmpR<cmpS)
		printf("Spain\n\n");
		else
		printf("Russia\n\n");
		printf("We wish all the champion the best for the next tennis champion league.\n See you in 2048");
}
void Table_of_statistics(int spain[],int Russia[],int winN)
{    int i,BestPlayerS,BestPlayerR,setS=0,setR=0,MaxS=0,MaxR=0;
	printf("Table of Statistics \n\n");
	printf("-------------------------------------\n");
	
	
	for(i=0;i<4;i++)
	{
		setS+=spain[i];
		if(MaxS<spain[i])
		{
			MaxS=spain[i];
			BestPlayerS=i+1;
		}
		if(MaxR<Russia[i])
		{
			MaxR=Russia[i];
			BestPlayerR=i+1;
		}
		setR+=Russia[i];
	}
	// Spain
	printf("Spain\n");
	printf("Number of Match Victory: %d\n",winN);
	printf("Number of set Victory: %d\n",setS);
	printf("Number of set Victory of the best player: %d\n",MaxS);
	printf("Best Player PLAYER %d\n\n",BestPlayerS);
   
   
   // Russia	
	printf("Russia\n");
	printf("Number of Match Victory: %d\n",16-winN);
	printf("Number of set Victory: %d\n",setR);
	printf("Number of set Victory of the best player: %d\n",MaxR);
	printf("Best Player PLAYER %d\n",BestPlayerR);
	
	
}

int main() 
{ srand(time(0));
  int setV[6][2]={{3,0},{3,1},{3,2},{0,3},{1,3},{2,3}};  //here we will generate random numeber to fetch randon set 
   int winN=0;                                                          // to avoid partiality
int i,spain[4]={};
int Russia[4]={};
int spP[4]={};
int RsP[4]={};
int spn=1,Rus=1;
int flag=1;
 while(1)
{
	int choice;
	Menu();
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			{
			   printf("Simulation Starts.....\n\n");
			   int randvalue;
			   for(i=1;i<=16;i++)
			   {  
			      printf("Match  %d\n", i);
			   	  printf("---------------------------------\n");
			   	  printf("PLAYER  %d (Spain) Vs. PLAYER %d  (Russia)\n", spn,Rus);
			   	  randvalue=MatchResult();
			   	  printf("Result: Spain %d - %d Russia \n\n",setV[randvalue][0],setV[randvalue][1]);
			   	  if(setV[randvalue][0]==3)
			   	    {
			   	  	 spain[spn-1]+=setV[randvalue][0]+setV[randvalue][1];
			   	  	 spP[spn-1]+=1;
			   	  	 winN++;
					 }
				   else 
				   {
				   	Russia[Rus-1]+=setV[randvalue][0]+setV[randvalue][1];
				   	RsP[Rus-1]+=1;
				   }
			   	  if(Rus==4)
			   	  {
			   	  	spn++;
			   	  	Rus=0;
				  }
				  Rus++;
			   	  
			   }
			   
			   // Table of statistics
			   Table_of_statistics(spain,Russia,winN);
			   TheVictor(spain,Russia,winN, spP,RsP);
			   
			   flag=1;
			   	break;
			}
		case 2:
			{
				flag=1;
					break;
			}
		
		default :
			{
			  printf("Please enter valid value\n");	
			  flag=0;
			}
	}
	if(flag)
	break;
}
  

  return 0;
}
