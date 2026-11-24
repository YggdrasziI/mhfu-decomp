/* unit_088585E8: 0x088585E8-0x08858840 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088585E8: keeps three (u8 kind, word, word) slots at 0x8/0xC/0x18,
 * replaces the lowest-ranked one if the new entry ranks at least as high,
 * then sorts the slots by rank (highest first).
 *
 * Needs the speed setting (loops rotated). The sort uses its own two
 * counters (one counter per loop) and its inner loop has an explicit guard
 * repeating the loop test (the original tests j < 3 twice). */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;

typedef struct {
    char unk0[8];
    u8 unk8[3];
    char pad;
    s32 unkC[3];
    s32 unk18[3];
} Slots;

static inline u8 rank(s32 x) {
    if (x < 3) return 0;
    if (x < 17) return 1;
    if (x < 19) return 2;
    return 3;
}

void func_088585E8(s32 arg0, Slots *p, s32 arg2, s32 arg3, s32 arg4) {
    u8 newRank;
    u8 slot;
    u8 minRank;
    u8 i;
    u8 a;
    u8 b;

    newRank = rank(arg2);
    slot = 0;
    minRank = 30;

    for (i = 0; i < 3; i++) {
        u8 v = p->unk8[i];
        if (v == 0) {
            slot = i;
            minRank = 0;
            break;
        }
        if (!(minRank < rank(v))) {
            minRank = rank(v);
            slot = i;
        }
    }
    if (minRank > newRank) return;

    p->unk8[slot] = arg2;
    p->unkC[slot] = arg3;
    p->unk18[slot] = arg4;
    for (a = 0; a < 2; a++) {
        b = a + 1;
        if (b < 3) {
            for (; b < 3; b++) {
                if (rank(p->unk8[a]) < rank(p->unk8[b])) {
                    u8 t8 = p->unk8[a];
                    s32 tc = p->unkC[a];
                    s32 t18 = p->unk18[a];
                    p->unk8[a] = p->unk8[b];
                    p->unkC[a] = p->unkC[b];
                    p->unk18[a] = p->unk18[b];
                    p->unk8[b] = t8;
                    p->unkC[b] = tc;
                    p->unk18[b] = t18;
                }
            }
        }
    }
}
