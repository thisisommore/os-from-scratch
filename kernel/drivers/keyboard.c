#include "../interrupt/irq.h"
#include "../interrupt/idt.h"
#include "ports.h"
#include "screen.h"
#include "../utils.h"
#include "keyboard.h"

#define KEYBOARD_DATA 0x60

char keyboard_buffer[100];
char *ky_p = keyboard_buffer;

void clear_k_buffer()
{
    while (keyboard_buffer != ky_p)
    {
        *ky_p = 0;
        ky_p--;
    }
}

void read_line(char *return_buffer)
{
    char *last_processed_token = keyboard_buffer;
    // ky_p-1 because it always points to next space in buffer available to place data (key)
    while (*(ky_p - 1) != '\n')
    {

        // ky_p changes quickly since that happens with interrupts, so better backup the pointer
        char *b_ky_p = ky_p;

        // this loop runs till ky_p has \n, so avoid processing duplicate charactors by storing last_processed_token
        if (b_ky_p - 1 != last_processed_token)
        {
            last_processed_token = b_ky_p - 1;
            if (*(b_ky_p - 1) == '\n')
                continue;
            print(b_ky_p - 1);
        }
    }

    char *head = keyboard_buffer;
    while (*head != '\n')
    {
        *(return_buffer++) = *(head++);
    }
    *(return_buffer++) = 0;
    clear_k_buffer();
}

void keyboard_handler(irq_handler_register r)
{
    u8 scancode = port_byte_in(KEYBOARD_DATA);
    // print("Keyboard inpput scan code - ");
    // println(int_to_assci(scancode));

    switch (scancode & 0xFF)
    {
    case SC_Q:
        *(ky_p++) = 'Q';
        break;
    case SC_W:
        *(ky_p++) = 'W';
        break;
    case SC_E:
        *(ky_p++) = 'E';
        break;
    case SC_R:
        *(ky_p++) = 'R';
        break;
    case SC_T:
        *(ky_p++) = 'T';
        break;
    case SC_Y:
        *(ky_p++) = 'Y';
        break;
    case SC_U:
        *(ky_p++) = 'U';
        break;
    case SC_I:
        *(ky_p++) = 'I';
        break;
    case SC_O:
        *(ky_p++) = 'O';
        break;
    case SC_P:
        *(ky_p++) = 'P';
        break;
    case SC_A:
        *(ky_p++) = 'A';
        break;
    case SC_S:
        *(ky_p++) = 'S';
        break;
    case SC_D:
        *(ky_p++) = 'D';
        break;
    case SC_F:
        *(ky_p++) = 'F';
        break;
    case SC_G:
        *(ky_p++) = 'G';
        break;
    case SC_H:
        *(ky_p++) = 'H';
        break;
    case SC_J:
        *(ky_p++) = 'J';
        break;
    case SC_K:
        *(ky_p++) = 'K';
        break;
    case SC_L:
        *(ky_p++) = 'L';
        break;
    case SC_Z:
        *(ky_p++) = 'Z';
        break;
    case SC_X:
        *(ky_p++) = 'X';
        break;
    case SC_C:
        *(ky_p++) = 'C';
        break;
    case SC_V:
        *(ky_p++) = 'V';
        break;
    case SC_B:
        *(ky_p++) = 'B';
        break;
    case SC_N:
        *(ky_p++) = 'N';
        break;
    case SC_M:
        *(ky_p++) = 'M';
        break;

    case SC_ENTER:
        *(ky_p++) = '\n';
        break;

    case SC_SPACE:
        *(ky_p++) = ' ';
        break;

    default:
        break;
    }
}

void init_keyboard()
{
    irq_h[33] = keyboard_handler;
}
