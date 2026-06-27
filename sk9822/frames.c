#include <stdint.h>
#include "led_driver.h"
#include "frames.h"

frame_t frame_grid[146][100] = 
{
    [0 ... 99] = frame_buffer
};

inline uint32_t
frame_read (uint8_t x, uint8_t y)
{
    return frame_grid[y][x];
}

inline void
frame_write (uint8_t x, uint8_t y, frame_t f)
{
    frame_grid[y][x] = f;
}

