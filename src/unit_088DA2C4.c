/* unit_088DA2C4: 0x088DA2C4-0x088DA324 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 D_089CC438;
extern s32 func_0885187C(s32, s32, s32);

void func_088DA2C4(char *arg0) {
    s32 temp_v0;
    s32 var_s1;
    char *var_s0;

    var_s1 = 0;
    var_s0 = arg0;
    do {
        temp_v0 = func_0885187C(D_089CC438, (s32) *(u16 *)(arg0 + 0x1E6), var_s1);
        var_s1 += 1;
        *(s16 *)(var_s0 + 0x536) = (s16) temp_v0;
        var_s0 += 2;
    } while (var_s1 < 6);
}
