/* unit_088D897C: 0x088D897C-0x088D8DA4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D8900 and unit_088D8DA4.
 *
 * Rebuilds the six entries at +0x676 (id), +0x634 and +0x63A (level): the
 * 7-byte records of D_089B7B60 (ended by 0xFF) give an id for the range the
 * total of func_088D8DF4 falls in, func_088D8DA4 appends it; the entries
 * are then ranked (positive levels first, then negative ones) and sorted.
 *
 * Optimized for speed (loops of six unrolled).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef struct Rec {
    u8 key;
    u8 id[6];
} Rec;

extern Rec D_089B7B60[];

struct Obj;
s32 func_088D8DF4(struct Obj *, s32);
void func_088D8DA4(struct Obj *, u8, u8 *, s32, s8);

typedef struct Obj {
    char pad0[0x634];
    u8 val[6];
    s8 level[6];
    char pad640[0x36];
    u8 id[6];
} Obj;

void func_088D897C(Obj *arg0) {
    s16 rank[6];
    u8 val[6];
    u8 id[6];
    u8 count;
    Rec *rec;
    s32 i;
    s32 a;
    s32 b;
    s8 total;
    s16 t;
    u8 tv;
    u8 ti;

    rec = D_089B7B60;
    count = 0;
    for (i = 0; i < 6; i++) {
        arg0->id[i] = 0;
        arg0->val[i] = 0;
        arg0->level[i] = 0;
    }
    for (; rec->key != 0xFF; rec++) {
        total = func_088D8DF4(arg0, rec->key);
        if (total < -0x13) {
            func_088D8DA4(arg0, rec->id[0], &count, rec->key, total);
        } else if (total < -0xE) {
            func_088D8DA4(arg0, rec->id[1], &count, rec->key, total);
        } else if (total < -9) {
            func_088D8DA4(arg0, rec->id[2], &count, rec->key, total);
        } else if (total >= 0x14) {
            func_088D8DA4(arg0, rec->id[5], &count, rec->key, total);
        } else if (total >= 0xF) {
            func_088D8DA4(arg0, rec->id[4], &count, rec->key, total);
        } else if (total >= 0xA) {
            func_088D8DA4(arg0, rec->id[3], &count, rec->key, total);
        }
    }
    for (i = 0; i < 6; i++) {
        if (arg0->id[i] != 0 && arg0->level[i] != 0) {
            if (arg0->level[i] > 0) {
                rank[i] = arg0->level[i] + 0xC8;
            } else {
                rank[i] = (s16) -arg0->level[i] + 0x64;
            }
            val[i] = arg0->val[i];
            id[i] = arg0->id[i];
        } else {
            rank[i] = 0;
            val[i] = 0;
            id[i] = 0;
        }
    }
    for (a = 0; a < 5; a++) {
        for (b = a + 1; b < 6; b++) {
            if (rank[a] < rank[b] || (rank[a] == rank[b] && val[a] < val[b])) {
                t = rank[a];
                rank[a] = rank[b];
                rank[b] = t;
                tv = val[a];
                val[a] = val[b];
                val[b] = tv;
                ti = id[a];
                id[a] = id[b];
                id[b] = ti;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        arg0->level[i] = rank[i];
        arg0->val[i] = val[i];
        arg0->id[i] = id[i];
    }
}
