/* unit_08873980: 0x08873980-0x088739A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

void func_08873980(s32 arg0, char *arg1) {
    if (*(u8 *)(arg1 + 0x1E9) == 1) {
        *(s8 *)((char *)((*(u8 *)(arg1 + 0x1E8) + arg0)) + 0x7CC) = 1;
    }
}
