#ifndef KENKOU__TRIPLE_TAP__H
#define KENKOU__TRIPLE_TAP__H

#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#define KENKOU__TRIPLE_TAP_CHANNELS 10
#define TRIPLE_TAP_MAX_DELAY 1000
#define TRIPLE_TAP_MAX_DUR   (TRIPLE_TAP_MAX_DELAY * 2) + 100


bool checkTripleTap(uint8_t channel
        , time_t epochTime
        , uint16_t additionalMillis);
#endif
