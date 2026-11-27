/* unit_0886AA28: 0x0886AA28-0x0886AB7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * NonMatching: compiled for the report only, the code stays in assembly.
 */

/* func_0886AA28 (NonMatching, 99.12 %): only the flag register differs
 * (original $t0, ours $t3; the loop invariants shift by one register).
 * Same id helpers as unit_08813594 / unit_088CC828, with the D_09CE5008
 * test against a flag read from D_09CE4808. C++.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;

#pragma opt_rebuildconditionals off

extern "C" {
extern char *D_09A4F060;
extern char *D_08A631A0;
extern u16 D_09CE4808[];
extern u16 D_09CE5008[];
extern u16 D_09CE5220[];
extern u16 func_088900C4(char *, s32);
}

typedef struct Ent { u16 id; u16 n; s32 off; } Ent;
typedef struct Pt { s32 a; f32 x; f32 y; f32 z; } Pt;

static inline s32 cur_flag(void) {
    if (D_09CE4808[*(s32 *)(D_09A4F060 + 0x284)] == 0xFFFF) {
        return 0;
    }
    return 1;
}

static inline u16 map_id(u16 id) {
    s32 v;

    if (id == 0xFFFF) {
        return id;
    }
    v = D_09CE5220[id];
    return (v != 0xFFFF) ? v : id;
}

static inline u16 base_id(u16 id) {
    s32 f = cur_flag();
    if (f == D_09CE5008[id]) {
        return id;
    }
    return map_id(id);
}

static inline u16 conv_id(u16 id) {
    if (id == 0xFFFF) {
        return id;
    }
    return base_id(id);
}

extern "C" s32 func_0886AA28(char *arg0, char *arg1) {
    s32 base = *(s32 *)(arg0 + 0x50);
    Ent *e = (Ent *)(*(char **)(*(char **)(arg0 + 0x4C) + 0x20) + base);
    Pt *p;

    while (1) {
        if (e->id == 0xFFFF) {
            return 0;
        }
        if (*(u16 *)(arg1 + 0x29A) == conv_id(e->id)) {
            break;
        }
        e++;
    }
    p = (Pt *)(e->off + base);
    p += (u16)func_088900C4(D_08A631A0, 0) % e->n;
    *(s32 *)(arg1 + 0x1F4) = p->a;
    *(f32 *)(arg1 + 0x200) = p->x;
    *(f32 *)(arg1 + 0x204) = p->y;
    *(f32 *)(arg1 + 0x208) = p->z;
    return 1;
}
