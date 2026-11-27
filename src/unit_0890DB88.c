/* unit_0890DB88: 0x0890DB88-0x0890DC24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0890DB88 (ULES01213)
 *
 * Reads a flag byte through arg1->unk4, stores its bit fields in arg0, then
 * decodes two or three values with func_0890C3F4 into arg0 fields (the
 * third only when bit 0x40 is set, otherwise unkB4 is cleared).
 */

typedef int s32;

typedef struct {
    char pad0[0x14];
    s32 unk14;
    s32 unk18;
    char pad1C[0x98 - 0x1C];
    s32 unk98;
    char pad9C[0xA0 - 0x9C];
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
} Obj;

typedef struct {
    s32 unk0;
    signed char *unk4;
} Src;

extern s32 func_0890C3F4(s32, s32 *);

void func_0890DB88(Obj *arg0, Src *arg1) {
    signed char *p;
    s32 f;
    s32 q;

    p = arg1->unk4;
    f = *p & 0x40;
    arg0->unkB0 = *p & 0x20;
    arg0->unkAC = *p & 0x10;
    arg0->unkA8 = *p & 0xF;
    q = func_0890C3F4((s32)(p + 1), &arg0->unkA0);
    q = func_0890C3F4(q, &arg0->unkA4);
    if (arg0->unkB0 != 0) {
        arg0->unk18 = arg0->unk98;
    } else {
        arg0->unk18 = arg0->unk14;
    }
    if (f != 0) {
        q = func_0890C3F4(q, &arg0->unkB4);
    } else {
        arg0->unkB4 = 0;
    }
}
