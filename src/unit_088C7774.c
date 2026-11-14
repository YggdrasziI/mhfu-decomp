/* unit_088C7774: 0x088C7774-0x088C77D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern char D_09CE4708;

s32 func_088C7774(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_a3;
    char *var_a2;
    char *temp_v0;

    temp_v0 = &D_09CE4708 + (*(u8 *)(D_089CC438 + 0x6AF10) * 8);
    temp_a0 = *(s32 *)temp_v0;
    var_a3 = 0;
    if (temp_a0 > 0) {
        var_a2 = (char *) (*(u16 **)(temp_v0 + 4));
loop_2:
        if ((arg1 & 0xFFFF) == *(u16 *)var_a2) {
            return var_a3 & 0xFF;
        }
        var_a3 += 1;
        var_a2 += 2;
        if (var_a3 >= temp_a0) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return 0;
}
