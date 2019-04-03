#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#define ROW 12
#define COL 80 
#define bullet 50
int i,j,ammo,x=18,y=8;				//head of stickman(5,8)
char k;								//input from keyboard
char map[ROW][COL]={"             #################################################################\0",		//0
				    "             #                                                               #\0",
				    "             #                                                               #\0",
				    "             #                                                               #\0",
				    "             #                                                               #\0",
				    "             #                                                               #\0",		//5
				    "             #                                                               #\0",
				    "             #                                                               #\0",
				    "             #    O                                                          #\0",
				    "             #   \\|v¡kùç=¤@                                                  #\0",
				    "             #   / \\                                                         #\0",		//10
				    "             #################################################################\0"};
void control();						//control stickman from keyboard
void refresh(int,int);				//move cursor and refresh the screen


int main(void)
{
	system("cls");
	printf("\e[?25l");  //hide cursor
	refresh(0,0);
    ammo=bullet;
								
	while(1)
	{
		while(!kbhit())
		{
			refresh(0,0);
			for(i=0;i<ROW;i++)
			{	
				for(j=COL-3;j>=0;j--)
				{
					if(map[i][j]=='-')
					{
						map[i][j]=' ';
						if(map[i][j+1]!='#')
							map[i][j+1]='-';
					}
				}
			
			}
			Sleep(8);
		}
		
		k=getch();					//control stickman
		control();
		
	}
	return 0;					  
}

void control(void)
{
	switch(k)
		{
			case 'w':
				printf("w");
				break;
				
			case 'a':
				break;
				
			case 'd':
				if(x+14==' ')
				{
					for(j=y;j>=y-2;j--)
					{
						for(i=x-5;i<=x+5;i++)
						map[i][j]=' ';
					}
					x++;
					
					/*map[x-1][y-1]	//lefthand
					map[x-1][y]		//body
					map[x-1][y+1]	//righthand
					map[x-1][y+2]	//¡k
					map[x-1][y+3]	//ùç
					map[x-1][y+4]	//=
					map[x-1][y+5]   //¤@
					*/
				}
				break;
				
			case 'r':
				ammo=bullet;
				break;
				
			case ' ':				//shoot
				if(ammo>0)
				{
					map[y+1][x+9]='-';
					ammo--;
				}
		}	
}

void refresh(int x,int y)		
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
	printf("\n\n");
	for(i=0;i<ROW;i++)
		puts(map[i]);
	printf("\n            ammo: %d       \n\n",ammo);
	printf("\n            use W A S D to move, use space to shoot, R to reload\n\n");
}
