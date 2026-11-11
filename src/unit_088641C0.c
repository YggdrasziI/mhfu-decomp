/* unit_088641C0: 0x088641C0-0x0886421C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern int func_08860648(s32);

void func_088641C0(char *arg0) {
    s32 var_s1;
    char *var_s0;

    var_s1 = 0;
    if ((s32) *(u16 *)(arg0 + 0x120) > 0) {
        var_s0 = arg0;
        do {
            func_08860648(*(s32 *)(var_s0 + 0x110));
            var_s1 += 1;
            var_s0 += 4;
        } while (var_s1 < (s32) *(u16 *)(arg0 + 0x120));
    }
}
