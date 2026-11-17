/* unit_08877100: 0x08877100-0x088775F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_088765C0 and text_088775F0). Its jump table (0x089317FC-0x08931814)
 * is linked from this unit.
 *
 * Optimized for speed: the division by 10 is a multiplication. The first
 * parameter of func_0884FBA4 / func_0884FC0C is a pointer here: as s32 the
 * D_089CC438 load is scheduled before the D_08A62CB4 one.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A62CB4;
extern s32 D_08A62C6C;
extern s32 D_08A62D8C;
extern s32 D_09A4F0C4;

extern s32 func_088DCEBC(s32, u8);
extern s32 func_0884FB6C(s32);
extern s32 func_0884FBA4(char *, s32);
extern s32 func_0884FC0C(char *, s32);
extern void func_088854A0(s32, s32, s32);
extern int func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_08877100(char *arg0) {
    s32 old;
    s32 n;

    func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    if (*(s16 *)(arg0 + 0xAA) > 0) {
        (*(s16 *)(arg0 + 0xAA))--;
    }
    if (*(s16 *)(arg0 + 0xA4) >= 2) {
        old = *(s32 *)(arg0 + 0x20);
        n = (*(s32 *)(arg0 + 0x24) - 1) / 10 + 1;
        if ((u16) func_0884FB6C((s32) D_089CC438) & 0x80) {
            if (--*(s32 *)(arg0 + 0x20) < 0) {
                *(s32 *)(arg0 + 0x20) = n - 1;
            }
        } else if ((u16) func_0884FB6C((s32) D_089CC438) & 0x20) {
            if (++*(s32 *)(arg0 + 0x20) > n - 1) {
                *(s32 *)(arg0 + 0x20) = 0;
            }
        }
        if (old != *(s32 *)(arg0 + 0x20)) {
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        }
    }
    switch (*(s16 *)(arg0 + 0xA4)) {
    case 0:
        if (--*(s16 *)(arg0 + 0xA8) < 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
            func_08883988(D_08A62D8C, 0, 0x10, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 1:
        if (--*(s16 *)(arg0 + 0xA8) < 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
            func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 2:
        if (--*(s16 *)(arg0 + 0xA8) < 0) {
            if (--*(u8 *)(D_08A62CB4 + 0x1C) <= 0) {
                *(s16 *)(arg0 + 0xA4) = 7;
                func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            } else {
                (*(s16 *)(arg0 + 0xA4))++;
                func_08883988(D_08A62D8C, 0, 0x11, 0, 0, 0, 0, 0, 0);
            }
            *(s16 *)(arg0 + 0xA8) = 10;
        }
        break;
    case 3:
        if (--*(s16 *)(arg0 + 0xA8) < 0) {
            (*(s16 *)(arg0 + 0xA4))++;
            *(s16 *)(arg0 + 0xA8) = 10;
            *(s16 *)(arg0 + 0xAE) = 0;
        }
        break;
    case 4:
        if (*(s32 *)(D_08A62CB4 + 0x10) > 0 || *(s32 *)(D_08A62CB4 + 0x14) > 0) {
            if (*(s16 *)(arg0 + 0xAE) == 0) {
                *(s32 *)(arg0 + 0xC8) = func_08883988(D_08A62D8C, 0, 8, 0, 0, 0, 0, 0, 0);
                (*(s16 *)(arg0 + 0xAE))++;
            }
            if (D_08A62C6C & 0x4000) {
                func_0884FBA4(D_089CC438, *(s32 *)(D_08A62CB4 + 0x10));
                func_0884FC0C(D_089CC438, *(s32 *)(D_08A62CB4 + 0x14));
                *(s32 *)(D_08A62CB4 + 0x10) = 0;
                *(s32 *)(D_08A62CB4 + 0x14) = 0;
            } else {
                if (*(s32 *)(D_08A62CB4 + 0x10) > 0) {
                    (*(s32 *)(D_08A62CB4 + 0x10))--;
                    func_0884FBA4(D_089CC438, 1);
                }
                if (*(s32 *)(D_08A62CB4 + 0x14) > 0) {
                    func_0884FC0C(D_089CC438, 1);
                    (*(s32 *)(D_08A62CB4 + 0x14))--;
                }
            }
        } else {
            func_088854A0(D_08A62D8C, *(s32 *)(arg0 + 0xC8), 0);
            (*(s16 *)(arg0 + 0xA4))++;
            func_08883988(D_08A62D8C, 0, 0x19, 0, 0, 0, 0, 0, 0);
        }
        break;
    case 5:
        if (*(s16 *)(arg0 + 0xAA) <= 0 || ((u16) func_0884FB6C((s32) D_089CC438) & 0x4000)) {
            func_08883988(D_08A62D8C, 0, 0x13, 0, 0, 0, 0, 0, 0);
            return 1;
        }
        break;
    }
    return 0;
}
