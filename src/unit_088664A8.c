/* unit_088664A8: 0x088664A8-0x088664F8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_08A62C5C;
extern int func_0890BFA4(s32);

s32 func_088664A8(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        if (arg0 != 0) {
            D_08A62C5C = 0;
        }
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}
