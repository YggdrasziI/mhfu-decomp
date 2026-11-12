/* unit_08882C9C: 0x08882C9C-0x08882CFC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 D_08A62D94;
extern u16 func_0888670C(s32, s32);

s32 func_08882C9C(s32 arg0, s32 arg1) {
    s32 var_s1;

    var_s1 = 0;
loop_1:
    if ((arg1 & 0xFFFF) == (func_0888670C(D_08A62D94, var_s1) & 0xFFFF)) {
        return var_s1;
    }
    var_s1 += 1;
    if (var_s1 >= 0x15) {
        return -1;
    }
    goto loop_1;
}
