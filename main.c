#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

void drawWalls()
{
    int y = 5;
    int x = 1;
    init_color(COLOR_BLACK, 0, 0, 0);
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
    int floor1x = 37;
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
    int floor8y = 13;
    int floor8x = 4;
    int floor9y = 14;
    int floor9x = 4;
    int floor10y = 15;
    int floor10x = 4;
    int floor11y = 16;
    int floor11x = 17;
    int floor12y = 17;
    int floor12x = 2;
    int floor13y = 18;
    int floor13x = 2;
    int floor14y = 19;
    int floor14x = 10;
    int floor15y = 20;
    int floor15x = 4;
    int floor16y = 21;
    int floor16x = 6;

    attron(COLOR_PAIR(3));
    //floor 1
    while (floor1x < 41)
    {
        mvaddch(floor1y, ++floor1x, ' ');
    }
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
    while (floor3x < 74)
    {
        if (floor3x == 6 || floor3x == 15 || floor3x == 19 || floor3x == 23 || floor3x == 57 || floor3x == 61 || floor3x == 66)
        {
            if (floor3x == 6 || floor3x == 66)
            {
                floor3x += 4;
            }
            else if (floor3x == 23)
            {
                floor3x += 30;
            }
            floor3x += 2;
            continue;
        }
        mvaddch(floor3y, ++floor3x, ' ');
    }

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
    while (floor5x < 70)
    {
        if (floor5x == 10 || floor5x == 15 || floor5x == 19 || floor5x == 23 || floor5x == 27 || floor5x == 49  || floor5x == 53 || floor5x == 57 || floor5x == 61 || floor5x == 66)
        {
            if (floor5x == 27)
            {
                floor5x += 22;
            }
            floor5x += 2;
            continue;
        }
        mvaddch(floor5y, ++floor5x, ' ');
    }

    //floor6
    while (floor6x < 74)
    {
        if (floor6x == 10 || floor6x == 15 || floor6x == 19 || floor6x == 23 || floor6x == 27 || floor6x == 31 || floor6x == 37 || floor6x == 45 || floor6x == 49 || floor6x == 53 || floor6x == 57 || floor6x == 61 || floor6x == 66)
        {
            if (floor6x == 37)
            {
                attroff(COLOR_PAIR(3));
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
            if (floor7x == 6 || floor7x == 15 || floor7x == 57 || floor7x == 66)
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

    //floor8
    while (floor8x < 74)
    {
        if (floor8x == 10 || floor8x == 15 || floor8x == 19 || floor8x == 23 || floor8x == 27 || floor8x == 31 || floor8x == 35 || floor8x == 41 || floor8x == 45 || floor8x == 49 || floor8x == 53 || floor8x == 57 || floor8x == 61 || floor8x == 66)
        {
            if (floor8x == 35)
            {
                floor8x += 6;
            }
            floor8x += 2;
            continue;
        }
        mvaddch(floor8y, ++floor8x, ' ');
    }

    //floor9
    while (floor9x < 74)
    {
        if (floor9x == 10 || floor9x == 15 || floor9x == 19 || floor9x == 23 || floor9x == 27 || floor9x == 31 || floor9x == 45 || floor9x == 49 || floor9x == 53 || floor9x == 57 || floor9x == 61 || floor9x == 66)
        {
            floor9x += 2;
            continue;
        }
        mvaddch(floor9y, ++floor9x, ' ');
    }

    //floor10
    while (floor10x < 74)
    {
        if (floor10x == 10 || floor10x == 15 || floor10x == 19 || floor10x == 23 || floor10x == 27 || floor10x == 31 || floor10x == 45 || floor10x == 49 || floor10x == 53 || floor10x == 57 || floor10x == 61 || floor10x == 66)
        {
            if (floor10x == 27)
            {
                floor10x += 20;
            }
            floor10x += 2;
            continue;
        }
        mvaddch(floor10y, ++floor10x, ' ');
    }

    //floor11
    while (floor11x < 74)
    {
        if (floor11x == 10 || floor11x == 15 || floor11x == 19 || floor11x == 23 || floor11x == 31 || floor11x == 45 || floor11x == 53 || floor11x == 57 || floor11x == 61)
        {
            if (floor11x == 61)
            {
                floor11x += 12;
            }
            floor11x += 2;
            continue;
        }
        mvaddch(floor11y, ++floor11x, ' ');
    }

    //floor12
    while (floor12x < 76)
    {
        if (floor12x == 12 || floor12x == 19 || floor12x == 23 || floor12x == 57 || floor12x == 64)
        {
            if (floor12x == 23)
            {
                floor12x += 30;
            }
            floor12x += 2;
            continue;
        }
        mvaddch(floor12y, ++floor12x, ' ');
    }

    //floor13
    while (floor13x < 76)
    {
        if (floor13x == 12 || floor13x == 19 || floor13x == 23 || floor13x == 31 || floor13x == 45 || floor13x == 53 || floor13x == 57 || floor13x == 64)
        {
            floor13x += 2;
            continue;
        }
        mvaddch(floor13y, ++floor13x, ' ');
    }

    //floor14
    while (floor14x < 68)
    {
        if (floor14x == 12 || floor14x == 19 || floor14x == 23 || floor14x == 27 || floor14x == 36 || floor14x == 41 || floor14x == 48 || floor14x == 53 || floor14x == 57 || floor14x == 64)
        {
            if (floor14x == 27 || floor14x == 41)
            {
                floor14x += 8;
            }
            floor14x += 2;
            continue;
        }
        mvaddch(floor14y, ++floor14x, ' ');
    }

    //floor15
    while (floor15x < 74)
    {
        if (floor15x == 8 || floor15x == 12 || floor15x == 19 || floor15x == 23 || floor15x == 35 || floor15x == 41 || floor15x == 53 || floor15x == 57 || floor15x == 64 || floor15x == 68)
        {
            floor15x += 2;
            continue;
        }
        mvaddch(floor15y, ++floor15x, ' ');
    }

    //floor16
    while (floor16x < 72)
    {
        if (floor16x == 8 || floor16x == 19 || floor16x == 64 || floor16x == 68)
        {
            if (floor16x == 8 || floor16x == 64 || floor16x == 68)
            {
                floor16x += 4;
            }
            else if (floor16x == 19)
            {
                floor16x += 38;
            }
            floor16x += 2;
            continue;
        }
        mvaddch(floor16y, ++floor16x, ' ');
    }
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
                while (y != 6)
                {
                    mvaddch(y, x, '<');
                    refresh();
                    napms(100);
                    mvaddch(y, x, ' ');
                    y--;
                    refresh();
                }
                break;

            case KEY_RIGHT:
                while (x != 76)
                {
                    mvaddch(y, x, '<');
                    refresh();
                    napms(100);
                    mvaddch(y, x, ' ');
                    x++;
                    refresh();
                }
                break;

            case KEY_DOWN:
                while (y != 21)
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
                while (x != 3)
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

    //game steps
    drawWalls();
    drawInternalWalls();
    movePacman();
    endwin();
    return 0;
}