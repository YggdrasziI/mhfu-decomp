/* Message structures sent through func_088A5B50 / func_088A5EF8 by the functions
 * of 0x088A6BA0-0x088A6FEC, and the byte-wise clear they inline. Layout from the
 * code; names are descriptive, not the original ones. The 0x1C-byte record is
 * copied as a 16-byte and a 12-byte part (two groups of float registers), so it
 * is written as two members. */

#ifndef UNK_MSG_H
#define UNK_MSG_H

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef union {
    struct {
        u16 flags;
        u8 unk2;
        u8 unk3;
        s8 a;
        u8 unk5;
        s8 b;
        s8 c;
        s16 unk8;
        s16 unkA;
        s16 unkC;
        s16 unkE;
    } f;
    s32 w[4];
} RA;

typedef struct {
    s32 w[3];
} RB;

typedef struct {
    RA h;
    RB t;
} R;typedef struct {
    s32 type;
    s32 unk4;
    s32 v[6];
} M20;

typedef struct {
    s32 type;
    s32 unk4;
    R r;
} M24;

typedef struct {
    s32 type;
    s32 unk4;
    R a;
    R b;
} M40;

static inline void clear(char *q, u32 n) {
    if (q != 0) {
        do {
            *q = 0;
            n--;
            q++;
        } while (n != 0);
    }
}

#endif
