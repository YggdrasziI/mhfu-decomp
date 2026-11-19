/* unit_088B1968: 0x088B1968-0x088B19CC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1888 and unit_088B19CC.
 *
 * Registers func_088B3130 as handler 6 with arg0 / arg1; when that fails,
 * sends event 0x8005 with the same arguments (as func_088B06C0). Returns 0.
 */

typedef int s32;

extern void func_088B3130(void);
extern s32 func_088B6F64(s32, void (*)(void), s32, s32);
extern void func_088B6A08(s32, s32, s32);

s32 func_088B1968(s32 arg0, s32 arg1) {
    if (!func_088B6F64(6, func_088B3130, arg0, arg1)) {
        return 0;
    }
    func_088B6A08(0x8005, arg0, arg1);
    return 0;
}
