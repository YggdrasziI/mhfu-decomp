/* unit_0885028C: 0x0885028C-0x088503F8 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char D_0899BF40;
extern s32 func_0884FFB8(s32, s32);
extern s32 func_0884FFCC(s32, s32);

s32 func_0885028C(s32 arg0, s32 arg1, u8 *arg2) {
    s32 temp_v1;
    s32 var_s1;
    u8 *var_s0;
    u8 var_v1;

    var_s0 = (unsigned char *) (((s32 *)&D_0899BF40)[(arg1 & 0xFF)]);
    var_v1 = *var_s0;
    var_s1 = 0;
    if (var_v1 != 0xFF) {
        do {
            temp_v1 = func_0884FFB8(arg0, var_v1 & 0xFF) & 0xFFFF;
            if ((var_s1 & 0xFFFF) < temp_v1) {
                var_s1 = temp_v1;
                if (arg2 != 0) {
                    *arg2 = *var_s0;
                }
            }
            var_s0 += 1;
            var_v1 = *var_s0;
        } while (var_v1 != 0xFF);
    }
    return var_s1;
}

s32 func_08850338(s32 arg0, s32 arg1, u8 *arg2) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s1;
    u8 *var_s0;
    u8 var_v1;

    var_s0 = (unsigned char *) (((s32 *)&D_0899BF40)[(arg1 & 0xFF)]);
    var_v1 = *var_s0;
    var_s1 = 0;
    if (var_v1 != 0xFF) {
        do {
            temp_v1 = func_0884FFCC(arg0, var_v1 & 0xFF) & 0xFFFF;
            if ((temp_v1 != 0) && ((temp_v0 = var_s1 & 0xFFFF, (temp_v0 == 0)) || (temp_v1 < temp_v0))) {
                var_s1 = temp_v1 & 0xFFFF;
                if (arg2 != 0) {
                    *arg2 = *var_s0;
                }
            }
            var_s0 += 1;
            var_v1 = *var_s0;
        } while (var_v1 != 0xFF);
    }
    return var_s1;
}
