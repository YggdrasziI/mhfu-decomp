/* unit_088577E0: 0x088577E0-0x088578A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_0884FAC4(s32, s32);
extern s32 func_0884FAFC(s32, s32);
extern s32 func_0884FB38(s32, s32);
extern s32 func_08857A34(s32);
extern s32 func_08857A80(s32, s32);

void func_088577E0(s32 arg0) {
    if (((func_08857A34(arg0) & 0xFF) == 1) && ((func_0884FB38(arg0, 0x25) & 0xFF) == 1) && ((func_08857A80(arg0, 2) & 0xFF) == 1) && !(func_0884FB38(arg0, 0x31) & 0xFF)) {
        func_0884FAC4(arg0, 0x31);
        func_0884FAC4(arg0, 0x30);
        func_0884FAFC(arg0, 7);
        func_0884FAFC(arg0, 0x5D);
        func_0884FAC4(arg0, 0x32);
    }
}
