/* unit_0885E348: 0x0885E348-0x0885E3D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885E348: when func_0885E244(arg0, arg1) holds, increments the 4-bit
 * counter (capped at 4) of the u16 at D_089CC438 + 0x4A0 + 0xAC + arg1 * 12,
 * keeping bits 4-7 and clearing the upper byte.
 * The counter must be one u16 local reused for the result (`n++`); a separate
 * local for the incremented value swaps the final `andi`s.
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

extern s32 func_0885E244(s32 arg0, s16 arg1);

void func_0885E348(s32 arg0, s16 arg1) {
    E12 *t = (E12 *)(D_089CC438 + 0x4A0);
    u16 v;

    if ((u8)func_0885E244(arg0, arg1)) {
        u16 n;

        v = ((E12 *)((char *)t + 0xAC))[arg1].f;
        n = v & 0xF;
        if (n >= 4) {
            n = 4;
        } else {
            n++;
        }
        ((E12 *)((char *)t + 0xAC))[arg1].f = (v & 0xF0) | n;
    }
}
