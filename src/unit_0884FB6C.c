/* unit_0884FB6C: 0x0884FB6C-0x0884FBA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_08A62C60;
extern s32 D_08A62C6C;
extern s32 D_08A62C74;

s32 func_0884FB6C(s32 arg0) {
    s32 var_v0;

    var_v0 = 0;
    if (*(u8 *)(D_08A62C60 + 0x74) == 0) {
        var_v0 = ((D_08A62C74 & 0xF0) | D_08A62C6C) & 0xFFFF;
    }
    return var_v0;
}
