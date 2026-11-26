/* unit_088268E0: 0x088268E0-0x0882693C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

s32 func_088268E0(u8 *arg0, u16 *arg1) {
    u16 n;

    if (arg0[0x52F] != 0) {
        return 0;
    }
    if (*(s16 *)(arg0 + 0x119E) <= 0) {
        n = *(u16 *)(arg0 + 0x119C) + 1;
        *(u16 *)(arg0 + 0x119C) = n;
        *arg1 = n;
        *(s16 *)(arg0 + 0x119E) = 4;
        return 1;
    }
    if (*arg1 == *(u16 *)(arg0 + 0x119C)) {
        *(s16 *)(arg0 + 0x119E) = 4;
        return 1;
    }
    return 0;
}
