/* unit_088B047C: 0x088B047C-0x088B04B4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_09A1FDE4;
extern s8 D_09A1FDE8;

s32 func_088B047C(s32 arg0, s32 arg1) {
    if (arg1 == 7) {
        D_09A1FDE8 = 1;
    } else {
        if (arg1 == 8) {
            D_09A1FDE4 = arg0;
        }
    }
    return 0;
}
