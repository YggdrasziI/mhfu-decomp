/* unit_0886B8DC: 0x0886B8DC-0x0886B918 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

s32 func_0886B8DC(char *arg0) {
    s32 var_v1;
    u32 temp_hi;

    var_v1 = *(u16 *)(arg0 + 0x132);
    if (var_v1 == 0) {
        var_v1 = 1;
    }
    temp_hi = (u32) (var_v1 * 0xB0) % 65363U;
    *(u16 *)(arg0 + 0x132) = (u16) temp_hi;
    return temp_hi & 0xFFFF;
}
