#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

void drawWalls()
{
    int y = 5;
    int x = 1;
    initscr();
    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(3));
    while (x < 77)
    {
        mvaddch(y, x++, ' ');
    }
    while (y < 22)
    {
        mvaddch(y, x++, ' ');
        mvaddch(y++, x, ' ');
        mvaddch(y, x--, ' ');
    }
    while (x > 1)
    {
        mvaddch(y, x--, ' ');
    }
    while (y > 5)
    {
        mvaddch(y--, x, ' ');
        mvaddch(y, x++, ' ');
        mvaddch(y, x--, ' ');
        
    }
    refresh();
    attroff(COLOR_PAIR(3));
}

void drawInternalWalls()
{
    int floor1y = 6;
    int floor1x = 38;
    int floor2y = 7;
    int floor2x = 4;
    int floor3y = 8;
    int floor3x = 5;
    int floor4y = 9;
    int floor4x = 5;
    
    initscr();
    start_color();
    attron(COLOR_PAIR(3));
    // floor 1
    mvaddch(floor1y, floor1x, ' ');
    floor1x++;
    mvaddch(floor1y, floor1x, ' ');
    floor1x++;
    mvaddch(floor1y, floor1x, ' ');
    floor1x++;
    mvaddch(floor1y, floor1x, ' ');
    // floor2
    while (floor2x < 74)
    {
        if (floor2x == 8 || floor2x == 15 || floor2x == 29 || floor2x == 35 || floor2x == 41 || floor2x == 47 || floor2x == 61 || floor2x == 68 || floor2x == 74)
        {
            floor2x += 2;
            continue;
        }
        mvaddch(floor2y, ++floor2x, ' ');
    }
    // floor3
    mvaddch(floor3y, floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 12;
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, floor3x += 3, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 21;
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 55;
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 59;
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 63;
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 72;
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    refresh();

    // floor4
    attroff(COLOR_PAIR(3));
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
    // initialize screen
    initscr();
    start_color();
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    attron(COLOR_PAIR(2));
    // balance teminal to rare mode
    cbreak();
    // remove echos
    noecho();
    // take input from keyboard
    keypad(stdscr, TRUE);
    // initilize lines and colonnes
    int x = 3;
    int y = 14;
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
            // update position with blank value (to hide old position)
            mvaddch(y, x, ' ');
            refresh();
            y--;
            break;

            case KEY_RIGHT:
            mvaddch(y, x, ' ');
            x += 2;
            break;

            case KEY_DOWN:
            mvaddch(y, x, ' ');
            y++;
            break;

            case KEY_LEFT:
            mvaddch(y, x, ' ');
            x -= 2;
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
    drawWalls();
    drawInternalWalls();
    movePacman();
    endwin();
    return 0;
}