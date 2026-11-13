/* unit_0886A58C: 0x0886A58C-0x0886A60C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 func_0886A30C(s32, s32);
extern int func_0886DD3C(s32, void *);

s32 func_0886A58C(s32 arg0, char *arg1) {
    s32 temp_v0;

    if (func_0886A30C(arg0, 0) != 0) {
        return 0;
    }
    temp_v0 = func_0886DD3C(arg0, arg1);
    if ((temp_v0 != 0) && !(*(s16 *)(temp_v0 + 0x2E) & 1) && (*(s8 *)(temp_v0 + 0xA) != 1)) {
        return 1;
    }
    return 0;
}
