/* unit_088A9F4C: 0x088A9F4C-0x088A9FF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern char D_09A1D5D0;
extern u8 D_09A1D5F3;
extern char D_09A1D638;
extern char D_09A1D700;
extern int func_088A84B4(void *, s32, s32);
extern s32 func_088A86BC(s32, s32);

void func_088A9F4C(char *arg0) {
    s32 var_a1;
    s32 var_v0;

    var_a1 = (int) (arg0);
    if (*((u8 *)&D_09A1D638 + D_09A1D5F3) == 3) {
        if (!(var_a1 & 0xFF)) {
            var_v0 = (u32) *(f32 *)((char *)(&D_09A1D700) + 4);
            var_a1 = var_v0 & 0xFF;
        }
        func_088A86BC((s32) &D_09A1D5D0, var_a1);
        func_088A84B4(&D_09A1D5D0, (s32) D_09A1D5F3, 4);
    }
}
