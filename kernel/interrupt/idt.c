#include "idt.h"
#include "isr.h"
void idt_init()
{
    set_idt_entry(0, isr0);
    set_idt_entry(1, isr1);
    set_idt_entry(2, isr2);
    set_idt_entry(3, isr3);
    set_idt_entry(4, isr4);
    set_idt_entry(5, isr5);
    set_idt_entry(6, isr6);
    set_idt_entry(7, isr7);
    set_idt_entry(8, isr8);
    set_idt_entry(9, isr9);
    set_idt_entry(10, isr10);
    set_idt_entry(11, isr11);
    set_idt_entry(12, isr12);
    set_idt_entry(13, isr13);
    set_idt_entry(14, isr14);
    set_idt_entry(15, isr15);
    set_idt_entry(16, isr16);
    set_idt_entry(17, isr17);
    set_idt_entry(18, isr18);
    set_idt_entry(19, isr19);
    set_idt_entry(20, isr20);
    set_idt_entry(21, isr21);
    set_idt_entry(22, isr22);
    set_idt_entry(23, isr23);
    set_idt_entry(24, isr24);
    set_idt_entry(25, isr25);
    set_idt_entry(26, isr26);
    set_idt_entry(27, isr27);
    set_idt_entry(28, isr28);
    set_idt_entry(29, isr29);
    set_idt_entry(30, isr30);
    set_idt_entry(31, isr31);
    idtd_int();
}

void set_idt_entry(int n, u32 handler)
{
    igt[n].low_offset = handler & 0xffff;
    igt[n].kernel_seg = KERNEL_SEG;
    igt[n].always0 = 0;
    igt[n].flags = 0x8E;
    igt[n]
        .high_offset = (handler >> 16) & 0xffff;
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