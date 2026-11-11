/* unit_088984B8: 0x088984B8-0x08898510 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_08A8B1E8;
extern int func_08859AE4(char *, char *, s32);

char *func_088984B8(char *arg0) {
    D_08A8B1E8 = arg0;
    *(s32 *)arg0 = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0xC) = 0;
    func_08859AE4(arg0 + 0x14010, arg0 + 0x10, 0x14000);
    return arg0;
}
