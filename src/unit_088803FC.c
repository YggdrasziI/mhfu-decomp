/* unit_088803FC: 0x088803FC-0x08880498 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62D8C;
extern void func_0888637C(char *);
extern void func_0887F794(char *);
extern void func_08885D80(char *);
extern void func_08881824(char *);
extern void func_08883374(char *);

char *func_088803FC(char *arg0) {
    D_08A62D8C = (s32) arg0;
    func_0888637C(arg0);
    func_0887F794(arg0 + 0x988 + 0x7FF8);
    func_08885D80(arg0 + 0xB08 + 0x7FF8);
    func_08881824(arg0);
    func_08883374(arg0);
    *(s32 *) (arg0 + 0x5623D0) = 7;
    *(s32 *) (arg0 + 0x5623D4) = 7;
    *(s32 *) (arg0 + 0x308BC0) = -1;
    *(char *) (arg0 + 0x562420) = 0;
    *(char *) (arg0 + 0x562421) = 0;
    return arg0;
}
