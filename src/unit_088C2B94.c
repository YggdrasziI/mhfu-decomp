/* unit_088C2B94: 0x088C2B94-0x088C2BE0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088C2B54 and unit_088C2BE0.
 *
 * Steps the keystream state i at +0xAA0: times D_089B4EE8[i] modulo
 * D_089B4EF8[i].
 *
 * NonMatching: the image keeps the original code.
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

/* NonMatching, 98.68 %: the original builds i * 4 in $a0 (arg0 dead) and
 * loads the state into $a1; ours reuses $a1 for i * 4 and loads into $a0.
 * Tried: the state through the structure member, pointers formed five
 * ways, a u32 index, an s32 return, the state in a local. */
u16 func_088C2B94(Dec *arg0, s32 i) {
    u16 *p;

    p = (u16 *) ((char *) arg0 + 0xAA0) + i;
    *p = (*p * D_089B4EE8[i]) % D_089B4EF8[i];
    return *p;
}
