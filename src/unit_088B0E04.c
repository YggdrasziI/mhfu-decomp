/* unit_088B0E04: 0x088B0E04-0x088B0E2C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern int func_088B6A08(s32, s32, s32);

s32 func_088B0E04(s32 arg0, s32 arg1) {
    func_088B6A08(0, arg0, arg1);
    return 0;
}
