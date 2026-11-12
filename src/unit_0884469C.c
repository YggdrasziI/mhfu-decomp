/* unit_0884469C: 0x0884469C-0x088446CC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern s32 func_088446CC(s32, s32);

void func_0884469C(char *arg0) {
    *(s8 *)(arg0 + 0x578) = func_088446CC((s32) arg0, (s32) *(u16 *)((*(char **)(arg0 + 0x530)) + 0x29A));
}
