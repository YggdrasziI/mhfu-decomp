/* unit_0886AD0C: 0x0886AD0C-0x0886AD58 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern int func_0886DD3C(s32, char *, s32);

void func_0886AD0C(s32 arg0, char *arg1, s32 arg2) {
    char *temp_v0;

    temp_v0 = (char *) (func_0886DD3C(arg0, arg1, arg2));
    if ((temp_v0 != 0) && !(*(s16 *)(temp_v0 + 0x2E) & 1)) {
        *(s16 *)(temp_v0 + 0x32) = (s16) *(s16 *)(arg1 + 0x2E4);
        *(s8 *)(temp_v0 + 0x34) = -1;
    }
}
