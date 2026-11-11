/* unit_08896A50: 0x08896A50-0x08896AD4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_089CC438;
extern int func_0884FAC4(s32, s32);
extern s32 func_0884FB38(s32, s32);

s32 func_08896A50(char *arg0, s32 arg1, s32 arg2, s8 arg3) {
    s32 temp_s2;

    if ((arg2 & 0xFFFF) == *(s8 *)(arg0 + 0x1111)) {
        temp_s2 = arg1 & 0xFFFF;
        if ((func_0884FB38(D_089CC438, temp_s2) & 0xFF) != 1) {
            func_0884FAC4(D_089CC438, temp_s2);
            *(s8 *)(arg0 + 0x1113) = arg3;
            return 1;
        }
    }
    return 0;
}
