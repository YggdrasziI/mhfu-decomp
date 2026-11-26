/* unit_08828F14: 0x08828F14-0x08828F3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * Tests a u16 against the bytes at 0x5B0 and 0x5B1.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

s32 func_08828F14(char *p, u16 v) {
    if (v == *(u8 *)(p + 0x5B0) || v == *(u8 *)(p + 0x5B1)) {
        return 1;
    }
    return 0;
}
