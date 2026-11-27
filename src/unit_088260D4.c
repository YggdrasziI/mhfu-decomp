/* unit_088260D4: 0x088260D4-0x0882619C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern s32 D_089CC438;
extern char *D_08A62D8C;
extern s8 func_088291B4(char *, s8, s32);
extern s32 func_08852F58(s32);
extern s32 func_08883988(void *, s32, s32, s32, s32, s32, s32, s32, u8);

void func_088260D4(char *arg0, s32 arg1) {
    s32 var_a2;
    s32 temp_a0;
    s32 temp_a1;
    s8 temp_v0;

    temp_a1 = *(s32 *)(arg0 + 0x5E8);
    *(s32 *)(arg0 + 0x5E8) = (s32) (temp_a1 & ~4);
    if (func_08852F58(D_089CC438) != 0) {
        temp_a0 = arg1 & 0xFFFF;
        if (temp_a0 & 0xA0) {
            if (!(temp_a0 & 0x80)) {
                var_a2 = 1;
            } else {
                var_a2 = -1;
            }
            temp_v0 = func_088291B4(arg0, *(s8 *)(arg0 + 0x5D9), var_a2);
            if (*(s8 *)(arg0 + 0x5D9) != temp_v0) {
                *(s8 *)(arg0 + 0x5D9) = temp_v0;
                func_08883988(D_08A62D8C, 0, 0x17, 0, 0, 0, 0, 0, 0U);
            }
        }
    } else {
        *(s8 *)(arg0 + 0x5D9) = -1;
    }
}
