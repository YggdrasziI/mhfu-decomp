/* unit_0881C2E4: 0x0881C2E4-0x0881C398 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0881C2E4: move a menu cursor up (0x10) or down (0x40) with wrap. */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62D8C;

extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_0881C2E4(char *arg0, u8 *cur, u16 pad, u8 n)
{
    u8 old = *cur;
    u8 v = old;

    if (pad & 0x10) {
        if (old == 0) {
            v = n - 1;
        } else {
            v = old - 1;
        }
    } else if (pad & 0x40) {
        v = old + 1;
        if (v >= n) {
            v = 0;
        }
    }
    if (v != old) {
        *cur = v;
        func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}
