#include <ncurses.h>

int main()
{
    initscr();
    int x = 0;
    int y = 0;
    
    while (1)
    {
        //clear();
        mvaddch(y, x, '<');
        refresh();
        /* if (getch() != 410)
            break; */
        y++;
        x++;
    }

    endwin();

    return 0;
}
