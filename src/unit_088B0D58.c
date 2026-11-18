/* unit_088B0D58: 0x088B0D58-0x088B0DBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0D2C and unit_088B0DBC.
 *
 * Registers func_088B0F30 as handler 4 (func_088B6F64) with arg0 / arg1;
 * when that fails, sends event 0x8005 with the same arguments
 * (func_088B6A08). Returns 0.
 */

typedef int s32;

extern void func_088B0F30(void);
extern s32 func_088B6F64(s32, void (*)(void), s32, s32);
extern void func_088B6A08(s32, s32, s32);

s32 func_088B0D58(s32 arg0, s32 arg1) {
    if (!func_088B6F64(4, func_088B0F30, arg0, arg1)) {
        return 0;
    }
    func_088B6A08(0x8005, arg0, arg1);
    return 0;
}
