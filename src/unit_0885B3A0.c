/* unit_0885B3A0: 0x0885B3A0-0x0885B5B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885B3A0: one `void *` local holds the group range pointer of both
 * loops and the entry pointer of the second loop (it sets the s0 / s1 choice
 * of the second loop). */

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
    void *p;
    s32 a;
    Entry *e;
    s32 i;
    s32 n;

    a = (s16)arg1;
    p = &D_089A4E88[a];
    n = ((Range *)p)->count;
    if (n != 0) {
        e = &D_089A47D0[((Range *)p)->start];
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
        p = &D_089A4E88[i];
        n = ((Range *)p)->count;
        if (n == 0) {
            continue;
        }
        p = &D_089A47D0[((Range *)p)->start];
        for (; n > 0; n--, p = (Entry *)p + 1) {
            if (((Entry *)p)->id != (s16)arg1) {
                continue;
            }
            switch (mode) {
            case 1:
                return 1;
            case 0:
                if (func_0885B160(arg0, func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)), p, arg2) == 1) {
                    return 1;
                }
                break;
            case -1:
                if (!(((Entry *)p)->flags & 1)) {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}
