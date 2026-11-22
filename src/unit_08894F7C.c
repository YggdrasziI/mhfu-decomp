/* unit_08894F7C: 0x08894F7C-0x08895220 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * #pragma optimize_for_size off: the copy loops are unrolled by 8 behind a
 * guard. #pragma opt_rebuildconditionals off: keeps the `ret == 2` if/else
 * as branches (otherwise folded into xori / sltiu).
 */

#pragma optimize_for_size off
#pragma opt_rebuildconditionals off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern s32 D_089CBBE8;
extern s32 func_08816930(s32 arg0, s32 arg1);
extern s32 func_08891B5C(s32 arg0, s8 *arg1);

s16 func_08894F7C(s32 arg0, s16 arg1, s8 *arg2, s8 **arg3, u8 arg4) {
    s16 count;
    s8 *src;
    s32 len;
    s32 ret;
    s32 r;
    s32 i;
    u8 c;

    src = *arg3;
    count = 0;
    while (*src != 0) {
        if (arg4 == 1) {
            len = func_08816930(D_089CBBE8, (u8) *src);
            if (count == arg1) {
                ret = func_08891B5C(arg0, src);
                for (i = 0; i < len; i++) {
                    *arg2++ = *src++;
                }
                *arg2 = 0;
                *arg3 = src;
                if (ret == 2) {
                    r = 1;
                } else {
                    r = 0;
                }
                return r;
            }
            for (i = 0; i < len; i++) {
                src++;
            }
            count++;
        } else {
            c = *src;
            if ((c >= 0x81 && c <= 0x9F) || (c >= 0xE0 && c < 0x100)) {
                if (count == arg1) {
                    arg2[0] = *src;
                    arg2[1] = src[1];
                    arg2[2] = 0;
                    *arg3 = src + 2;
                    return 1;
                }
                src++;
            } else {
                if (count == arg1) {
                    arg2[0] = *src;
                    arg2[1] = 0;
                    *arg3 = src + 1;
                    return 0;
                }
            }
            src++;
            count++;
        }
    }
    *arg2 = 0;
    *arg3 = src;
    return 4;
}
