/* unit_088D9EB8: 0x088D9EB8-0x088DA008 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088D92F8 and unit_088DA008
 * (see unit_088D92F8 for the start).
 *
 * func_088D9EB8 adds a value to the float of +0x39C...+0x3AC chosen by a
 * key (0x10-0x14). func_088D9F3C adds the five signed bytes at +0x6993D of
 * the global object to those floats.
 *
 * Optimized for speed (loop of five unrolled).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef short s16;
typedef int s32;

extern char *D_089CC438;

void func_088D9EB8(char *arg0, s16 arg1, float arg2) {
    if (arg1 == 0x10) {
        *(float *)(arg0 + 0x39C) += arg2;
    } else if (arg1 == 0x11) {
        *(float *)(arg0 + 0x3A0) += arg2;
    } else if (arg1 == 0x12) {
        *(float *)(arg0 + 0x3A4) += arg2;
    } else if (arg1 == 0x13) {
        *(float *)(arg0 + 0x3AC) += arg2;
    } else if (arg1 == 0x14) {
        *(float *)(arg0 + 0x3A8) += arg2;
    }
}

void func_088D9F3C(char *arg0) {
    s32 i;

    for (i = 0; i < 5; i++) {
        ((float *)(arg0 + 0x39C))[i] += *(s8 *)(D_089CC438 + 0x6993D + i);
    }
}
