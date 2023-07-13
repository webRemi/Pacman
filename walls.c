#include <ncurses.h>

int main()
{
    WINDOW *wall;
    int size = strlen(wall);

    initscr();

    while(1)
    {
        clear();
        wall = subwin(stdscr, 10, 10, LINES / 2, COLS / 2);
        box(wall, ACS_VLINE, ACS_HLINE);
        refresh();
        if(getch() != 410)
            break;
    }

    endwin();

    free(wall);

    return 0;
}