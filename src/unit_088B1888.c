/* unit_088B1888: 0x088B1888-0x088B1968 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1708 and unit_088B1968.
 *
 * Event 0x8004 when D_09A28876 is clear, 0x8031 in state 5, 0x8033 when
 * func_088B3424 rejects D_09A2887C. Otherwise registers func_088B2AAC as
 * handler 5; on failure sends event 0x8005, on success calls
 * func_088B7A50(5). Returns 0.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_09A2886C;
extern u8 D_09A28876;
extern char D_09A2887C[];

extern void func_088B2AAC(void);
extern void func_088B6A08(s32, s32, s32);
extern s32 func_088B6F64(s32, void (*)(void), s32, s32);
extern s32 func_088B3424(char *);
extern void func_088B7A50(s32);

s32 func_088B1888(s32 arg0, s32 arg1) {
    if (D_09A28876 == 0) {
        func_088B6A08(0x8004, arg0, arg1);
        return 0;
    }
    if (D_09A2886C == 5) {
        func_088B6A08(0x8031, arg0, arg1);
        return 0;
    }
    if (func_088B3424(D_09A2887C) == 0) {
        func_088B6A08(0x8033, arg0, arg1);
        return 0;
    }
    if (!func_088B6F64(5, func_088B2AAC, arg0, arg1)) {
        func_088B7A50(5);
        return 0;
    }
    func_088B6A08(0x8005, arg0, arg1);
    return 0;
}
