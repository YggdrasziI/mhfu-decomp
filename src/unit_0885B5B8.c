/* unit_0885B5B8: 0x0885B5B8-0x0885B718 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

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

Entry *func_0885B5B8(s32 arg0, s16 a, s16 b, s32 arg3, s32 arg4, s32 arg5) {
    Entry *e;
    s32 n;
    Range *r;
    s16 t;

    if (a > b) {
        t = b;
        b = a;
        a = t;
    }
    r = &D_089A4E88[a];
    n = r->count;
    if (n == 0) {
        return 0;
    }
    e = &D_089A47D0[r->start];
    if (n != 0) do {
        if (e->id != b) {
            goto next;
        }
        if (arg3 & 1) {
            return e;
        }
        switch (arg5) {
        case 1:
            return e;
        case 0:
            if (func_0885B160(arg0, func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)), e, arg4) == 1) {
                return e;
            }
            break;
        case -1:
            if (!(e->flags & 1)) {
                return e;
            }
            break;
        }
    next:
        n--;
        e++;
    } while (n != 0);
    return 0;
}
