#ifndef __FRAMES_H__
#define __FRAMES_H__

#include <stdint.h>
#include "led_driver.h"

// Placeholder values
static const uint32_t RPM = 100; 
static const uint32_t GRID_WIDTH = 50; 
static const uint32_t GRID_HEIGHT = 144;

extern frame_t frame_grid[146][100];

inline uint32_t frame_read (uint8_t x, uint8_t y);
inline void frame_write (uint8_t x, uint8_t y, frame_t f);

#endif /* __FRAMES_H__ */