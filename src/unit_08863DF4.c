/* unit_08863DF4: 0x08863DF4-0x08863E70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08863DF4 (ULES01213) */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern void func_08863D58(char *, s32, s32);
extern void func_08863E70(char *, s32, s32, s32, s32);

void func_08863DF4(char *arg0, s32 arg1, u32 arg2, s32 arg3, float arg4) {
    if (arg2 != 0 && ((s32 *)(arg0 + 0x38))[arg3 * 16] == 0) {
        arg2 = 0;
    }
    if (arg2 == 0) {
        func_08863D58(arg0, arg1, arg3);
    } else if (arg1 != 0) {
        func_08863E70(arg0, arg1, (s32)arg4, arg2, arg3);
    } else {
        ((s8 *)(arg0 + 0x128))[arg3] = 0;
        ((s16 *)(arg0 + 0x130))[arg3] = 0;
    }
}
