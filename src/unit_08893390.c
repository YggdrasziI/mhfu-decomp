/* unit_08893390: 0x08893390-0x08893444 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 func_08893444(s32, s32, s32, s32, s32);

void func_08893390(char *arg0) {
    s32 var_s1;
    u16 temp_a1;
    u8 temp_a5;
    char *var_s0;

    var_s1 = 0;
    if ((s32) *(u16 *)(arg0 + 0x11E) > 0) {
        var_s0 = arg0;
        do {
            temp_a1 = *(u16 *)(var_s0 + 0x22608);
            if (temp_a1 != 0) {
                temp_a5 = *(u8 *)(arg0 + 0x11A);
                func_08893444((s32) arg0, (s32) temp_a1, var_s1 / (s32) *(u16 *)(arg0 + 0x11C), *(u8 *)(arg0 + 0x118) * (var_s1 % (s32) temp_a5), *(u8 *)(arg0 + 0x119) * ((s32) (var_s1 / (s32) temp_a5) % (s32) *(u8 *)(arg0 + 0x11B)));
            }
            var_s1 += 1;
            var_s0 += 2;
        } while (var_s1 < (s32) *(u16 *)(arg0 + 0x11E));
    }
}
