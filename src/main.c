#include "kenkou_keyboard_monitor.h"

int  main(void){
    initKenkouKeyboardMonitor();
    for(;;){
        kenkouKeyboardMonitor();
    }
}
