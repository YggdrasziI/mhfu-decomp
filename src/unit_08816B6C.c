/* unit_08816B6C: 0x08816B6C-0x08816BE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef int s32;

extern s32 D_089CBBEC;
extern char func_08816B24;
extern void func_08832838(s32);
extern int func_0890BE54(s32, char *, s32, s32);
extern int func_0890BFA4(s32);

s32 func_08816B6C(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        func_08832838(arg0);
        func_0890BE54(arg0 + 0xE28, &func_08816B24, 0x24, 0x14);
        if (arg0 != 0) {
            D_089CBBEC = 0;
        }
        if (arg1 > 0) {
            func_0890BFA4(arg0);
        }
    }
    return arg0;
}
