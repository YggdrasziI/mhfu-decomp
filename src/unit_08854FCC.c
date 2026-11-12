/* unit_08854FCC: 0x08854FCC-0x08855038 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern s32 func_08854C5C(s32, s32);

s32 func_08854FCC(s32 arg0) {
    return (func_08854C5C(arg0, 8) & 0xFF) != 0;
}

s32 func_08854FF0(s32 arg0) {
    return (func_08854C5C(arg0, 9) & 0xFF) != 0;
}

s32 func_08855014(s32 arg0) {
    return (func_08854C5C(arg0, 0xA) & 0xFF) != 0;
}
