/* unit_0887265C: 0x0887265C-0x0887276C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned short u16;

extern char *D_08A631A0;

extern s32 func_088900C4(char *, s32);

u16 func_0887265C(u16 *arg0, s16 *arg1) {
    s32 stride;
    u16 total;
    u16 *p;
    u16 acc;
    u16 r;

    if (arg1 == 0) {
        stride = 2;
    } else {
        stride = 3;
    }
    total = 0;
    for (p = arg0; *p != 0xFFFF; p += stride) {
        total += *p;
    }
    r = (u16) func_088900C4(D_08A631A0, 0) % total;
    acc = 0;
    for (p = arg0; *p != 0xFFFF; p += stride) {
        acc += *p;
        if (acc > r) {
            if (arg1 != 0) {
                *arg1 = p[2];
            }
            return p[1];
        }
    }
    if (*arg1 != 0) {
        *arg1 = 0;
    }
    return 0xFFFF;
}
