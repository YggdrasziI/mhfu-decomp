/* unit_088EC224: 0x088EC224-0x088EC284 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088EC098(char *, s32);
extern int func_088EC3E0(char *);
extern int func_088EF354(char *, s32, s32);

void func_088EC224(char *arg0) {
    s32 var_s0;

    var_s0 = 1;
    do {
        func_088EC098(arg0, var_s0);
        var_s0 -= 1;
    } while (var_s0 >= 0);
    func_088EF354(arg0, *(s32 *)(arg0 + 4), 0x54);
    *(s32 *)(arg0 + 4) = 0;
    func_088EC3E0(arg0);
}
