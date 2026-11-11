/* unit_088A0AB0: 0x088A0AB0-0x088A0AFC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

s16 func_088A0AFC(u32);

s32 func_088A0AB0(char *arg0) {
    s32 temp_lo;
    s32 var_v0;

    temp_lo = *(u16 *)(arg0 + 6) * func_088A0AFC((u32) *(u32 *)arg0 >> 8);
    var_v0 = temp_lo >> 0xF;
    if (temp_lo < 0) {
        var_v0 = (s32) (temp_lo + 0x7FFF) >> 0xF;
    }
    return var_v0;
}
