/* unit_088B012C: 0x088B012C-0x088B01BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0118 and unit_088B01BC.
 * The initializer of the local `any` (6 bytes at 0x089B2A2C) is the unit's
 * .data. func_088ADA44 is declared with its own parameter types: a `u8`
 * last parameter loads the global first argument before the others.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_09A202D0;

extern void memcpy(void *dst, const void *src, int size);
/* Prototype of src/unit_088ADA44.c: the u16 last parameter puts the loads of
 * the last three arguments before the load of D_09A202D0. */
extern s32 func_088ADA44(s32 id, u8 *mac, u16 port, void *data, s16 len, u16 count);

s32 func_088B012C(char *arg0) {
    s8 any[6] = {-1, -1, -1, -1, -1, -1};
    u8 addr[16];
    s32 ret;

    memcpy(addr, any, 6);
    ret = func_088ADA44(D_09A202D0, addr, 0x2710, arg0 + 4, *(u16 *)arg0 + 0x14, *(u8 *)(arg0 + 0x14));
    if (ret < 0) {
        return ret;
    }
    return 0;
}
