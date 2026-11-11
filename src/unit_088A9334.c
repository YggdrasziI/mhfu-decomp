/* unit_088A9334: 0x088A9334-0x088A93A4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern int func_088A84B4(char *, s32, s32);

void func_088A9334(char *arg0) {
    s32 var_s0;

    *(s32 *)(arg0 + 0x64) = 0;
    var_s0 = 0;
    if ((s32) *(u8 *)(arg0 + 0x22) > 0) {
        do {
            if (*(u8 *)((char *)((arg0 + var_s0)) + 0x68) == 3) {
                func_088A84B4(arg0, var_s0 & 0xFF, 1);
            }
            var_s0 += 1;
        } while (var_s0 < (s32) *(u8 *)(arg0 + 0x22));
    }
}
