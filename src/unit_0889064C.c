/* unit_0889064C: 0x0889064C-0x088906A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern char *D_08A631A0;
extern void func_08890544(char *arg0);

s32 func_0889064C(s32 arg0, s32 arg1, s32 arg2, char *arg3) {
    func_08890544(D_08A631A0);
    *(s32 *)(arg3 + 0xF7F02C) += 1;
    if (*(s32 *)(arg3 + 0xF7F02C) < 2) {
        return 0x411A;
    }
    return 0;
}
