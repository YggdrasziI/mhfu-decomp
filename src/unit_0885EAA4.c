/* unit_0885EAA4: 0x0885EAA4-0x0885EB34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0885EAA4: for an item (kind unk1, index unk2), returns the byte at
 * +0xC of the 40-byte record D_08978474[kind][index] plus twice
 * min(unk4, (u8)func_0885EF20(arg0, arg1)), as a u16; 0 when the index is 0.
 * The record pointer is taken in two steps (row, then `rec += index`); a
 * single `&tbl[kind][index]` swaps the address registers.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u8 unk4;
} Item;

typedef struct {
    char pad0[0xC];
    u8 unkC;
    char pad[0x28 - 0xD];
} UnkRec40;

extern UnkRec40 *D_08978474[];

extern s32 func_0885EF20(s32 arg0, Item *arg1);

s32 func_0885EAA4(s32 arg0, Item *arg1) {
    UnkRec40 *rec;
    u8 n;
    u8 r;

    if (arg1->unk2 == 0) {
        return 0;
    }
    rec = D_08978474[arg1->unk1];
    rec += arg1->unk2;
    n = arg1->unk4;
    r = func_0885EF20(arg0, arg1);
    if (r < n) {
        n = r;
    }
    return (u16)(rec->unkC + n * 2);
}
