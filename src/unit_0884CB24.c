/* unit_0884CB24: 0x0884CB24-0x0884CBD8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;
typedef float f32;

extern s32 D_089CBBE4;
extern s32 func_088160E8(s32, char *, f32);
extern s32 func_0884CBD8(s32, s32, char *, char *, s32);

void func_0884CB24(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    *(s32 *)(arg2 + 4) = (s32) (*(s32 *)(arg2 + 4) & ~2);
    if (((arg3 & 0xFF) || (func_088160E8(D_089CBBE4, arg2 + 0x40, *(f32 *)((*(char **)(arg2 + 0x50)) + 0xC)) & 0xFF)) && ((func_0884CBD8(arg0, arg1, arg2, arg2 + 0x40, arg3) & 0xFF) == 1)) {
        *(s32 *)(arg2 + 4) = (s32) (*(s32 *)(arg2 + 4) | 2);
    }
}
