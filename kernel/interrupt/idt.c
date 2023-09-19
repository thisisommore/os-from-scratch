#include "idt.h"
#include "isr.h"
#include "irq.h"

void idt_init()
{
    isr_init();
    irq_init();
    idtd_int();
}

void set_idt_entry(int n, u32 handler)
{
    igt[n].low_offset = handler & 0xffff;
    igt[n].kernel_seg = KERNEL_SEG;
    igt[n].always0 = 0;
    igt[n].flags = 0x8E;
    igt[n]
        .high_offset = (handler >> 16);
}

void idtd_int()
{
    interrupt_descriptor idtp;
    idtp.base = &igt;
    idtp.limit = IGT_ENTRIES * sizeof(interrupt_gate) - 1;
    __asm__ __volatile__("lidtl (%0)"
                         :
                         : "r"(&idtp));
}