#ifndef ISR_H
#define ISR_H
#define KERNEL_SEG 0x08
#include "../types.h"

void isr_init();
extern void isr0(), isr1(), isr2(), isr3(), isr4(), isr5(), isr6(), isr7(), isr8(),
    isr9(), isr10(), isr11(), isr12(), isr13(), isr14(), isr15(), isr16(),
    isr17(), isr18(), isr19(), isr20(), isr21(), isr22(), isr23(), isr24(),
    isr25(), isr26(), isr27(), isr28(), isr29(), isr30(), isr31(), isr32();

char *exception_messages[] = {
    "Division By Zero",
    "Debug",
    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"};

typedef struct
{
    u32 ds;
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 int_no, err_code;
    u32 eip, cs, eflags, useresp, ss;
} isr_handler_register;

#endif