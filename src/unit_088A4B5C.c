/* unit_088A4B5C: 0x088A4B5C-0x088A4BC4 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;

extern s32 func_088A47C4(s32);
extern s32 D_09A0EB10[16];

s32 func_088A4B5C(s32 arg0) {
    s32 ret;
    s32 i;

    ret = func_088A47C4(arg0);
    if (ret < 0) {
        return ret;
    }
    for (i = 0; i < 16; i++) {
        D_09A0EB10[i] = 0;
    }
    return 0;
}
