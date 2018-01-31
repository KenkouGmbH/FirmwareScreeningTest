
#include "kenkou_keyboard_monitor.h"
#include "kenkou_triple_tap.h"

#include <time.h>
#include <stdint.h>
#include <stdio.h>



/**
 * Show the user instructions
 */
void printInstructions(void){

    printf("Press the ENTER key to trigger a tap!\n");
    printf("Press <CTRL + C> to quit.\n\n");
    printf("A triple tap will be triggered \n"\
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
    int ch;

    ch = getchar();

    if (ch != '\n') return;

    clock_gettime(CLOCK_MONOTONIC, &time); // Unix friendly, not available on windows

    uint32_t ms = time.tv_nsec / 1000000;

    if(checkTripleTap(TRIPLE_TAP_CHANNEL, time.tv_sec, ms))
    {
        printf("Triple tap at %10u.%03us\n", (uint32_t) time.tv_sec, ms);
    }
    else {
        printf("Tap at        %10u.%03us\n", (uint32_t) time.tv_sec, ms);
    }


}

