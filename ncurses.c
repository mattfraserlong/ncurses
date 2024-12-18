#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <inttypes.h>

int stringToInt();

int main(void) {
    char mesg[] = "Enter a number: ";
    char *endptr;
    int int1;
    int int2;
    int ans;
    char str[80];
    int row, col;               

    initscr();                  /* start the curses mode */
    getmaxyx(stdscr, row, col); /* get the number of rows and columns */

    mvprintw(row / 2, (col - (int) strlen(mesg)) / 2, "%s", mesg); /* print the message in Screen centre*/
    
    getstr(str);   // take input as a string

    int1 = strtoimax(str, &endptr, 10); // turn inputted string into an int
    ans = int1 + 10;                    // add inputted int to 10                   
    
    mvprintw(row / 2, (col - (int) strlen(mesg)) / 2, "Your number + 10 = %d", ans);

    getch();   // wait for next input to end ncurses session
    endwin();   // end ncurses session

    return 0;
}