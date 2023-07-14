#include <ncurses.h>

int main()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    int x = 0;
    int y = 0;
    int key;
    
    while (1)
    {
        mvaddch(y, x, '<');
        refresh();
        key = getch();
        switch(key)
        {
            case KEY_UP:
            y--;
            break;
            
            case KEY_RIGHT:
            x++;
            break;

            case KEY_DOWN:
            y++;
            break;

            case KEY_LEFT:
            x--;
            break;
        }
    }

    endwin();

    return 0;
}
