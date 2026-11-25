/* unit_0885E748: 0x0885E748-0x0885E834 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E748: if arg1->count (byte 1) is below 7, takes n =
 * func_0885EB34(arg0, arg1) clamped to 3 (0 when not positive), sums the
 * levels (byte read through func_0885E834, 0 or above 3 counting as 1) of
 * the nonzero u16 ids at arg1 + 6 among the first n, and returns n - sum,
 * or 0 when the sum exceeds n.
 * Speed setting (pointer stepped in the loop). Compares written `> 6` /
 * `> 3` so that the slti result goes through $at.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 pad0;
    u8 count;
    u8 pad2[4];
    u16 ids[1];
} Rec;

extern s8 func_0885EB34(s32 arg0, Rec *arg1);
extern u8 *func_0885E834(s32, s32);

s32 func_0885E748(s32 arg0, Rec *arg1) {
    s32 n;
    s32 i;
    s32 sum;
    s32 v;

    if (arg1->count > 6) {
        return 0;
    }
    v = func_0885EB34(arg0, arg1);
    if (v <= 0) {
        return 0;
    }
    if (v > 3) {
        v = 3;
    }
    n = (s8)v;
    sum = 0;
    for (i = 0; i < n; i++) {
        if (arg1->ids[i] != 0) {
            v = *(s8 *)func_0885E834(arg0, arg1->ids[i]);
            if (v == 0 || v > 3) {
                v = 1;
            }
            sum += (s8)v;
        }
    }
    if (n < sum) {
        return 0;
    }
    return n - sum;
}
