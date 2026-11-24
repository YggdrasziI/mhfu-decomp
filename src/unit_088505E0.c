/* unit_088505E0: 0x088505E0-0x08850618 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

void func_088505E0(char *arg0, s32 arg1) {
    ((u32 *)(arg0 + 0x6ADE8))[arg1 >> 5] |= 1 << (arg1 & 0x1F);
}
