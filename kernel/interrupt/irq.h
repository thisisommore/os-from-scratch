#ifndef IRQ_H
#define IRQ_H
#include "../types.h"

#define PCI_SLAVE_CTRL 0xA0
#define PCI_SLAVE_DATA (PCI_SLAVE_CTRL + 1)
#define PCI_CTRL 0x20
#define PCI_DATA (PCI_CTRL + 1)

void irq_init();
extern void irq0(), irq1(), irq2(), irq3(), irq4(), irq5(), irq6(), irq7(), irq8(),
    irq9(), irq10(), irq11(), irq12(), irq13(), irq14(), irq15();
typedef (*irq_individual_handle)(irq_handler_register);
irq_individual_handle irq_h[256];
typedef struct
{
    u32 ds;
    u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
    u32 int_no;
    u32 eip, cs, eflags, useresp, ss;
} irq_handler_register;

#endif