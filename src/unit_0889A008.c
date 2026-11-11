/* unit_0889A008: 0x0889A008-0x0889A024 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char func_0889A918;
extern int func_088B3BE4(char *, char *);

void func_0889A008(char *arg0) {
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 0x400);
    func_088B3BE4(&func_0889A918, arg0);
}
