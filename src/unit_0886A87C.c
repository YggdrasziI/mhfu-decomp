/* unit_0886A87C: 0x0886A87C-0x0886A8AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A87C: returns val[idx] of entry n (0x2C-byte entries at 0x768). */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    /* 0x00 */ s32 val[7];
    /* 0x1C */ u8 pad1C[3];
    /* 0x1F */ s8 idx;
    /* 0x20 */ u8 pad20[0xC];
} Entry; /* size 0x2C */

typedef struct {
    /* 0x000 */ u8 pad0[0x768];
    /* 0x768 */ Entry ent[1];
} Obj;

s32 func_0886A87C(Obj *p, u8 n) {
    return p->ent[n].val[p->ent[n].idx];
}
