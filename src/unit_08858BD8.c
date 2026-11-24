/* unit_08858BD8: 0x08858BD8-0x08858E48 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
/* func_08858BD8: 0x08858BD8-0x08858E48 (ULES01213)
 *
 * Needs the speed setting (pragma above). The word at +0 of an entry is
 * compared as an integer but copied as a float (lwc1/swc1): a union, copied
 * as a whole. The 54- and 43-byte blocks are copied by struct assignment
 * (byte-wise count-down loops).
 */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

typedef struct { u8 v[3]; } Blk3;
typedef struct { f32 x, y, z; } Vec3;
typedef struct { s8 v[54]; } Blk54;
typedef struct { s8 v[43]; } Blk43;

typedef struct {
    union { s32 i; f32 f; } unk0;
    s16 unk4;
    u16 unk6;
    Blk3 unk8;
    Vec3 unkC;
    Vec3 unk18;
    Blk54 unk24;
    Blk43 unk5A;
    char pad[0x88 - 0x85];
} Entry;

typedef struct {
    char pad[0x67D98];
    Entry ent[10];
} Owner;

typedef struct {
    s32 unk0;
    s16 unk4;
    u16 unk6;
} Key;

s32 func_08858BD8(Owner *arg0, Key *arg1) {
    u32 i;

    if (arg1->unk4 > 4) {
        return 1;
    }
    for (i = 0; i < 10; i++) {
        if (arg0->ent[i].unk0.i != arg1->unk0) {
            return 1;
        }
        if (arg0->ent[i].unk4 < 5 && arg0->ent[i].unk4 != 3 &&
            arg0->ent[i].unk6 == arg1->unk6) {
            if (arg1->unk4 < arg0->ent[i].unk4) {
                return 0;
            }
            break;
        }
    }
    if (i >= 10) {
        return 1;
    }
    if (arg0->ent[i].unk4 == 4) {
        return 1;
    }
    for (; i < 9; i++) {
        arg0->ent[i].unk0 = arg0->ent[i + 1].unk0;
        arg0->ent[i].unk4 = arg0->ent[i + 1].unk4;
        arg0->ent[i].unk6 = arg0->ent[i + 1].unk6;
        arg0->ent[i].unk8 = arg0->ent[i + 1].unk8;
        arg0->ent[i].unkC = arg0->ent[i + 1].unkC;
        arg0->ent[i].unk18 = arg0->ent[i + 1].unk18;
        arg0->ent[i].unk24 = arg0->ent[i + 1].unk24;
        arg0->ent[i].unk5A = arg0->ent[i + 1].unk5A;
    }
    return 1;
}
