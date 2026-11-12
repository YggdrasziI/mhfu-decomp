/* unit_08863D58: 0x08863D58-0x08863DF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern void func_0885F9A0(s32, s32, s32, s32);
extern void func_0886423C(char *, s32, s32);

void func_08863D58(char *arg0, s32 arg1, s32 arg2) {
    s32 var_s1;
    char *var_s0;

    if (arg1 != 0) {
        ((s8 *)((char *)arg0 + 0x128))[arg2] = 0;
        ((s16 *)((char *)arg0 + 0x130))[arg2] = 0;
        func_0886423C(arg0, arg1, arg2);
        var_s1 = 0;
        if ((s32) *(u16 *)(arg0 + 0x120) > 0) {
            var_s0 = arg0;
            do {
                func_0885F9A0(*(s32 *)(var_s0 + 0x110), arg1, arg2, 0);
                var_s1 += 1;
                var_s0 += 4;
            } while (var_s1 < (s32) *(u16 *)(arg0 + 0x120));
        }
    }
}
