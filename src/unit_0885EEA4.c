/* unit_0885EEA4: 0x0885EEA4-0x0885EF20 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

s32 func_0885EEA4(s32 arg0, char *arg1, char *arg2) {
    if (*(u8 *)(arg1 + 1) != *(u8 *)(arg2 + 1)) {
        return 0;
    }
    if (*(u16 *)(arg1 + 2) != *(u16 *)(arg2 + 2)) {
        return 0;
    }
    if (*(u16 *)(arg1 + 4) != *(u16 *)(arg2 + 4)) {
        return 0;
    }
    if (*(u16 *)(arg1 + 6) != *(u16 *)(arg2 + 6)) {
        return 0;
    }
    if (*(u16 *)(arg1 + 8) != *(u16 *)(arg2 + 8)) {
        return 0;
    }
    return *(u16 *)(arg1 + 0xA) == *(u16 *)(arg2 + 0xA);
}
