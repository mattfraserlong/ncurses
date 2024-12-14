#include <ncurses.h>

int main(void) {
    int int1;
    int int2;
    int ans;

    initscr();                  /* Start curses mode            */
    raw();                      /* Line buffering disabled      */
    keypad(stdscr, TRUE);       /* We get F1, F2 etc..          */
    noecho();                   /* Don't echo() while we do getch */

    printw("This program adds two numbers.\nType first number to add\n");
    //https://stackoverflow.com/questions/66981503/how-to-use-ncurses-to-take-integer-as-a-variable
    int1 = getch();               /* If raw() hadn't been called
                                 * we have to press enter before it
                                 * gets to the program          */
    printw("Your first number is %d: \n", int1);
    printw("Type second number to add\n");
    int2 = getch();
    ans = int1 + int2;
    printw("%i + %i = %i", int1, int2, ans);


    refresh();                  /* Print it on to the real screen */
    getch();                    /* Wait for user input */
    endwin();                   /* End curses mode                */

    return 0;
}