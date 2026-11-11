/* unit_08859AF0: 0x08859AF0-0x08859B44 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

void func_08859AF0(char *arg0) {
    *(s32 *)((*(char **)(arg0 + 4)) + 0) = 0;
    *(s32 *)((*(char **)(arg0 + 4)) + 4) = 0;
    *(s32 *)((*(char **)(arg0 + 4)) + 8) = 0;
    *(s32 *)((*(char **)(arg0 + 4)) + 0xC) = 0;
    *(s32 *)((*(char **)(arg0 + 4)) + 0x18) = 0;
    *(s32 *)((*(char **)(arg0 + 4)) + 0x10) = 2;
    *(u32 *)((*(char **)(arg0 + 4)) + 0x14) = (u32) ((u32) (*(s32 *)arg0 - 0x20) >> 4);
    *(char **)(arg0 + 0x10) = (char *) *(char **)(arg0 + 4);
}
