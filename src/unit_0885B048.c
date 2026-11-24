/* unit_0885B048: 0x0885B048-0x0885B160 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885B048
 *
 * Speed setting: the 0xAC-entry loop counts down an unsigned counter.
 * The u8 parameter is tested with `!mode` (no mask before the bnez); the
 * selection is a switch so the else value is masked from the shared 1.
 * func_0885B160 keeps its src/ prototype; its result is read as (u8). */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[6];
    u8 bit;
    u8 flags;
    u8 pad8[2];
} Entry;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern Entry D_089A47D0[];

extern char *func_088DCEBC(s32, u8);
extern s32 func_0885B160(s32, s32, char *, s32);

u16 func_0885B048(s32 arg0, u8 mode) {
    u8 *base;
    char *p;
    u16 n;
    Entry *e;
    unsigned int i;

    base = (u8 *)D_089CC438 + 0x4A0;
    p = func_088DCEBC(D_09A4F0C4, D_089CC438[0x28]);
    if (!mode) {
        switch ((u8)func_0885B160(arg0, (s32)p, 0, 0)) {
        case 1:
            mode = 2;
            break;
        default:
            mode = 1;
            break;
        }
    }
    n = 0;
    e = D_089A47D0;
    for (i = 0xAC; i != 0; i--, e++) {
        if ((base + 0x3FCC)[e->bit >> 3] & (1 << (e->bit & 7))) {
            if (mode == 1) {
                if (!(e->flags & 1)) {
                    n++;
                }
            } else if (mode == 3) {
                if ((e->flags & 1) == 1) {
                    n++;
                }
            } else {
                n++;
            }
        }
    }
    return n;
}
