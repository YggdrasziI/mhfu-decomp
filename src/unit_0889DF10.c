/* unit_0889DF10: 0x0889DF10-0x0889DFAC (ULES01213) */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

extern s32 func_0889DFAC(char *, s32);

s32 func_0889DF10(char *arg0, u8 *key) {
    s32 i;
    s32 j;
    s32 r;
    char *p;

    i = 0;
    if (*(s8 *)(arg0 + 0xEE3) > 0) {
        p = arg0;
        do {
            for (j = 0; j < 6; j++) {
                u8 a = (u8)p[0x57C + j];
                u8 b = key[j];
                if (b < a) {
                    r = -1;
                    goto done;
                }
                if (a < b) {
                    r = 1;
                    goto done;
                }
            }
            r = 0;
        done:
            if (r == 0) {
                return func_0889DFAC(arg0, i);
            }
            i++;
            p += 0xC8;
        } while (i < *(s8 *)(arg0 + 0xEE3));
    }
    return 0;
}
