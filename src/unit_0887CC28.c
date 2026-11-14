/* unit_0887CC28: 0x0887CC28-0x0887CCAC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char D_089A898C;
extern s32 D_089CC438;
extern u16 func_0884FF38(s32, s32);

s32 func_0887CC28(void) {
    char sp18[0x58];
    char *var_a2;
    char *var_a1;
    char *var_s0;
    s16 temp_v1;
    s32 var_a0;

    var_a2 = &D_089A898C;
    var_a1 = sp18;
    var_a0 = 0x16;
    do {
        var_a0 -= 1;
        *(s16 *)var_a1 = *(s16 *)var_a2;
        *(s16 *)(var_a1 + 2) = (s16) *(s16 *)(var_a2 + 2);
        var_a2 += 4;
        var_a1 += 4;
    } while (var_a0 > 0);
    var_s0 = sp18;
loop_3:
    temp_v1 = *(s16 *)var_s0;
    if (temp_v1 == -1) {
        return 1;
    }
    if (!(func_0884FF38(D_089CC438, temp_v1 & 0xFF) & 0xFFFF)) {
        return 0;
    }
    var_s0 += 2;
    goto loop_3;
}
