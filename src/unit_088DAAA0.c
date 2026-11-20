/* unit_088DAAA0: 0x088DAAA0-0x088DACA4 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088DAA98 and unit_088DACA4.
 *
 * func_088DAAA0 sets the 16-bit value at +0x60C from the first item's
 * record (0x18-byte records at 0x08959FD0, byte 5: 150 + 50 per unit),
 * moved by 50 within 150...450 by the states of func_088D6A1C.
 * func_088DAB94 counts the leading entries below `arg1` in a row of seven
 * 16-bit values (table of D_0897923C chosen by func_0885CCE8, row from
 * byte 4 of the record). func_088DAC58 tells whether the state pair at
 * +0x298 / +0x299 is one of three.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_08A62C54;
extern u8 D_08959FD4[];
extern u8 D_08959FD5[];
extern s16 *D_0897923C[];

extern s32 func_088D6A1C(char *, u8);
extern s32 func_0885CCE8(char *, char *);

void func_088DAAA0(char *arg0) {
    *(s16 *)(arg0 + 0x60C) = D_08959FD5[*(u16 *)(arg0 + 0x4EA) * 0x18] * 50 + 0x96;
    if ((u8) func_088D6A1C(arg0, 0x1D) == 1 || (u8) func_088D6A1C(arg0, 0xD1) == 1) {
        *(s16 *)(arg0 + 0x60C) += 0x32;
        if (*(s16 *)(arg0 + 0x60C) > 0x1C2) {
            *(s16 *)(arg0 + 0x60C) = 0x1C2;
        }
    } else if ((u8) func_088D6A1C(arg0, 0x1E) == 1) {
        *(s16 *)(arg0 + 0x60C) -= 0x32;
        if (*(s16 *)(arg0 + 0x60C) < 0x96) {
            *(s16 *)(arg0 + 0x60C) = 0x96;
        }
    }
}

u8 func_088DAB94(char *arg0, s16 arg1) {
    s16 *tbl;
    s16 *p;
    u8 i;

    if (*(u8 *)(arg0 + 0x4E9) != 5) {
        return 0;
    }
    tbl = D_0897923C[(u8) func_0885CCE8(D_08A62C54, arg0 + 0x4E8)];
    p = tbl + D_08959FD4[*(u16 *)(arg0 + 0x4EA) * 0x18] * 7;
    for (i = 0; i < 7; i++, p++) {
        if (*p >= arg1) {
            break;
        }
    }
    return i;
}

s32 func_088DAC58(char *arg0) {
    if (*(u8 *)(arg0 + 0x298) == 0
        && (*(u8 *)(arg0 + 0x299) == 0x11 || *(u8 *)(arg0 + 0x299) == 0x1B || *(u8 *)(arg0 + 0x299) == 0x3A)) {
        return 1;
    }
    return 0;
}
