/* unit_088A7F6C: 0x088A7F6C-0x088A8018 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern int func_088A84B4(char *, s32, s32);
extern s32 func_088AA9B4(s32, char *);

s32 func_088A7F6C(char *arg0) {
    s32 temp_a0;
    s32 var_s1;
    char *var_s0;

    *(s16 *)(arg0 + 0xDA) = 1;
    func_088AA9B4(-1, arg0 + 0xD8);
    *(s16 *)(arg0 + 0xDA) = 0;
    var_s1 = 0;
    if ((s32) *(u8 *)(arg0 + 0x22) > 0) {
        var_s0 = arg0;
        do {
            temp_a0 = *(s32 *)(var_s0 + 8);
            if ((temp_a0 >= 0) && (func_088AA9B4(temp_a0, arg0 + 0xD8) >= 0) && (*(s16 *)(arg0 + 0xD8) != 4)) {
                func_088A84B4(arg0, var_s1 & 0xFF, 6);
            }
            var_s1 += 1;
            var_s0 += 4;
        } while (var_s1 < (s32) *(u8 *)(arg0 + 0x22));
    }
    return 1;
}
