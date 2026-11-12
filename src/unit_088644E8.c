/* unit_088644E8: 0x088644E8-0x08864544 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_089BAB44;
extern void *func_08861604(void *, s16);
extern void func_0886454C(s32);

char **func_088644E8(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAB44;
        func_08861604(arg0, 0);
        if (arg1 > 0) {
            func_0886454C((s32) arg0);
        }
    }
    return arg0;
}
