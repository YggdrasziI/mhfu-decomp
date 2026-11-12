/* unit_088B00DC: 0x088B00DC-0x088B012C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 func_088B0010(s32, s32);
extern void func_088B0084(void *, void *, s32);

void func_088B00DC(s32 arg0, char *arg1, s32 arg2) {
    func_088B0010(arg0, arg2);
    func_088B0084((char *) arg0, arg1, arg2);
}
