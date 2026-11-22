/* unit_0889CE10: 0x0889CE10-0x0889CEB0 (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

u8 *func_0889CE10(u8 *arg0, u8 *arg1) {
    s32 i;
    s32 j;
    s32 r;
    u8 e;
    u8 c;

    for (i = 0; i < *(s8 *) (arg0 + 0x12D8); i++) {
        for (j = 0; j < 6; j++) {
            e = (arg0 + i * 100)[j + 0x12DC];
            c = arg1[j];
            if (c < e) {
                r = -1;
                goto done;
            }
            if (e < c) {
                r = 1;
                goto done;
            }
        }
        r = 0;
    done:
        if (r == 0) {
            return arg0 + i * 100 + 0x12DC;
        }
    }
    return 0;
}
