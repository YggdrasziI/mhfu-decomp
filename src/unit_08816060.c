/* unit_08816060: 0x08816060-0x088160F0 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef float f32;

extern void func_088160F0(char *, s32, f32, f32);

s32 func_08816060(char *arg0, char *arg1, f32 fparg0) {
    f32 temp_f2;
    s32 var_v0;

    if (*(u8 *)(arg0 + 0xAAA) == 0) {
        return 1;
    }
    temp_f2 = *(f32 *)(arg0 + 0xBB8) + ((*(f32 *)(arg0 + 0xBA8) * *(f32 *)(arg1 + 8)) + ((*(f32 *)(arg0 + 0xB88) * *(f32 *)arg1) + (*(f32 *)(arg0 + 0xB98) * *(f32 *)(arg1 + 4))));
    if ((temp_f2 - fparg0) > *(f32 *)(arg0 + 0xD90)) {
        return 0;
    }
    var_v0 = 1;
    if (!((temp_f2 + fparg0) < *(f32 *)(arg0 + 0xD94))) {
        var_v0 = 0;
    }
    return var_v0 ^ 1;
}

void func_088160E8(char *arg0, s32 arg1, f32 farg0) {
    func_088160F0(arg0, arg1, farg0, *(f32 *)(arg0 + 0xd94));
}
