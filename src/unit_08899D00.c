/* unit_08899D00: 0x08899D00-0x08899D9C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern void func_08899DE0(char *, s8, s32);

s32 func_08899D00(char *arg0, u8 *arg1, s32 arg2) {
    s32 n;
    s32 i;
    s32 j;
    char *p;
    s32 r;

    i = 0;
    n = *(s8 *)(arg0 + 0x12D8);
    if (n > 0) {
        p = arg0;
        do {
            for (j = 0; j < 6; j++) {
                u8 a = (p + j)[0x12DC];
                u8 b = arg1[j];
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
                func_08899DE0(arg0, i, arg2);
                return 1;
            }
            i++;
            p += 0x64;
        } while (i < n);
    }
    return 0;
}
