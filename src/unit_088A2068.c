/* unit_088A2068: 0x088A2068-0x088A20E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char D_09A0D258;
extern int func_088A177C(char *);
extern int func_088A178C(char *);
extern s32 func_088A20E4(char *, s32, s32);

s32 func_088A2068(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;

    func_088A177C(&D_09A0D258);
    temp_s0 = func_088A20E4(arg0, arg1, arg2);
    *(s32 *)(arg0 + 0x2C) = 1;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    func_088A178C(&D_09A0D258);
    return temp_s0;
}
