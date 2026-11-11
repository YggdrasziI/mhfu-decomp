/* unit_0883D66C: 0x0883D66C-0x0883D6D0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char D_08930BDC;
extern s32 D_089CC438;
extern int func_08852EE0(s32, u8);

void func_0883D66C(s32 arg0, s32 arg1) {
    char *var_s2;
    s32 var_s1;

    var_s2 = &D_08930BDC;
    var_s1 = 0x3E;
    do {
        if (*(u16 *)(var_s2 + 0xA) == (arg1 & 0xFFFF)) {
            func_08852EE0(D_089CC438, *(u8 *)var_s2);
        }
        var_s1 -= 1;
        var_s2 += 0xE;
    } while (var_s1 > 0);
}
