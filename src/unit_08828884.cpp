/* unit_08828884: 0x08828884-0x08828938 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef unsigned short u16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern s32 func_088D72A4(s32, s32, s32, s32);
extern void func_088D8900(s32);

void func_08828884(char *arg0) {
    s32 var_s2;
    u16 temp_a1;
    char *var_s1;

    if (*(s32 *)(arg0 + 0x528) & 8) {
        var_s2 = 0;
        var_s1 = arg0;
        do {
            temp_a1 = *(u16 *)(var_s1 + 0x5AC);
            if (temp_a1 != 0xFFFF) {
                func_088D72A4(*(s32 *)(arg0 + 0x530), (s32) temp_a1, 1, 0);
            }
            var_s2 += 1;
            var_s1 += 2;
        } while (var_s2 < 2);
        if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 1) {
            func_088D8900(*(s32 *)(arg0 + 0x530));
        }
        *(s32 *)(arg0 + 0x528) = (s32) (*(s32 *)(arg0 + 0x528) & ~8);
    }
}

}
