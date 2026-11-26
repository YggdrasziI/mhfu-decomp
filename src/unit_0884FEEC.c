/* unit_0884FEEC: 0x0884FEEC-0x0884FF24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FEEC: add to a u16 counter at 0x46E8 indexed by a byte, clamped to 9999. */

typedef unsigned char u8;
typedef unsigned short u16;

void func_0884FEEC(char *arg0, u8 arg1, u16 arg2) {
    u16 *p = &((u16 *)(arg0 + 0x46E8))[arg1];

    *p += arg2;
    if (*p > 9999) {
        *p = 9999;
    }
}
