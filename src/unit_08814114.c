/* unit_08814114: 0x08814114-0x08814268 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_08933A94[];

s32 func_08814114(char *arg0, u8 *arg1, char *arg2) {
    char *base = *(char **)(arg2 + 0x190);
    u8 best = 0xFF;
    float min = 65000.0f;
    float d;
    s32 i;


    for (i = 0; i < 3; i++) {
        float *pd = &d;
        float *e = (float *)(base + D_08933A94[i] * 0x250 + 0x100);
        float *p = (float *)(arg0 + 0xB40);
        asm {
            lv.q C000, 0(e)
            lv.q C010, 0(p)
            vsub.t C000, C000, C010
            vdot.t S010, C000, C000
            sv.s S010, 0(pd)
        }
        if (d < min) {
            min = d;
            best = i;
        }
    }
    if (best != 0xFF) {
        if (min < 10000.0f) {
            if (min <= 3600.0f) {
                *arg1 = 0x4C;
            } else {
                *arg1 = (u8)(u32)(179.0f * ((min - 3600.0f) / 6400.0f)) + 0x4C;
            }
        } else {
            *arg1 = 0xFF;
            return 0;
        }
    } else {
        *arg1 = 0xFF;
    }
    return 1;
}
