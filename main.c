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
    int floor3x = 4;
    int floor4y = 9;
    int floor4x = 4;
    int floor5y = 10;
    int floor5x = 8;
    int floor6y = 11;
    int floor6x = 4;
    int floor7y = 12;
    int floor7x = 4;

    initscr();
    start_color();
    attron(COLOR_PAIR(3));
    //floor 1
    mvaddch(floor1y, floor1x, ' ');
    floor1x++;
    mvaddch(floor1y, floor1x, ' ');
    floor1x++;
    mvaddch(floor1y, floor1x, ' ');
    floor1x++;
    mvaddch(floor1y, floor1x, ' ');
    //floor2
    while (floor2x < 74)
    {
        if (floor2x == 8 || floor2x == 15 || floor2x == 29 || floor2x == 35 || floor2x == 41 || floor2x == 47 || floor2x == 61 || floor2x == 68 || floor2x == 74)
        {
            floor2x += 2;
            continue;
        }
        mvaddch(floor2y, ++floor2x, ' ');
    }
    //floor3
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 12;
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    mvaddch(floor3y, ++floor3x, ' ');
    floor3x = 17;
    mvaddch(floor3y, ++floor3x, ' ');
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

    //floor4
    while (floor4x < 74)
    {
        if (floor4x == 6 || floor4x == 10 || floor4x == 15 || floor4x == 19 || floor4x == 23 || floor4x == 31 || floor4x == 45 || floor4x == 53 || floor4x == 57 || floor4x == 61 || floor4x == 66 || floor4x == 70)
        {
            floor4x += 2;
            continue;
        }
        mvaddch(floor4y, ++floor4x, ' ');
    }
    
    //floor5
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 12;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 17;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 21;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 25;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 51;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 55;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 59;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 63;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');
    floor5x = 68;
    mvaddch(floor5y, ++floor5x, ' ');
    mvaddch(floor5y, ++floor5x, ' ');

    //floor6
    while (floor6x < 74)
    {
        if (floor6x == 10 || floor6x == 15 || floor6x == 19 || floor6x == 23 || floor6x == 27 || floor6x == 31 || floor6x == 37 || floor6x == 45 || floor6x == 49 || floor6x == 53 || floor6x == 57 || floor6x == 61 || floor6x == 66)
        {
            if (floor6x == 37)
            {
                attroff(COLOR_PAIR(3));
                init_pair(4, COLOR_RED, COLOR_BLACK);
                attron(COLOR_PAIR(4));
                floor6x += 2;
                mvaddch(floor6y, 38, '-');
                mvaddch(floor6y, 39, '-');
                mvaddch(floor6y, 40, '-');
                mvaddch(floor6y, 41, '-');
                attroff(COLOR_PAIR(4));
                attron(COLOR_PAIR(3));
            }
            floor6x += 2;
            continue;
        }
        mvaddch(floor6y, ++floor6x, ' ');
    }

    //floor7
    while (floor7x < 74)
    {
        if (floor7x == 6 || floor7x == 15 || floor7x == 23 || floor7x == 27 || floor7x == 31 || floor7x == 35 || floor7x == 45 || floor7x == 49 || floor7x == 53 | floor7x == 57 || floor7x == 61 || floor7x == 66)
        {
            if (floor7x == 6 || floor7x == 15 || floor7x == 66)
            {
                floor7x += 4;
            }
            else if (floor7x == 35)
            {
                floor7x += 6;
            }
            floor7x += 2;
            continue;
        }
        mvaddch(floor7y, ++floor7x, ' ');
    }

    refresh();
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