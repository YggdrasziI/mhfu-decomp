/* unit_088D2E04: 0x088D2E04-0x088D2E18 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern void func_088D2E18(char *, char *, s32, s32);

void func_088D2E04(char *arg0) {
    func_088D2E18(arg0, arg0 + 0xa10, *(s32 *)(arg0 + 0x190) + 0x2f10, *(s32 *)(arg0 + 0x190) + 0x17f0);
}
