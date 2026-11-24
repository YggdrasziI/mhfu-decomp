/* unit_088576BC: 0x088576BC-0x088577E0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern u8 func_0884FB38(char *, s32);
extern void func_0884FAC4(char *, s32);
extern void func_0884FAFC(char *, s32);
extern u8 func_08857A34(char *);
extern u8 func_09C19080(s32, s32);
extern u8 func_088579BC(char *);
extern void func_0885793C(char *);
extern s32 D_09CFB798;

void func_088576BC(char *arg0) {
    if (func_0884FB38(arg0, 0x25) == 1) {
        if (func_08857A34(arg0) == 1) {
            if (func_09C19080(D_09CFB798, 2) == 1) {
                if (func_0884FB38(arg0, 0x31) == 0) {
                    func_0884FAC4(arg0, 0x31);
                    func_0884FAC4(arg0, 0x30);
                    func_0884FAFC(arg0, 7);
                    func_0884FAFC(arg0, 0x5D);
                } else if (func_088579BC(arg0) == 0) {
                    func_0885793C(arg0);
                }
            } else {
                func_0885793C(arg0);
            }
        } else {
            func_0885793C(arg0);
        }
    } else {
        func_0884FAC4(arg0, 7);
        func_0884FAFC(arg0, 0x5D);
        func_0884FAFC(arg0, 0x30);
    }
}
