/* unit_088303E8: 0x088303E8-0x08830550 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088303E8 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern u16 func_08830550(void *arg0, char *arg1, s32 arg2, char *arg3);

u8 func_088303E8(void *arg0, char *arg1, s32 arg2, char *arg3) {
    s32 r;
    u16 hi;
    u16 lo;
    u16 t;

    if (arg1 != 0 && *(u16 *)(arg1 + 2) == 0) {
        arg1 = 0;
    }
    if (arg3 != 0 && *(u16 *)(arg3 + 2) == 0) {
        arg3 = 0;
    }
    r = func_08830550(arg0, arg1, arg2, arg3);
    if (arg1 != 0 && (arg2 & 0x100)) {
        return (u8)r;
    }
    hi = (u16)r & 0x8000;
    lo = r & 7;
    if (arg3 != 0) {
        r = func_08830550(arg0, arg3, arg2, arg1);
        if (arg2 & 0x100) {
            return (u8)r;
        }
        hi |= (u16)r & 0x8000;
        t = (u16)r & 7;
        if (lo < t) {
            lo = t;
        }
        if (hi != 0) {
            lo++;
        }
        return (u8)lo;
    }
    if ((arg2 & 0x10) || (hi != 0 && (arg2 & 0x20))) {
        lo++;
    }
    return (u8)lo;
}
