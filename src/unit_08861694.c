/* unit_08861694: 0x08861694-0x0886171C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 func_0886171C(s32, s32, s32, s32);
extern s32 func_08862354(s32, s32);

void func_08861694(char **arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;

    func_08862354(arg3, (int) ((char *) arg0 + 0x10));
    var_s0 = 0;
    if ((s32) *(u16 *)((char *)(*arg0) + 0x1C) > 0) {
        do {
            func_0886171C((s32) arg0, arg1, arg2, var_s0 & 0xFF);
            var_s0 += 1;
        } while (var_s0 < (s32) *(u16 *)((char *)(*arg0) + 0x1C));
    }
}
