#ifndef TYPES_H
#define TYPES_H
typedef char i8;
typedef unsigned char u8;
typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;

#define low_16(address) (u16)((address)&0xFFFF)
#define high_16(address) (u16)(((address) >> 16) & 0xFFFF)

#endif