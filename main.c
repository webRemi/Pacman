#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

void drawWalls()
{
    WINDOW *walls;
    
    initscr();
    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    // create window all screen
    walls = subwin(stdscr, LINES / 2, COLS, LINES/2, 0);
    // generate borders
    box(walls, ACS_VLINE, ACS_HLINE);
    // refresh walls
    wrefresh(walls);
    attroff(COLOR_PAIR(1));
}     

void drawInternWalls()
{
    int y = 5;
    int x = 1;
    initscr();
    start_color();
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    attron(COLOR_PAIR(3));
    while (x < 10)
    {
        mvaddch(y, x ++, ' ');
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
    int x = 1;
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
    drawInternWalls();
    greetings();
    movePacman();
    
    endwin();
    return 0;
}