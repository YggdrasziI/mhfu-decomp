/* unit_088D61CC: 0x088D61CC-0x088D6388 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D6108 and unit_088D6388.
 *
 * Copies the three words and the two 16-bit values at D_08A62C68 to +0x480
 * (and the words again to +0x48C), masks or clears them by the result of
 * func_08830F74 and the flags at +0x614, and counts at +0x61C the calls
 * with bit 0x100 set in the first word (reset by the same bit of the
 * second).
 *
 * C++: bool conversions.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern "C" {

extern s32 D_08A62C68;
extern s32 D_08A62C6C;
extern s32 D_08A62C70;
extern u16 D_08A62C78;
extern u16 D_08A62C7A;
extern char *D_089CBBEC;

extern s32 func_08830F74(char *);

#define W(o) (*(s32 *)(arg0 + (o)))

void func_088D61CC(char *arg0) {
    s32 flags;

    W(0x480) = D_08A62C68;
    W(0x484) = D_08A62C6C;
    W(0x488) = D_08A62C70;
    *(u16 *)(arg0 + 0x49C) = D_08A62C78;
    *(u16 *)(arg0 + 0x49E) = D_08A62C7A;
    W(0x48C) = D_08A62C68;
    W(0x490) = D_08A62C6C;
    W(0x494) = D_08A62C70;
    if ((u8) func_08830F74(D_089CBBEC) == 0 && (bool) ((flags = W(0x614)) & 2) == 0 && (bool) (flags & 0x200) == 0) {
        if ((bool) (flags & 1) == 1) {
            W(0x480) &= 0xF00200;
            W(0x484) &= 0xF00000;
            W(0x488) &= 0xF00000;
        }
    } else {
        if ((u8) func_08830F74(D_089CBBEC) == 1) {
            W(0x480) &= 0xF00100;
            W(0x484) &= 0xF00100;
            W(0x488) &= 0xF00100;
        } else {
            W(0x480) = 0;
            W(0x484) = 0;
            W(0x488) = 0;
        }
        W(0x48C) = 0;
        W(0x490) = 0;
        W(0x494) = 0;
        W(0x498) = 0;
    }
    if (W(0x484) & 0x100) {
        W(0x61C) = 0;
    } else if (W(0x480) & 0x100) {
        W(0x61C)++;
    }
    if (*(s32 *)(D_089CBBEC + 0x528) & 0x20) {
        W(0x484) &= ~1;
    }
}

}
