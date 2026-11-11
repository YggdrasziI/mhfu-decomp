/* unit_0888640C: 0x0888640C-0x08886468 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_08886674(s32, s32);
extern char func_08886898;
extern int func_088A1848(s32);
extern int func_088A2404(char *);

void func_0888640C(s32 arg0) {
    s32 var_s0;

    func_088A1848(0x11);
    func_088A2404(&func_08886898);
    var_s0 = 0;
    do {
        func_08886674(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 < 2);
}
