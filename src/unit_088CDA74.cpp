/* unit_088CDA74: 0x088CDA74-0x088CDBF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function of the former text_088CD964 asm piece
 * (0x088CD964-0x088CDCB0), split around func_088CDA74.
 *
 * Tests the four 0x8C-byte entries of D_089CC438 against the bit mask at
 * 0x98.
 *
 * C++: the flag tests are bool conversions.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern "C" {

extern char *D_089CC438;
extern char *D_089CBBE4;
extern char *D_08A631A0;
extern s32 D_08A62C6C;
extern s32 D_09A1DAEC;
extern s32 func_08813DD8(char *);
extern void func_088AB514(s32, s32, s32);

/* The 0x9A test wraps the rest so that it is the first branch to the shared
 * `return 0` (filled `beql`); the later tests keep their `nop`. */
u8 func_088CDA74(char *arg0) {
    s32 bit;
    u8 ok;
    s32 i;

    if (func_08813DD8(D_089CBBE4) <= 0) {
        return 1;
    }
    if (*(u8 *)(arg0 + 0x9A) != 0) {
        if ((bool) (*(u32 *)(D_08A631A0 + 0xF7A57C) & 1) == 0) {
            if ((D_08A62C6C & 1) && *(u8 *)(D_089CC438 + 0x480) == 0) {
                *(u8 *)(arg0 + 0x99) = 1;
                return 1;
            }
        } else {
            bit = 1 << *(u8 *)(D_089CC438 + 0x28);
            if ((*(u8 *)(arg0 + 0x98) & bit) == 0 && (D_08A62C6C & 1)) {
                *(u8 *)(arg0 + 0x98) |= (u8) bit;
                func_088AB514(D_09A1DAEC, 0xD, 0);
            }
            ok = 1;
            i = 0;
            do {
                if ((bool) *(u8 *)(D_089CC438 + (u8) i * 0x8C + 0x30) != 0) {
                    if ((*(u8 *)(arg0 + 0x98) & (1 << i)) == 0) {
                        ok = 0;
                    }
                }
                i++;
            } while (i < 4);
            if (ok == 1) {
                *(u8 *)(arg0 + 0x99) = 1;
            }
            return ok;
        }
    }
    return 0;
}

}
