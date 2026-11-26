/* unit_0884FF4C: 0x0884FF4C-0x0884FF80 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884FF4C: sum of two u16 tables indexed by a byte, clamped to 9999. */

typedef unsigned short u16;
typedef unsigned char u8;

u16 func_0884FF4C(char *arg0, u8 arg1) {
    u16 n = *(u16 *)((char *)(arg1 * 2) + (int)arg0 + 0x46E8) + *(u16 *)((char *)(arg1 * 2) + (int)arg0 + 0x44CC);
    if (n > 9999) {
        n = 9999;
    }
    return n;
}
