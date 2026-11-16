/* unit_08854EB0: 0x08854EB0-0x08854FCC (ULES01213)
 *
 * Bounds (hypothesis): 3 small functions between code still in assembly.
 */

typedef int s32;

extern s32 func_08854C5C(s32, s32);

s32 func_08854EB0(s32 arg0) {
    if (!(func_08854C5C(arg0, 0) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 1) & 0xFF)) {
        return 0;
    }
    return 1;
}

s32 func_08854EFC(s32 arg0) {
    if (!(func_08854C5C(arg0, 2) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 3) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 4) & 0xFF)) {
        return 0;
    }
    return 1;
}

s32 func_08854F64(s32 arg0) {
    if (!(func_08854C5C(arg0, 5) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 6) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 7) & 0xFF)) {
        return 0;
    }
    return 1;
}
