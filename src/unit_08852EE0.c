/* unit_08852EE0: 0x08852EE0-0x08852F1C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08852EE0: set bit n of the flag array at 0x44AC (n < 0x3E). */

typedef int s32;
typedef unsigned char u8;

void func_08852EE0(char *arg0, s32 arg1) {
    s32 n = (u8)arg1;

    if (n < 0x3E) {
        ((u8 *)(arg0 + 0x44AC))[n >> 3] |= (u8)(1 << (n & 7));
    }
}
