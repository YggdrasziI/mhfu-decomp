/* unit_08854CCC: 0x08854CCC-0x08854D64 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;

extern s32 func_08854BEC(s32, s32);

s32 func_08854CCC(s32 arg0) {
    if (!(func_08854BEC(arg0, 0) & 0xFF)) {
        return 0;
    }
    if (!(func_08854BEC(arg0, 1) & 0xFF)) {
        return 0;
    }
    return 1;
}

s32 func_08854D18(s32 arg0) {
    if (!(func_08854BEC(arg0, 2) & 0xFF)) {
        return 0;
    }
    if (!(func_08854BEC(arg0, 3) & 0xFF)) {
        return 0;
    }
    return 1;
}
