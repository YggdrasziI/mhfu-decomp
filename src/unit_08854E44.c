/* unit_08854E44: 0x08854E44-0x08854EB0 (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern s32 func_08854BEC(s32, s32);

s32 func_08854E44(s32 arg0) {
    return (func_08854BEC(arg0, 6) & 0xFF) != 0;
}

s32 func_08854E68(s32 arg0) {
    return (func_08854BEC(arg0, 7) & 0xFF) != 0;
}

s32 func_08854E8C(s32 arg0) {
    return (func_08854BEC(arg0, 8) & 0xFF) != 0;
}
