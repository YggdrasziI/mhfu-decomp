/* unit_08853ABC: 0x08853ABC-0x08853C88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u16 id;
    s16 count;
} Item;

extern u8 D_0899D19B[];
extern char *D_08A62C50;
extern s16 func_08850EC4(char *arg0);
extern void func_0885ACA0(char *, s32);

u16 func_08853ABC(char *arg0, s32 id, u16 count, u16 slot) {
    char *base;
    Item *e;
    u32 max;
    s32 n;
    s32 i;
    u32 diff;
    s16 *c;

    base = arg0 + 0x4A0;
    n = func_08850EC4(arg0);
    max = D_0899D19B[(id & 0xFFFF) * 24];
    if (max != 0xFF) {
        max = 99;
    }
    if (max < count) {
        count = max;
    }
    if (max != 0xFF) {
        e = (Item *)(base + 0x2F88);
        if (slot != 0xFFFF && e[slot].id == (u16)id) {
            diff = max - e[slot].count;
            c = &e[slot].count;
            if (diff >= count) {
                *c = *c + (s16)count;
                func_0885ACA0(D_08A62C50, id);
                return 0;
            }
            count -= (u16)diff;
            *c = max;
        }
        for (i = n; i != 0; i--, e++) {
            if (e->id == (u16)id && (u32)e->count < max) {
                diff = max - e->count;
                if (diff >= count) {
                    e->count = e->count + (s16)count;
                    func_0885ACA0(D_08A62C50, id);
                    return 0;
                }
                count -= (u16)diff;
                e->count = max;
            }
        }
    }
    e = (Item *)(base + 0x2F88);
    for (; n != 0; n--, e++) {
        if (e->id == 0) {
            e->id = id;
            e->count = count;
            func_0885ACA0(D_08A62C50, id);
            return 0;
        }
    }
    return count;
}
