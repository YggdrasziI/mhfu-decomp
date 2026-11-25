/* unit_0885E3D4: 0x0885E3D4-0x0885E478 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E3D4: when func_0885E244 accepts entry arg1, sets bit 0x10 and
 * clears bit 0x20 of its halfword flags at +0xAC (12-byte entries from
 * D_089CC438 + 0x4A0) if arg2 is 0, else clears bit 0x10. */

typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

extern u8 func_0885E244(s32, s16);

void func_0885E3D4(s32 arg0, s16 arg1, s32 arg2) {
    char *base = D_089CC438 + 0x4A0;

    if (func_0885E244(arg0, arg1) != 0) {
        if (arg2 == 0) {
            *(u16 *)((char *)(arg1 * 12) + (s32)base + 0xAC) |= 0x10;
            *(u16 *)((char *)(arg1 * 12) + (s32)base + 0xAC) &= ~0x20;
        } else {
            *(u16 *)((char *)(arg1 * 12) + (s32)base + 0xAC) &= ~0x10;
        }
    }
}
