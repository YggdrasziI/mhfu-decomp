/* unit_088C2B54: 0x088C2B54-0x088C2B94 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088C2168 (text_088C1828)
 * and unit_088C2B94 (NonMatching).
 *
 * Seeds the 16-bit keystream state i at +0xAA0 (D_089B4EE8[i] for a zero
 * seed).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

/* The decoder state: four 16-bit keystream states at +0xAA0. */
typedef struct {
    u8 pad0[0xAA0];
    u16 keys[4];
} Dec;

extern s32 D_089B4EE8[];

void func_088C2B54(Dec *arg0, s32 i, u16 seed) {
    if (seed != 0) {
        arg0->keys[i] = seed;
    } else {
        arg0->keys[i] = D_089B4EE8[i];
    }
}
