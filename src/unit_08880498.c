/* unit_08880498: 0x08880498-0x0888051C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_08A62D8C;
extern s32 func_0887F7F8(s32, s16);
extern s32 func_08885DB0(s32, s16);
extern s32 func_088863BC(s32, s16);
extern int func_0890BFA4(s32);

s32 func_08880498(char *arg0, s16 arg1) {
    if (arg0 != 0) {
        func_08885DB0((int) (arg0 + 0xB08 + 0x7FF8), -1);
        func_0887F7F8((int) (arg0 + 0x988 + 0x7FF8), -1);
        func_088863BC((int) (arg0), -1);
        if (arg0 != 0) {
            D_08A62D8C = 0;
        }
        if (arg1 > 0) {
            func_0890BFA4((int) (arg0));
        }
    }
    return (int) (arg0);
}
