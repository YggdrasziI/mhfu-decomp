/* unit_0889CEB0: 0x0889CEB0-0x0889CF34 (ULES01213) */
#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

s8 func_0889CEB0(u8 *arg0, u8 *arg1) {
    s32 n;
    s32 i;
    s32 j;
    s32 r;

    n = *(s8 *)(arg0 + 0x12D8);
    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            if (arg1[j] < arg0[0x12DC + j]) {
                r = -1;
                goto done;
            }
            if (arg0[0x12DC + j] < arg1[j]) {
                r = 1;
                goto done;
            }
        }
        r = 0;
done:
        if (r == 0) {
            return i;
        }
        arg0 += 0x64;
    }
    return -1;
}
