/* unit_088903BC: 0x088903BC-0x08890430 (ULES01213)
 *
 * Bounds (hypothesis): 1 function before unit_08890430; the code before it is still in
 * assembly.
 * Its jump table (0x08931AA0-0x08931ABC) is linked from this unit.
 */

typedef int s32;

s32 func_088903BC(char *arg0) {
    switch (*(s32 *) (arg0 + 0xF7A574)) {
    case 0:
    default:
        return 0;
    case 1:
        return 1;
    case 2:
        return 4;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 5;
    case 6:
        return 9;
    }
}
