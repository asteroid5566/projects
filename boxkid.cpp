#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

int ROW = 7, i, target[4][2] = {{4, 2}, {4, 3}, {5, 2}, {5, 3}};    //目標位置(y, x)

void refresh(string s[])
{
    COORD point;
    point.X = point.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);   //游標回到最上方����

	for (i = 0; i < 4; i++) {                           //重新顯示被玩家蓋住的 *
		if (s[target[i][0]][target[i][1]] == ' ')
			s[target[i][0]][target[i][1]] = '*';
	}
    cout << "\n    press r to restart\n\n";
    for (i = 0; i < ROW; i++)
		cout << "    " << s[i] << "\n";
}

int main()
{
	restart:
	string s[ROW] = {"##########",
					 "##     ###",
					 "##o###   #",
					 "# & o  o #",
					 "# **# o ##",
					 "##**#   ##",
					 "##########"};
    int y = 3, x = 2, success = 0;   //成功數量
	char k;
	system("cls");
	printf("\e[?25l");  			//隱藏游標
	refresh(s);
	
	while (success < 4) {
		k = getch();
		if (k == 'w' || k == 'W') {     		//向上
			if (s[y - 1][x] == ' ') {
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			else if (s[y - 1][x] == 'o' && s[y - 2][x] == ' ') {
    			s[y - 2][x] = 'o';
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			else if (s[y - 1][x] == 'o' && s[y - 2][x] == '*') {
				success++;
				s[y - 2][x] = '@';
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			else if (s[y - 1][x] == '@' && s[y - 2][x] == '*') {
				s[y - 2][x] = '@';
				s[y - 1][x] = '&';
				s[y--][x] = ' ';
			}
			refresh(s);
		}
		else if (k == 'a' || k =='A') {     		//向左
			if (s[y][x - 1] == ' ') {
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			else if (s[y][x - 1] == 'o' && s[y][x - 2] == ' ') {
    			s[y][x - 2] = 'o';
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			else if (s[y][x - 1] == 'o' && s[y][x - 2] == '*') {
				success++;
				s[y][x - 2] = '@';
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			else if (s[y][x - 1] == '@' && s[y][x - 2] == '*') {
				s[y][x - 2] = '@';
				s[y][x - 1] = '&';
				s[y][x--] = ' ';
			}
			refresh(s);
		}
		else if (k == 's' || k == 'S') {     		//向下
			if (s[y + 1][x] == ' ') {
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			else if (s[y + 1][x] == 'o' && s[y + 2][x] == ' ') {
    			s[y + 2][x] = 'o';
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			else if (s[y + 1][x] == 'o' && s[y + 2][x] == '*') {
				success++;
				s[y + 2][x] = '@';
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			else if (s[y + 1][x] == '@' && s[y + 2][x] == '*') {
				s[y + 2][x] = '@';
				s[y + 1][x] = '&';
				s[y++][x] = ' ';
			}
			refresh(s);
		}
		else if (k == 'd' || k == 'D') {     		//向右
			if (s[y][x + 1] == ' ') {
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			else if (s[y][x + 1] == 'o' && s[y][x + 2] == ' ') {
    			s[y][x + 2] = 'o';
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			else if (s[y][x + 1] == 'o' && s[y][x + 2] == '*') {
				success++;
				s[y][x + 2] = '@';
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			else if (s[y][x + 1] == '@' && s[y][x + 2] == '*') {
				s[y][x + 2] = '@';
				s[y][x + 1] = '&';
				s[y][x++] = ' ';
			}
			refresh(s);
		}
		else if (k == 'r' || k == 'R')
			goto restart;
	}
	cout << "\a\n\n     你贏了!\n\n\n\n";
	system("pause");
	return 0;
}
