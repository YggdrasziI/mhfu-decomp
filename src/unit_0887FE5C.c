/* unit_0887FE5C: 0x0887FE5C-0x0887FEE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern void func_0887FBC4(s32, s32);
extern void func_0887FBF8(s32);
extern void func_0889EA54(s32);

void func_0887FE5C(char *arg0, s32 arg1, s8 arg2) {
    s32 var_s2;

    func_0889EA54(arg1);
    var_s2 = 1;
    if (arg2 == 1) {
        func_0887FBF8((s32) arg0);
    } else {
        if (*(s32 *)(arg0 + 8) != arg1) {
            do {
                func_0887FBC4((s32) arg0, var_s2);
                var_s2 += 1;
            } while (var_s2 < 0x10);
        }
    }
    *(s32 *)(arg0 + 8) = arg1;
}
