/* unit_0885E528: 0x0885E528-0x0885E5C0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E528: when func_0885E244(arg0, arg1) holds, sets (arg2 == 0) or
 * clears (arg2 != 0) bit 0x40 of the u16 at D_089CC438 + 0x4A0 + 0xAC + arg1 * 12.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 f;
    char pad[10];
} E12;

extern char *D_089CC438;

extern s32 func_0885E244(s32 arg0, s32 arg1);

void func_0885E528(s32 arg0, s32 arg1, s32 arg2) {
    E12 *t = (E12 *)(D_089CC438 + 0x4A0);

    if ((u8)func_0885E244(arg0, arg1)) {
        if (arg2 == 0) {
            ((E12 *)((char *)t + 0xAC))[(s16)arg1].f |= 0x40;
        } else {
            ((E12 *)((char *)t + 0xAC))[(s16)arg1].f &= ~0x40;
        }
    }
}
