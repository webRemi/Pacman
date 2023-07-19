#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

void drawWalls()
{
    int wallx = 0;
    int wally = 0;

    // Initialize color pairs
    init_color(COLOR_BLACK, 0, 0, 0);
    char walls[] = { 
                    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '\n',
                    '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', '\n', 
                    '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '-', '-', '-', '-', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '*', '*', 'o', '_', '_', '_', '_', '_', '̈́*', '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', '*', '_', '_', '_', '_', '_', 'o', '*', '*', '_', '_', '*', '̈́*', '\n',
                    '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '\n',
                    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '\n',
                    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '\n',
                    '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', 'o', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', 'o', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '*', '_', '_', '*', '*', '_', '_', '*', '*', '*', '*', '_', '_', '*', '*', '\n',
                    '*', '*', '_', '_', '_', 'o', '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', '*', '*', '*', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '*', '*', '*', '*', '*', '_', '_', '_', '_', '_', '_', '*', '*', 'o', '_', '_', '_', '*', '*', '\n',
                    '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '\n',
                    };

    attron(COLOR_PAIR(3));
    

    for (int i = 0; i < sizeof(walls); i++)
    {
        if (walls[i] == '\n')
        {
            wally++;
            wallx = 0;
        }
        else if (walls[i] == '*')
        {
            attron(COLOR_PAIR(3));
            mvaddch(wally, wallx, walls[i]);
            wallx++;
            attroff(COLOR_PAIR(3));
        }
        else if (walls[i] == '_')
        {
            attron(COLOR_PAIR(5));
            mvaddch(wally, wallx, walls[i]);
            wallx++;
            attroff(COLOR_PAIR(5));
        }
        else if (walls[i] == '-')
        {
            attron(COLOR_PAIR(4));
            mvaddch(wally, wallx, walls[i]);
            wallx++;
            attroff(COLOR_PAIR(4));
        }
        else if (walls[i] == 'o')
        {
            attron(COLOR_PAIR(2));
            mvaddch(wally, wallx, walls[i]);
            wallx++;
            attroff(COLOR_PAIR(2));
        }
    }
    refresh();
    
}


void greetings()
{
    // bold text
    attron(A_BOLD);
    // print greeting message
    printw("\n\t\t\tWelcome to the Pacman game!!!");
    attroff(A_BOLD);
    refresh();
}

void movePacman()
{
    int locations[18][80] = {
                            {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                            {'0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0'}, 
                            {'0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '-', '-', '-', '-', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', 'o', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1', 'o', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0'},
                            {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                            {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                            {'0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', 'o', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', 'o', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '0', '0', '1', '1', '0', '0'},
                            {'0', '0', '1', '1', '1', 'o', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '0', '0', 'o', '1', '1', '1', '0', '0'},
                            {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                            };

    // color blue
    attron(COLOR_PAIR(2));
    // balance teminal to rare mode
    cbreak();
    // remove echos
    noecho();
    // take input from keyboard
    keypad(stdscr, TRUE);
    // initilize lines and colonnes
    int x = 3;
    int y = 5;
    int check;
    // initialize key
    int key;
    // set shape for cursor (0, 1, 2)
    curs_set(0);
    while (1)
    {   
        // mv pacman to position updated
        mvaddch(y, x, '<');
        // refresh screen to view updates
        refresh();
        
        // take user input (for arrow keys)
        key = getch();
        // check position where pacman need to move
        switch(key)
        {
            case KEY_UP:
                while(locations[y - 1][x])
                {
                    mvaddch(y, x, '<');
                    refresh();
                    napms(100);
                    mvaddch(y, x, ' ');
                    y--;
                    refresh();
                    printw("%d", locations[y][x]);
                    refresh();
                }
                break;

            case KEY_RIGHT:
                while(locations[y][x + 1] != 0)
                {
                    mvaddch(y, x, '<');
                    refresh();
                    napms(100);
                    mvaddch(y, x, ' ');
                    x++;
                    refresh();
                    printw("%d", locations[y][x]);
                }
                break;

            case KEY_DOWN:
                while (locations[y + 1][x] != 0)
                {
                    mvaddch(y, x, '<');
                    refresh();
                    napms(100);
                    mvaddch(y, x, ' ');
                    y++;
                    refresh();
                }
                break;

            case KEY_LEFT:
                while (locations[y][x - 1] != 0)
                {
                    mvaddch(y, x, '<');
                    refresh();
                    napms(100);
                    mvaddch(y, x, ' ');
                    x--;
                    refresh();
                }
                break;
        }
        
    }
    attroff(COLOR_PAIR(2));
}

void callMonsters(int x)
{
    srand(time(NULL));

    // initialize random x
    int randomX = rand() % 10;
    // initialize random y
    int randomY = rand() % 10;

    // array for monsters
    char monsters[5] = {'o', 'a', 'b', 'c', 'd'};
    // call monster in random position
    mvaddch(randomX, randomY, monsters[x]);
    refresh();
}

int main()
{
    initscr();

    //color declaration
    start_color();
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);

    //game steps
    drawWalls();
    movePacman();
    endwin();
    return 0;
}