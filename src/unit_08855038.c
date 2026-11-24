/* unit_08855038: 0x08855038-0x08855160 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08855038 (ULES01213): all nine checks must hold. */

typedef int s32;

extern s32 func_08854D88(s32);
extern s32 func_08854BEC(s32, s32);
extern s32 func_08854EB0(s32);
extern s32 func_08854EFC(s32);
extern s32 func_08854F64(s32);
extern s32 func_08854C5C(s32, s32);

s32 func_08855038(s32 arg0) {
    if (!(func_08854D88(arg0) & 0xFF)) {
        return 0;
    }
    if (!(func_08854BEC(arg0, 6) & 0xFF)) {
        return 0;
    }
    if (!(func_08854BEC(arg0, 7) & 0xFF)) {
        return 0;
    }
    if (!(func_08854BEC(arg0, 8) & 0xFF)) {
        return 0;
    }
    if (!(func_08854EB0(arg0) & 0xFF)) {
        return 0;
    }
    if (!(func_08854EFC(arg0) & 0xFF)) {
        return 0;
    }
    if (!(func_08854F64(arg0) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 8) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 9) & 0xFF)) {
        return 0;
    }
    if (!(func_08854C5C(arg0, 0xA) & 0xFF)) {
        return 0;
    }
    return 1;
}
