/* unit_088DD7E8: 0x088DD7E8-0x088DD838 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_09A4F0D0;
extern int func_0890BFA4(s32);

s32 func_088DD7E8(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            D_09A4F0D0 = 0;
        }
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}
