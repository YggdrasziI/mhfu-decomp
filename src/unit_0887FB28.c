/* unit_0887FB28: 0x0887FB28-0x0887FBBC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_08A62D84;
extern s32 D_08A62D94;
extern s8 D_09A0DB44;
extern int func_088803E4(s32, s32);
extern int func_088803F0(s32, s32);
extern int func_088868A0(s32, s32);
extern int func_0889E9DC(s32);

void func_0887FB28(char *arg0, s32 arg1) {
    s32 var_s0;

    D_09A0DB44 = 0;
    var_s0 = arg1;
    if (arg1 >= 3) {
        D_09A0DB44 = 3;
        var_s0 = 1;
        func_088803E4(D_08A62D84, 1);
        func_088868A0(D_08A62D94, 1);
        func_088803F0(D_08A62D84, 1);
    }
    func_0889E9DC(var_s0);
    *(s32 *)(arg0 + 0x10) = arg1;
}
