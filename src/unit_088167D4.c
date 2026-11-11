/* unit_088167D4: 0x088167D4-0x088167EC (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

s32 func_088167D4(s32 arg0, u32 arg1) {
    return arg1 < 0x80000000U;
}

s32 func_088167E0(s32 arg0, u32 arg1) {
    return arg1 < 0x10000U;
}
