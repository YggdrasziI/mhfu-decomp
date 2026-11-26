/* unit_08828EEC: 0x08828EEC-0x08828F14 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;

s32 func_08828EEC(char *p) {
    if (*(u16 *)(p + 0x5AC) == 0xFFFF || *(u16 *)(p + 0x5AE) == 0xFFFF) {
        return 0;
    }
    return 1;
}
