/* unit_088DE0B8: 0x088DE0B8-0x088DE3D4 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between func_088DE060 and
 * func_088DE3D4, both still in assembly (text_088DE060, text_088DE3D4).
 *
 * Requests in the resource table (unit_088DD8A8): func_088DE0B8 loads the
 * resource of id `arg1 + 0x17DF` into entry `9 + arg3`, or, for -1, into
 * the first free entry from `9 + n` unless it is loaded already, n being
 * the number of slots counted from D_08A62C7C; func_088DE2D8 does the same
 * from entry `0x16 + n`; func_088DE22C adds the three resources of the
 * 6-byte record `arg1` of the table at 0x09BC8400.
 *
 * Optimized for speed, as unit_088DD8A8.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

struct Entry {
    u16 flags;
    u16 id;
    s32 ptr;
    s32 unk8;
};

struct Table {
    Entry e[43];
};

extern "C" {

extern char *D_08A62C7C;
extern u16 D_09BC8400[];
extern u16 D_09BC8402[];
extern u16 D_09BC8404[];

extern void func_088DDBD8(Table *, s32, u16, s32);
extern s32 func_088DDF94(Table *, u8);

void func_088DE2D8(Table *arg0, u8 arg1);

static inline s32 slot_count(void) {
    char *g = D_08A62C7C;
    s32 n = 0;

    if (*(s8 *)(g + 0x786) > 0) {
        n++;
    }
    if (*(s8 *)(g + 0x7B2) > 0) {
        if (*(s8 *)(g + 0x77C) != *(s8 *)(g + 0x7A8)) {
            n++;
        }
    }
    return n;
}

void func_088DE0B8(Table *arg0, u8 arg1, s32 arg2, s32 arg3) {
    Entry *e;
    s32 k;

    if (arg3 == -1) {
        if (func_088DDF94(arg0, arg1) != 0) {
            return;
        }
        e = &arg0->e[slot_count() + 9];
        for (k = slot_count(); k < 4; k++, e++) {
            if (!(e->flags & 3)) {
                func_088DDBD8(arg0, k + 9, arg1 + 0x17DF, arg2);
                break;
            }
        }
    } else {
        e = &arg0->e[arg3 + 9];
        if ((e->flags & 2) && e->id == (u16) (arg1 + 0x17DF)) {
            return;
        }
        func_088DDBD8(arg0, arg3 + 9, arg1 + 0x17DF, arg2);
    }
}

void func_088DE22C(Table *arg0, u8 arg1, s32 arg2) {
    func_088DE2D8(arg0, arg1);
    func_088DDBD8(arg0, arg2 + 0x1E, D_09BC8400[arg1 * 3], 0);
    func_088DDBD8(arg0, arg2 + 0x22, D_09BC8402[arg1 * 3], 0);
    func_088DDBD8(arg0, arg2 + 0x1A, D_09BC8404[arg1 * 3], 0);
}

void func_088DE2D8(Table *arg0, u8 arg1) {
    Entry *e;
    s32 k;

    if (func_088DDF94(arg0, arg1) != 0) {
        return;
    }
    e = &arg0->e[slot_count() + 0x16];
    for (k = slot_count(); k < 4; k++, e++) {
        if (!(e->flags & 3)) {
            func_088DDBD8(arg0, k + 0x16, arg1 + 0x17DF, 0);
            break;
        }
    }
}

}
