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

#define PCI_CTRL 0x20
#define PCI_DATA (PCI_CTRL + 1)

#define PCI_SLAVE_CTRL 0xA0
#define PCI_SLAVE_DATA (PCI_SLAVE_CTRL + 1)
#define IGT_ENTRIES 256
interrupt_gate igt[IGT_ENTRIES];
typedef struct
{
    u16 limit;
    u32 base;
} __attribute__((packed)) interrupt_descriptor;

#endif