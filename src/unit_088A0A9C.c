/* unit_088A0A9C: 0x088A0A9C-0x088A0AB0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

void func_088A0A9C(char *arg0) {
    *(s32 *)arg0 = (s32) (*(s32 *)arg0 + *(u16 *)(arg0 + 4));
}
