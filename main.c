#include <ncurses.h>

void drawWalls()
{
    WINDOW *walls;
    
    initscr();
    // create window all screen
    walls = subwin(stdscr, LINES, COLS, 0, 0);
    // generate borders
    box(walls, ACS_VLINE, ACS_HLINE);
    // refresh walls
    wrefresh(walls);
}     

void greetings()
{
    // print greeting message
    printw("Welcome to the Pacman game!!!");
    refresh();
}

void movePacman()
{
    // initialize screen
    initscr();
    // balance teminal to rare mode
    cbreak();
    // remove echos
    noecho();
    // take input from keyboard
    keypad(stdscr, TRUE);
    // initilize lines and colonnes
    int x = 0;
    int y = 0;
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
}

int main()
{
    initscr();
    drawWalls();
    greetings();
    movePacman();
    endwin();
    return 0;
}