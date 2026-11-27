/* unit_0886BEA4: 0x0886BEA4-0x0886BF28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886BEA4: returns an entry of an offset table relative to a base
 * pointer, or the result of func_09A8A4B0 when a global flag bit is set.
 * Needs #pragma opt_propagation off (keeps the 0x50 load at its use). */
#pragma opt_propagation off

typedef int s32;

extern "C" {
extern char *D_089CC438;
extern char *D_08A631A0;
extern void *D_09B23820;
s32 func_09A8A4B0(void *);
}

typedef struct {
    char pad[0x50];
    char *base; /* 0x50 */
    char pad2[4];
    s32 *tbl;   /* 0x58 */
} T;

extern "C" s32 func_0886BEA4(T *p, s32 idx)
{
    if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) != false) {
        return func_09A8A4B0(D_09B23820);
    }
    s32 *t = p->tbl;
    s32 o = t[*(s32 *)(D_08A631A0 + 0xF7A574)];
    char *b = p->base;
    s32 r = *(s32 *)(o + (s32)b + idx * 4);
    return r + (s32)b;
}
