/* unit_088B089C: 0x088B089C-0x088B0938 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088B0724 (still in
 * assembly) and unit_088B0938.
 *
 * Registers func_088AE0D4 as handler 2 (func_088B6F64) with arg1 / arg2
 * and keeps the 12 bytes arg0 at D_09A28944; when the registration fails,
 * sends event 0x8005 with arg1 / arg2 (func_088B6A08). Returns 0.
 */

typedef signed char s8;
typedef int s32;

typedef struct {
    s8 b[12];
} Bytes12;

extern Bytes12 D_09A28944;

extern void func_088AE0D4(void);
extern s32 func_088B6F64(s32, void (*)(void), s32, s32);
extern void func_088B6A08(s32, s32, s32);

s32 func_088B089C(Bytes12 *arg0, s32 arg1, s32 arg2) {
    if (!func_088B6F64(2, func_088AE0D4, arg1, arg2)) {
        D_09A28944 = *arg0;
        return 0;
    }
    func_088B6A08(0x8005, arg1, arg2);
    return 0;
}
