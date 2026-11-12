/* unit_088DCF70: 0x088DCF70-0x088DCFCC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern char D_089BAE28;
extern void func_0886454C(s32);
extern void *func_088CE208(void *, s16);

char **func_088DCF70(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAE28;
        func_088CE208(arg0, 0);
        if (arg1 > 0) {
            func_0886454C((s32) arg0);
        }
    }
    return arg0;
}
