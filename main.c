#include <ncurses.h>

void drawWalls()
{
    printw(" ______________________\n|  __________________  |\n| |                  | |\n| |                  | |\n| |                  | |\n| |                  | |\n| |                  | |\n| |                  | |\n| |                  | |\n| |__________________| |\n|______________________|\n");
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
            x++;
            break;

            case KEY_DOWN:
            mvaddch(y, x, ' ');
            y++;
            break;

            case KEY_LEFT:
            mvaddch(y, x, ' ');
            x--;
            break;
        }
    }
    // restore terminal
    endwin();
}

int main()
{
    movePacman();
}