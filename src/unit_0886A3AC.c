/* unit_0886A3AC: 0x0886A3AC-0x0886A444 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A3AC */
typedef int s32;
typedef short s16;
typedef signed char s8;

extern s32 func_0886A30C(char *, s32);
extern char *func_0886DD3C(char *, s32);
extern s32 func_0886A524(char *, s32);

s32 func_0886A3AC(char *arg0, s32 arg1) {
    char *p;

    if (func_0886A30C(arg0, 0) != 0) {
        return 0;
    }
    p = func_0886DD3C(arg0, arg1);
    if (p != 0) {
        if (*(s16 *)(p + 0x2E) & 1) {
            if (func_0886A524(arg0, arg1) == 0) {
                return 1;
            }
        } else if (*(s8 *)(p + 0xA) != 1) {
            return 1;
        }
    }
    return 0;
}
