/* unit_0890DA8C: 0x0890DA8C-0x0890DB28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890DA8C: derived from the assembly only.
 * Walks 16 two-word entries of D_09A5F120; when arg1 lies in
 * [first->unk0, second->unk0 + (second->unk4 & ~1)), copies the entry's
 * two words to arg0->unkC / arg0->unk10 and returns 1; else returns 0.
 */

typedef int s32;
typedef unsigned int u32;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} Range;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    Range *unkC;
    Range *unk10;
} Info;

typedef struct {
    Range *unk0;
    Range *unk4;
} Pair;

extern Pair D_09A5F120[];
extern Pair D_09A5F124[];

s32 func_0890DA8C(Info *arg0, u32 arg1) {
    s32 i;
    Pair *e;

    i = 0;
    e = D_09A5F120;
    do {
        if (e->unk0 != 0) {
            if (e->unk0->unk0 <= arg1 &&
                arg1 < e->unk4->unk0 + (e->unk4->unk4 & ~1)) {
                arg0->unkC = D_09A5F120[i].unk0;
                arg0->unk10 = D_09A5F124[i].unk0;
                return 1;
            }
        }
        i++;
        e++;
    } while (i < 16);
    return 0;
}
