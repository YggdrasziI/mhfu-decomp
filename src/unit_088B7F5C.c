/* unit_088B7F5C: 0x088B7F5C-0x088B826C (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088B7F5C asm piece, 4 functions
 * between unit_088B7A5C and unit_088B826C.
 *
 * Angles in radians: func_088B7F5C brings an angle into [0, 2 pi];
 * func_088B7FCC remaps it piecewise (breaks at pi / 3, 2 pi / 3, 7 pi / 6
 * and 11 pi / 6, the last pieces through func_08905E9C(x, 2.0));
 * func_088B8164 returns quadrant flags (0x80 past pi, 0x40 in the first
 * and last quarters) and func_088B81F8 a value from -0x40 to 0x3F.
 *
 * Speed mode: the double constant 7 pi / 4 is built with `lui` / `ori`
 * (notes/MATCHING.md).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef int s32;

extern double func_08905E9C(double, double);

float func_088B7F5C(float a) {
    while (a < 0.0f) {
        a += 6.2831855f;
    }
    while (a > 6.2831855f) {
        a -= 6.2831855f;
    }
    return a;
}

float func_088B7FCC(float a) {
    float b;

    a = func_088B7F5C(a);
    if (a < 1.0471976f) {
        b = 5.4977875f + func_08905E9C(a + 6.2831855f - 5.759587f, 2.0);
    } else if (a < 2.0943952f) {
        b = 3.0f * (a - 1.0471976f);
    } else if (a < 3.6651914f) {
        b = 3.1415927f + (a - 2.0943952f) / 2.0f;
    } else if (a < 5.759587f) {
        b = 3.926991f + 3.0f * ((a - 3.6651914f) / 4.0f);
    } else {
        b = 5.4977875f + func_08905E9C(a - 5.759587f, 2.0);
    }
    return func_088B7F5C(b);
}

u8 func_088B8164(float a) {
    u8 r;

    r = 0;
    a = func_088B7FCC(a);
    if (a < 3.1415927f) {
        if (!(a > 1.5707964f)) {
            r |= 0x40;
        }
    } else {
        r |= 0x80;
        if (a > 4.712389f) {
            r |= 0x40;
        }
    }
    return r;
}

s32 func_088B81F8(float a) {
    s32 v;

    a = func_088B7FCC(a);
    if (a < 3.1415927f) {
        v = 127.0f - 127.0f * a / 3.1415927f;
    } else {
        v = 127.0f * (float) (a - 3.1415927f) / 3.1415927f;
    }
    return v - 0x40;
}
