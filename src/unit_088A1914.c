/* unit_088A1914: 0x088A1914-0x088A198C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A0D258;
extern int func_088A177C(char *);
extern int func_088A178C(char *);
extern s32 func_088A198C(s32, s32, s32, s32);

s32 func_088A1914(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;

    func_088A177C(&D_09A0D258);
    temp_s0 = func_088A198C(arg0, arg1, arg2, arg3);
    func_088A178C(&D_09A0D258);
    return temp_s0;
}
