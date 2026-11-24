/* unit_0885AF28: 0x0885AF28-0x0885AFF8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885AF28: looks up arg1 in the 24 (id, val) pairs at
 * D_089CC438 + 0x4A0 + 0x3F28. Found: 0xFF if the table byte
 * D_0899D19B[id * 24] is 0xFF, else that byte minus val (s16). Not found:
 * the table byte if a free (id 0) slot exists, else -1.
 * Speed setting (strength-reduced loop offset) and
 * opt_rebuildconditionals off (0xFF return branches straight to the end
 * instead of sharing the seh of the other return).
 */

#pragma optimize_for_size off
#pragma opt_rebuildconditionals off

typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 id;
    s16 val;
} Entry;

typedef struct {
    char pad[0x3F28];
    Entry ent[24];
} Work;

extern char *D_089CC438;
extern u8 D_0899D19B[];

s32 func_0885AF28(s32 arg0, s32 arg1) {
    s16 i;
    s16 n;
    Work *base;

    base = (Work *)(D_089CC438 + 0x4A0);
    n = 0;
    i = 0;
    do {
        if (base->ent[i].id == (u16)arg1) {
            u8 b = D_0899D19B[(arg1 & 0xFFFF) * 24];
            if (b == 0xFF) {
                return 0xFF;
            }
            return (s16)(b - base->ent[i].val);
        }
        if (base->ent[i].id == 0) {
            n++;
        }
        i++;
    } while (i < 24);
    {
        s32 r;
        if (n) {
            r = D_0899D19B[(u16)(arg1 & 0xFFFF) * 24];
        } else {
            r = -1;
        }
        return r;
    }
}
