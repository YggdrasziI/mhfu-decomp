/* unit_088C2B94: 0x088C2B94-0x088C2BE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C2B54 and unit_088C2BE0.
 *
 * Steps the keystream state i at +0xAA0: times D_089B4EE8[i] modulo
 * D_089B4EF8[i].
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

/* The decoder state: four 16-bit keystream states at +0xAA0. */
typedef struct {
    u8 pad0[0xAA0];
    u16 keys[4];
} Dec;

extern s32 D_089B4EE8[];
extern u32 D_089B4EF8[];

u16 func_088C2B94(Dec *arg0, s32 i) {
    u16 *p = (u16 *) ((char *) arg0 + 0xAA0) + i;
    u32 v = *p;

    v *= D_089B4EE8[i];
    v %= D_089B4EF8[i];
    *p = v;
    return *p;
}
