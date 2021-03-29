#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define SLEEP 100 
#define ROW 35 
#define COL 96 

void ConsoleFullScreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0);
    keybd_event(VK_RETURN,0x9c,KEYEVENTF_KEYUP,0);
}

void refresh()
{
	COORD point;
	point.X = 0; point.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}

int main()
{
	ConsoleFullScreen();
	int i, j, k, l,neighbor;
	char map1[ROW][COL] = 	
							{"                                                                                               ",
							"                           #                  #              ###   ###                         ",
							"                         # #                 # #                                               ",
							"               ##      ##            ##       #            #    # #    #                       ",
							"              #   #    ##            ##                    #    # #    #                       ",
							"   ##        #     #   ##                                  #    # #    #                       ",
							"   ##        #   # ##    # #                                 ###   ###                         ",
							"             #     #       #                                                                   ",
							"              #   #                                          ###   ###                         ",
							"               ##                                          #    # #    #                       ",
							"                                                           #    # #    #                       ",
							"                                                           #    # #    #                       ",
							"      ##                                                                                       ",
							"     #  #                                                    ###   ###                         ",
							"      # #                                                                                      ",
							"       #                                                                                       ",
							"                                                                                               ",
							"                                                                                               ",
							"   ###      #                                                              ##                  ",
							"            #                                               ###            # #                 ",
							"            #                                              ###               #                 ",
							"                                                                             # #               ",
							"        ###   ###                                                             ##               ",
							"                                       ##                                                      ",
							"            #                          # #                                                     ",
							"            #                            #                                                     ",
							"            #                            ##                           ##                       ",
							"                                                                      ##                       ",
							"                                                                        ##                     ",
							"                                                                        ##                     ",
							"                                                                                               ",
							"                                                                                               ",
							"                                                                                               ",
							"                                                                                               ",
							"                                                                                               "};
							
							/*	
							{"                                                                                               ",
							"                           #                  #              ###   ###                         ",
							"                         # #                 # #                                               ",
							"               ##      ##            ##       #            #    # #    #                       ",
							"              #   #    ##            ##                    #    # #    #                       ",
							"   ##        #     #   ##                                  #    # #    #                       ",
							"   ##        #   # ##    # #                                 ###   ###                         ",
							"             #     #       #                                                                   ",
							"              #   #                                          ###   ###                         ",
							"               ##                                          #    # #    #                       ",
							"                                                           #    # #    #                       ",
							"                                                           #    # #    #                       ",
							"      ##                                                                                       ",
							"     #  #                                                    ###   ###                         ",
							"      # #                                                                                      ",
							"       #                                                                                       ",
							"                                                                                               ",
							"                                                                                               ",
							"   ###      #                                                                                  ",
							"            #                                                                                  ",
							"            #                                                                                  ",
							"                                                                                               ",
							"        ###   ###                                                                              ",
							"                                       ##                                                      ",
							"            #                          # #                                                     ",
							"            #                            #                                                     ",
							"            #                            ##                                                    ",
							"                                                                                               ",
							"                                                                              ##               ",
							"                                                                             ##                ",
							"                                                                              #                ",
							"                                                                                               ",
							"                                                                                               ",
							"                                                                                               ",
							"                                                                                               "};
							*/
	char map2[ROW][COL];
	for(i = 0; i <= ROW - 1; i++)
	{
		for(j = 0; j <= COL - 2; j++)
			map2[i][j] = ' ';
	}
	
	system("color 2");
    printf("\e[?25l");      //hide cursor
    Sleep(SLEEP * 10);
    system("cls");

	for (i = 0; i <= ROW - 1; i++)
		puts(map1[i]);
	Sleep(SLEEP);
	while (!kbhit())
	{
		for (i = 0; i <= ROW - 1; i++)
		{
			for (j = 0; j <= COL - 2; j++)
			{
				if (map1[i][j] == '#')
					neighbor = -1;
				else
					neighbor = 0;
				
				for (k = i - 1; k <= i + 1 && k <= ROW - 1; k++)
				{
					if (k < 0)
						continue;
					for (l = j - 1; l <= j + 1 && l <= COL - 2; l++)
					{
						if (l < 0)
							continue;
						if (map1[k][l] == '#')
							neighbor++;
					}
				}
				if ((neighbor == 2 || neighbor == 3) && map1[i][j] == '#')
					map2[i][j] = '#';
				else if (neighbor == 3 && map1[i][j] == ' ')
					map2[i][j] = '#';
				else if(map1[i][j] == 'o')
					map2[i][j] = 'o';
				else
					map2[i][j] = ' ';
			}
		}
		refresh();
		for (i = 0; i <= ROW - 1; i++)
			puts(map2[i]);
		Sleep(SLEEP);
		
		
		for (i = 0; i <= ROW - 1; i++)
		{
			for (j = 0; j <= COL - 2; j++)
			{
				if (map2[i][j] == '#')
					neighbor = -1;
				else
					neighbor = 0;
				
				for (k = i - 1; k <= i + 1 && k <= ROW - 1; k++)
				{
					if (k < 0)
						continue;
					for (l = j - 1; l <= j + 1 && l <= COL - 2; l++)
					{
						if (l < 0)
							continue;
						if (map2[k][l] == '#')
							neighbor++;
					}
				}
				if ((neighbor == 2 || neighbor == 3) && map2[i][j] == '#')
					map1[i][j] = '#';
				else if (neighbor == 3 && map2[i][j] == ' ')
					map1[i][j] = '#';
				else if(map2[i][j] == 'o')
					map1[i][j] = 'o';
				else
					map1[i][j] = ' ';
			}
		}
		refresh();
		for (i = 0; i <= ROW - 1; i++)
			puts(map1[i]);
		Sleep(SLEEP);	
	}
	return 0;
}
