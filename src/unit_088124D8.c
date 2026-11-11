/* unit_088124D8: 0x088124D8-0x088125A4 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef int s32;
typedef unsigned int u32;

void func_088124D8(s32 arg0, u32 arg1, s32 arg2) {
    s32 temp_t0;
    s32 var_v1;
    u32 temp_t2;
    u32 var_a1;
    char *temp_a3;

    var_a1 = arg1;
    temp_t2 = var_a1 + arg2;
    if (var_a1 < temp_t2) {
        do {
            temp_t0 = 1 << ((s32) var_a1 % 32);
            var_v1 = (s32) var_a1 >> 5;
            if ((s32) var_a1 < 0) {
                var_v1 = (s32) (var_a1 + 0x1F) >> 5;
            }
            temp_a3 = (char *) (arg0 + (var_v1 * 4));
            var_a1 += 1;
            *(s32 *)(temp_a3 + 0x458) = (s32) (*(s32 *)(temp_a3 + 0x458) | temp_t0);
        } while (var_a1 < temp_t2);
    }
}

void func_0881253C(s32 arg0, u32 arg1, s32 arg2) {
    s32 temp_t0;
    s32 var_v1;
    u32 temp_t2;
    u32 var_a1;
    char *temp_a3;

    var_a1 = arg1;
    temp_t2 = var_a1 + arg2;
    if (var_a1 < temp_t2) {
        do {
            temp_t0 = ~(1 << ((s32) var_a1 % 32));
            var_v1 = (s32) var_a1 >> 5;
            if ((s32) var_a1 < 0) {
                var_v1 = (s32) (var_a1 + 0x1F) >> 5;
            }
            temp_a3 = (char *) (arg0 + (var_v1 * 4));
            var_a1 += 1;
            *(s32 *)(temp_a3 + 0x458) = (s32) (*(s32 *)(temp_a3 + 0x458) & temp_t0);
        } while (var_a1 < temp_t2);
    }
}
