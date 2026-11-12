/* unit_0890CB64: 0x0890CB64-0x0890CBC0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_089BAEDC;
extern char D_089BAEEC;
extern int func_0890BFA4(s32);

char **func_0890CB64(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAEEC;
        if (arg0 != 0) {
            *arg0 = &D_089BAEDC;
        }
        if (arg1 > 0) {
            func_0890BFA4((s32) arg0);
        }
    }
    return arg0;
}
