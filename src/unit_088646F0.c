/* unit_088646F0: 0x088646F0-0x0886477C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 D_089CBFFC;
extern int func_0884CDE4(s32, s32);
extern int func_0886477C(char **, s32, s32, s32);

void func_088646F0(char **arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;

    func_0884CDE4(D_089CBFFC, arg3);
    var_s0 = 0;
    if ((s32) *(u16 *)((char *)(*arg0) + 0x1C) > 0) {
        do {
            func_0886477C(arg0, arg1, arg2, var_s0);
            var_s0 += 1;
        } while (var_s0 < (s32) *(u16 *)((char *)(*arg0) + 0x1C));
    }
}
