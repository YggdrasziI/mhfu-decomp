/* unit_088AA0BC: 0x088AA0BC-0x088AA14C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern char D_09A1D5D0;
extern char D_09A1D5E8;
extern s32 D_09A1D5EC;
extern s8 D_09A1D5F1;
extern u8 D_09A1D5F2;
extern int func_088A84B4(char *, s32, s32);
extern int func_088AAE10(char *);
extern int func_088AB028(char *);

void func_088AA0BC(void) {
    char *var_s1;
    s32 var_s0;

    D_09A1D5F1 = 8;
    D_09A1D5EC = 0;
    var_s0 = 0;
    if ((s32) D_09A1D5F2 > 0) {
        var_s1 = &D_09A1D5D0;
        do {
            func_088A84B4(&D_09A1D5D0, var_s0 & 0xFF, 0);
            func_088AAE10(var_s1 + 8);
            var_s0 += 1;
            var_s1 += 4;
        } while (var_s0 < (s32) D_09A1D5F2);
    }
    func_088AB028(&D_09A1D5E8);
}
