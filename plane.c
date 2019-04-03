#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define ROW 31 
#define COL 85 
#define bullet 100
int i,j,lose=0,score=1,stage=0,wepon=1,ammo,x=48,y=26;				//coordinate of the plane(x,y)
char k;								        //input from keyboard
char map[ROW][COL]={"               #####################################################################\0",		//0
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",		//5
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",      //10
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",      //15
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",      //20
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",
				    "               #                                                                   #\0",     //25
				    "               #                                A                                  #\0",
				    "               #                               /|\\                                 #\0",     
				    "               #                              <[|]>                                #\0",
				    "               #                                                                   #\0",		
				    "               #####################################################################\0"};     

void control();						//control from keyboard
void refresh(int,int);				//move cursor and refresh the screen
void clearplane(void);              //clear old plane
void enemy(void);
void level1(void);                  //behavior of level1 enemy

int main(void)
{
	start:
	lose=0,score=1,stage=0,wepon=1,ammo,x=48,y=26;
    system("cls");
    printf("\e[?25l");  //hide cursor
	refresh(0,0);
    ammo=bullet;
								
	while(1)
	{
		while(!kbhit())
		{
			refresh(0,0);
			for(i=0;i<ROW;i++)                       //.
			{	
				for(j=0;j<COL;j++)
				{
					if(map[i][j]=='.')
					{
						map[i][j]=' ';
						if(map[i-1][j]!='#')
							map[i-1][j]='.';
					}
				}
			}
			Sleep(30);
			if(score%1000==0)
			{
                stage++;
            }
            else 
            {
                enemy();
            }
            score++;
		}
		
		k=getch();					//control plane
		control();
		
		if(lose==1)
		  break;
	}
	printf("    Bang!\n");         //lose
	Sleep(500);
	printf("    Play again?  y/n");
	do{
		k=getch();
		if(k=='y')
			goto start;
	}while(k!='y'&&k!='n');
	return 0;					  
}

void enemy(void)                  //spawn enemy
{
    
    if(score<1000)
    {
        if(score%100==0)
        map[2][40]='@';
    }
}

void level1(void)
{
    for(i=1;i<ROW;i++)
    {
        for(j=0;j<COL;j++);
        
    }

}

void control(void)
{
	switch(k)
		{
			case 'w':
			    if(map[y-1][x]!='#')
			    {
    				clearplane();
                    map[y-1][x]='A';
    				map[y][x-1]='/';
    				map[y][x]='|';
    				map[y][x+1]='\\';
    				map[y+1][x-2]='<';
    				map[y+1][x-1]='[';
    				map[y+1][x]='|';
    				map[y+1][x+1]=']';
    				map[y+1][x+2]='>';
    				y--;
    			}
				break;
				
			case 'a':
			    if(map[y+2][x-4]!='#'&&map[y+2][x-3]!='#')
			    {
    				clearplane();
                    map[y][x-2]='A';
    				map[y+1][x-3]='/';
    				map[y+1][x-2]='|';
    				map[y+1][x-1]='\\';
    				map[y+2][x-4]='<';
    				map[y+2][x-3]='[';
    				map[y+2][x-2]='|';
    				map[y+2][x-1]=']';
    				map[y+2][x]='>';
    				x-=2;
    			}
				break;
			
            case 's':
			    if(map[y+3][x]!='#')
			    {
    				clearplane();
                    map[y+1][x]='A';
    				map[y+2][x-1]='/';
    				map[y+2][x]='|';
    				map[y+2][x+1]='\\';
    				map[y+3][x-2]='<';
    				map[y+3][x-1]='[';
    				map[y+3][x]='|';
    				map[y+3][x+1]=']';
    				map[y+3][x+2]='>';
    				y++;
    			}
				break;	
				
			case 'd':
				if(map[y+2][x+4]!='#'&&map[y+2][x+3]!='#')
			    {
    				clearplane();
                    map[y][x+2]='A';
    				map[y+1][x+1]='/';
    				map[y+1][x+2]='|';
    				map[y+1][x+3]='\\';
    				map[y+2][x]='<';
    				map[y+2][x+1]='[';
    				map[y+2][x+2]='|';
    				map[y+2][x+3]=']';
    				map[y+2][x+4]='>';
    				x+=2;
    			}
				break;
				
			case 'r':
				ammo=bullet;
				break;
				
			case ' ':				    //shoot
				
                if(ammo>0&&map[y-1][x]!='#')
				{
					if(wepon==1)
                        map[y-1][x]='.';
					if(wepon==2)
					{
				        map[y-1][x-2]='.';
				        map[y-1][x]='.';
				        map[y-1][x+2]='.';
                    }
                    ammo--;
				}
		}	
}

void clearplane(void)
{
    map[y][x]=' ';
    map[y+1][x-1]=map[y+1][x]=map[y+1][x+1]=' ';
    map[y+2][x-2]=map[y+2][x-1]=map[y+2][x]=map[y+2][x+1]=map[y+2][x+2]=' ';
}

void refresh(int x,int y)		
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
	printf("\n");
	for(i=0;i<ROW;i++)
		puts(map[i]);
	printf("\n            ammo: %d      \n            time: %d\n",ammo,score);
}
