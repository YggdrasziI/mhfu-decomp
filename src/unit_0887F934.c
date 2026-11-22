/* unit_0887F934: 0x0887F934-0x0887FAB4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_08A631A0;
extern char *D_089CC438;
extern u16 func_088900C4(char *, s32);

void func_0887F934(char *arg0, char *arg1) {
    s32 n;
    s16 v;
    s32 t;

    n = *(u16 *)(arg1 + 0x1A);
    if (n > 0) {
        v = (func_088900C4(D_08A631A0, 1) % n) * 8;
        if (func_088900C4(D_08A631A0, 1) & 1) {
            v *= -1;
        }
        *(s16 *)(arg0 + 0xC) += v;
    }
    if (*(u16 *)(arg1 + 0x1C) > 0) {
        v = func_088900C4(D_08A631A0, 1) % *(u16 *)(arg1 + 0x1C);
        if (func_088900C4(D_08A631A0, 1) & 1) {
            v *= -1;
        }
        *(s16 *)(arg0 + 0x8) += v;
    }
    t = *(u8 *)(arg0 + 0x11) + *(s16 *)(arg1 + 0x1E);
    if (t < 0) {
        *(u8 *)(arg0 + 0x11) = 0;
    } else if (t > 0xFF) {
        *(u8 *)(arg0 + 0x11) = 0xFF;
    } else {
        *(u8 *)(arg0 + 0x11) = t;
    }
    if ((u8)((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 1) {
        if (*(u8 *)(arg0 + 6) & 0x20) {
            if ((*(u8 *)(arg0 + 6) & 0xF) != *(u8 *)(D_089CC438 + 0x28)) {
                *(u8 *)(arg0 + 3) += 0xFD;
            }
        }
    }
}
