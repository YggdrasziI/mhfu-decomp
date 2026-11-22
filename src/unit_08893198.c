/* unit_08893198: 0x08893198-0x088932A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u16 func_088932A8(char *);

s32 func_08893198(char *arg0, u16 arg1) {
    u16 *slot;
    u16 idx;

    if (arg1 >= 0xFFF0) {
        return 0;
    }
    slot = &((u16 *)(arg0 + 0x2628))[arg1];
    idx = *slot;
    if (idx != 0xFFFF) {
        (arg0 + 0x22968)[idx] = 2;
        return 0;
    }
    *(u16 *)(arg0 + 0x158) = func_088932A8(arg0);
    *slot = *(u16 *)(arg0 + 0x158);
    ((u16 *)(arg0 + 0x22608))[*(u16 *)(arg0 + 0x158)] = arg1;
    (arg0 + 0x22968)[*(u16 *)(arg0 + 0x158)] = 2;
    *(u16 *)(arg0 + 0x15A) += 1;
    if (*(u16 *)(arg0 + 0x15A) > *(u16 *)(arg0 + 0x11E)) {
        *(u16 *)(arg0 + 0x15A) = *(u16 *)(arg0 + 0x11E);
    }
    if (*(u16 *)(arg0 + 0x15A) < *(u16 *)(arg0 + 0x11E)) {
        *(u16 *)(arg0 + 0x158) += 1;
    }
    return 1;
}
