/* unit_0885B3A0: 0x0885B3A0-0x0885B5B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * NonMatching: compiled for the report only, the code stays in assembly.
 */

/* func_0885B3A0: NonMatching (99.44 %: in the second loop's inner part the group count and the entry pointer have s0 / s1 swapped). */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;

typedef struct {
    s16 id;
    u8 pad2[5];
    u8 flags;
    u8 pad8[2];
} Entry;

typedef struct {
    u8 count;
    u8 start;
} Range;

extern Range D_089A4E88[];
extern Entry D_089A47D0[];
extern char *D_089CC438;
extern s32 D_09A4F0C4;

extern s32 func_088DCEBC(s32, u8);
extern u8 func_0885B160(s32, s32, Entry *, s32);

s32 func_0885B3A0(s32 arg0, s32 arg1, s32 arg2, s32 mode) {
    s32 a;
    Entry *e;
    s32 n;
    s32 i;
    Range *r;

    a = (s16)arg1;
    r = &D_089A4E88[a];
    n = r->count;
    if (n != 0) {
        e = &D_089A47D0[r->start];
        for (; n > 0; n--, e++) {
            switch (mode) {
            case 1:
                return 1;
            case 0:
                if (func_0885B160(arg0, func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)), e, arg2) == 1) {
                    return 1;
                }
                break;
            case -1:
                if (!(e->flags & 1)) {
                    return 1;
                }
                break;
            }
        }
    }
    for (i = 0; i < (s16)arg1; i++) {
        r = &D_089A4E88[i];
        n = r->count;
        if (n == 0) {
            continue;
        }
        e = &D_089A47D0[r->start];
        for (; n > 0; n--, e++) {
            if (e->id != (s16)arg1) {
                continue;
            }
            switch (mode) {
            case 1:
                return 1;
            case 0:
                if (func_0885B160(arg0, func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)), e, arg2) == 1) {
                    return 1;
                }
                break;
            case -1:
                if (!(e->flags & 1)) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}
