/* unit_088578A0: 0x088578A0-0x0885793C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern u8 func_0884FB38(char *, s32);
extern s32 func_0884FAFC(char *, s32);
extern void func_0884FAC4(char *, s32);

void func_088578A0(char *arg0) {
    if (func_0884FB38(arg0, 0x25) == 1) {
        func_0884FAFC(arg0, 7);
        func_0884FAC4(arg0, 0x5D);
    } else {
        func_0884FAC4(arg0, 7);
        func_0884FAFC(arg0, 0x5D);
    }
    func_0884FAFC(arg0, 0x30);
    func_0884FAC4(arg0, 0x26);
    func_0884FAC4(arg0, 0x5E);
    func_0884FAC4(arg0, 0xCD);
}
