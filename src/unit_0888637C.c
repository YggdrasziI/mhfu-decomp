/* unit_0888637C: 0x0888637C-0x088863BC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_08A62D94;
extern void func_08886568(char *);
extern int func_088865D0(char *);

char *func_0888637C(char *arg0) {
    D_08A62D94 = arg0;
    *(s32 *)arg0 = 0;
    *(s32 *)(arg0 + 0x18) = 0;
    func_08886568(arg0);
    func_088865D0(arg0);
    return arg0;
}
