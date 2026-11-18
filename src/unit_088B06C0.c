/* unit_088B06C0: 0x088B06C0-0x088B0724 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0604 and unit_088B0724.
 *
 * Registers func_088ADF58 as handler 1 (func_088B6F64) with arg0 / arg1; when
 * that fails, sends event 0x8005 with the same arguments (func_088B6A08).
 * Returns 0.
 */

typedef int s32;

extern void func_088ADF58(void);
extern s32 func_088B6F64(s32, void (*)(void), s32, s32);
extern void func_088B6A08(s32, s32, s32);

s32 func_088B06C0(s32 arg0, s32 arg1) {
    if (!func_088B6F64(1, func_088ADF58, arg0, arg1)) {
        return 0;
    }
    func_088B6A08(0x8005, arg0, arg1);
    return 0;
}
