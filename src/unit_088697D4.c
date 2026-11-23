/* unit_088697D4: 0x088697D4-0x08869880 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088697D4: looks up an entry by id in a per-index table and returns
 * one of its two offsets relocated against a base pointer. */

typedef unsigned short u16;
typedef signed char s8;
typedef int s32;

typedef struct {
    s32 id;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Ent;

extern char *D_089CC438;

s32 func_088697D4(char *arg0, u16 arg1, s32 arg2, s8 arg3) {
    s32 *tbl;
    char *base;
    Ent *e;
    s32 v;

    tbl = *(s32 **)(arg0 + 0x718);
    if (*(u16 *)(D_089CC438 + 0x6AF12) == 0) {
        return 0;
    }
    if (tbl[arg3] == 0) {
        return 0;
    }
    base = *(char **)(arg0 + 0x50);
    e = (Ent *)((char *)tbl[arg3] + (s32)base);
    for (;;) {
        if (e->id == 0) {
            return 0;
        }
        if (e->id == arg1) {
            break;
        }
        e++;
    }
    if (arg2 == 0) {
        v = e->unk8;
    } else if (arg2 == 1) {
        v = e->unkC;
    }
    if ((unsigned int)(v + 1) < 2) {
        return v;
    }
    return v + (s32)base;
}
