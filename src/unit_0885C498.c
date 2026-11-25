/* unit_0885C498: 0x0885C498-0x0885C580 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885C498: for item arg1 (low 16 bits; -1 for item 0), walks the
 * func_08850EC4() slots at D_089CC438 + 0x4A0 + 0x2F88 (u16 id, s16 count)
 * and returns the cap minus the room left: the cap is 99 unless the
 * D_0899D19B[id * 24] byte is 0xFF (then that byte, and no deduction).
 * Stops at the first empty slot or once the room reaches 0 (returns the cap).
 *
 * Speed setting (pointer stepped, loop guarded and tested at the bottom).
 * s32 arg1 masked at each use, the table index written `(u16)arg1` and the
 * other uses `arg1 & 0xFFFF` (keeps the s2 copy and the v1 index copy).
 * The cap is reassigned with the room: `r = max = 99;`. Declaration order
 * p, max, e, n, r sets the a1/a2/a3 registers.
 */

#pragma optimize_for_size off

typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 id;
    s16 val;
} Slot;

extern char *D_089CC438;
extern u8 D_0899D19B[];

extern s16 func_08850EC4(char *arg0);

s32 func_0885C498(s32 arg0, s32 arg1) {
    char *p;
    s32 max;
    Slot *e;
    s32 n;
    s32 r;

    p = D_089CC438 + 0x4A0;
    if ((arg1 & 0xFFFF) == 0) {
        return -1;
    }
    n = func_08850EC4(D_089CC438);
    max = D_0899D19B[(u16)arg1 * 24];
    r = max;
    if (max != 0xFF) {
        r = max = 99;
    }
    for (e = (Slot *)(p + 0x2F88); n > 0; n--, e++) {
        if (e->id == 0) {
            return max;
        }
        if (e->id == (arg1 & 0xFFFF) && max != 0xFF) {
            r -= max - e->val;
            if (r <= 0) {
                return max;
            }
        }
    }
    return max - r;
}
