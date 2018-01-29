
#include "kenkou_keyboard_monitor.h"
#include "kenkou_triple_tap.h"
#include <curses.h>
#include <time.h>



/**
 * Initializer for ncurses with user instructions
 */
void initKenkouKeyboardMonitor(void){

    initscr();
    cbreak();
    noecho();
    scrollok(stdscr, TRUE);

    printw("Press any key to trigger a tap!\n");
    printw("Press <CTRL + C> to quit.\n\n");
    printw("A triple tap will be triggered \n"\
           "when the two most recent ones \n"\
           "are within %u ms of each other\n",TRIPLE_TAP_MAX_DELAY);

}

/**
 * Blocking keyboard logger to capture keypresses as taps.
 *
 * Processes the timestamp at the time of a keypress.
 */
void kenkouKeyboardMonitor(void){

    struct timespec time;

    getch();
    clock_gettime(CLOCK_MONOTONIC, &time); // Unix friendly, not available on windows

    uint32_t ms = time.tv_nsec / 1000000;

    if(checkTripleTap(TRIPLE_TAP_CHANNEL, time.tv_sec, ms))
    {
        printw("Triple tap at %10u.%03us\n", time.tv_sec, ms);
    }
    else {
        printw("Tap at        %10u.%03us\n", time.tv_sec, ms);
    }


}

