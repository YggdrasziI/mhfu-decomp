/* unit_0886D28C: 0x0886D28C-0x0886D2E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_089CBBEC;
extern u16 D_089AC5A6;
extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08830850(char *, char *);

void func_0886D28C(char *arg0) {
    char buf[128];

    func_0880E8F0(buf, func_0885151C(D_089CC438, D_089AC5A6), *(int *)(arg0 + 0x18));
    buf[127] = 0;
    func_08830850(D_089CBBEC, buf);
}
