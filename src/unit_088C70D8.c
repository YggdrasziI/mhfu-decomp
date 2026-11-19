/* unit_088C70D8: 0x088C70D8-0x088C7130 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088C70D8 asm piece, 1 function
 * between unit_088C6DF8 and unit_088C7130.
 *
 * Reserves a size rounded up to 16 bytes from a buffer of the object of
 * unit_088C6ADC (base at 0xA2BC, used size at 0xA2C0) and returns its address.
 */

typedef int s32;

typedef struct Obj {
    char pad0[0xA2BC];
    char *unkA2BC;
    s32 unkA2C0;
} Obj;

char *func_088C70D8(Obj *arg0, s32 size) {
    s32 r;
    char *base;

    r = size % 16;
    if (r != 0) {
        size += 16 - r;
    }
    base = arg0->unkA2BC + arg0->unkA2C0;
    arg0->unkA2C0 += size;
    return base;
}
