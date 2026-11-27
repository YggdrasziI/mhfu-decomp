/* unit_08850618: 0x08850618-0x08850648 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08850618: tests bit arg1 of the bit set at +0x6ADE8 (set by
 * func_088505E0). */

typedef int s32;
typedef unsigned int u32;

s32 func_08850618(char *arg0, s32 arg1) {
    u32 w = ((u32 *)(arg0 + 0x6ADE8))[arg1 >> 5];

    return (w & (1 << (arg1 & 0x1F))) != 0;
}
