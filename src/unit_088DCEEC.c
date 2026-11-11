/* unit_088DCEEC: 0x088DCEEC-0x088DCF3C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_09A4F0C4;
extern int func_0890BFA4(s32);

s32 func_088DCEEC(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            D_09A4F0C4 = 0;
        }
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}
