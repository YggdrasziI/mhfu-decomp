/* unit_0886D114: 0x0886D114-0x0886D168 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886D114: finds arg1 in the byte list D_08A62C9C and passes its
 * index to func_0886D0AC. */
#pragma optimize_for_size off

typedef signed char s8;
typedef int s32;

extern char D_08A62C9C;
extern void func_0886D0AC(char *arg0, s8 arg1);

void func_0886D114(char *arg0, s8 arg1) {
    s32 i;

    for (i = 0; i < *(s8 *)(arg0 + 0x21); i++) {
        if (arg1 == (&D_08A62C9C)[i]) {
            func_0886D0AC(arg0, i);
            return;
        }
    }
}
