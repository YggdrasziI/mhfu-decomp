/* unit_08829674: 0x08829674-0x0882981C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

extern char *D_08A62C7C;
extern char *D_089CC438;

extern s32 func_08872D74(char *, s32);
extern s8 func_0882981C(void);

u8 func_08829674(u8 *arg0) {
    s32 flags;
    s32 i;
    s8 r;

    arg0[0x5E6] = 0;
    flags = *(s32 *)(D_08A62C7C + 0x28);
    if (flags & 0x40000) {
        switch (*(u8 *)(D_089CC438 + 0x6AF10)) {
        case 1:
            arg0[0x584] = 3;
            break;
        case 12:
            arg0[0x584] = 4;
            break;
        default:
            arg0[0x584] = 6;
            break;
        }
    } else if (flags & 4) {
        arg0[0x584] = 0;
        if (*(s32 *)(D_08A62C7C + 0x28) & 0x200000) {
            arg0[0x5E6] |= 1;
        }
        if (*(s32 *)(D_08A62C7C + 0x28) & 0x400000) {
            arg0[0x5E6] |= 4;
        }
    } else if (flags & 1) {
        arg0[0x584] = 1;
        i = 0;
        do {
            if (func_08872D74(D_08A62C7C, i) == 3) {
                arg0[0x5E6] |= 2;
                break;
            }
            i++;
        } while (i < 2);
    } else if (flags & 2) {
        arg0[0x584] = 2;
    } else if (flags & 0x10) {
        arg0[0x584] = 5;
    } else {
        r = func_0882981C();
        if (r >= 0) {
            arg0[0x584] = 1;
            if (r == 1) {
                arg0[0x5E6] |= 2;
            }
        } else {
            arg0[0x584] = 6;
        }
    }
    return arg0[0x584];
}
