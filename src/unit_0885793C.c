/* unit_0885793C: 0x0885793C-0x088579BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned short u16;

extern char *D_08A631A0;
extern u16 func_088900C4(char *, s32);
extern void func_0884FAC4(char *, s32);
extern void func_0884FAFC(char *, s32);

void func_0885793C(char *arg0) {
    if (func_088900C4(D_08A631A0, 1) & 1) {
        func_0884FAFC(arg0, 7);
        func_0884FAC4(arg0, 0x5D);
    } else {
        func_0884FAC4(arg0, 7);
        func_0884FAFC(arg0, 0x5D);
    }
    func_0884FAFC(arg0, 0x30);
}
