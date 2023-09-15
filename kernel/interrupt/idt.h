#ifndef IDT_H
#define IDT_H
#include "../types.h"
typedef struct
{
    u16 low_offset;
    u16 kernel_seg;
    u8 always0;
    u8 flags;
    u16 high_offset;
} __attribute__((packed)) interrupt_gate;

#define IGT_ENTRIES 256
interrupt_gate igt[IGT_ENTRIES];
typedef struct
{
    u16 limit;
    u32 base;
} __attribute__((packed)) interrupt_descriptor;

#endif