/* unit_08897E5C: 0x08897E5C-0x08897ED8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_089BAAA8;
extern char D_089BABAC;
extern char D_089BAC20;
extern s32 D_089CC434;
extern int func_0890BFA4(char **);

char **func_08897E5C(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BABAC;
        if (arg0 != 0) {
            *arg0 = &D_089BAAA8;
            if (arg0 != 0) {
                *arg0 = &D_089BAC20;
            }
        }
        if (arg0 != 0) {
            D_089CC434 = 0;
        }
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}
