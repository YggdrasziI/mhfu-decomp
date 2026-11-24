/* unit_08852A60: 0x08852A60-0x08852C20 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Speed setting (`#pragma optimize_for_size off`): needed to match.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    Vec3s unk6;
} Elem;

typedef struct {
    u8 pad0[0x13];
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 pad18[4];
    s32 unk1C;
    u8 unk20;
    u8 unk21;
    u16 unk22;
    u16 unk24;
    Vec3s unk26;
    Elem unk2C[5];
} Src;

typedef struct {
    u8 unk0;
    u8 pad1[0xF];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15[5][4];
    u8 pad29[3];
    s32 unk2C;
    u8 unk30;
    u8 unk31;
    u16 unk32;
    u16 unk34;
    Vec3s unk36;
    Elem unk3C[5];
    u8 unk78;
    u8 unk79[5];
    u8 unk7E;
    u8 unk7F;
    u8 unk80;
    u8 unk81[8];
} Dst;

extern void memcpy(void *, void *, s32);

void func_08852A60(u8 *arg0) {
    Dst *dst = (Dst *)(arg0 + 0x30);
    Src *src = (Src *)(arg0 + 0x4A0);
    s32 i;

    dst->unk0 = 1;
    dst->unk10 = src->unk13;
    dst->unk11 = src->unk14;
    dst->unk12 = src->unk15;
    dst->unk13 = src->unk16;
    dst->unk14 = src->unk17;
    dst->unk2C = src->unk1C;
    dst->unk30 = src->unk20;
    dst->unk31 = src->unk21;
    dst->unk32 = src->unk22;
    dst->unk34 = src->unk24;
    dst->unk36 = src->unk26;
    for (i = 0; i < 5; i++) {
        dst->unk3C[i].unk0 = src->unk2C[i].unk0;
        dst->unk3C[i].unk1 = src->unk2C[i].unk1;
        dst->unk3C[i].unk2 = src->unk2C[i].unk2;
        dst->unk3C[i].unk4 = src->unk2C[i].unk4;
        dst->unk3C[i].unk6 = src->unk2C[i].unk6;
        dst->unk15[i][0] = ((u8 *)src + 0x6A79E)[i * 4 + 0];
        dst->unk15[i][1] = ((u8 *)src + 0x6A79E)[i * 4 + 1];
        dst->unk15[i][2] = ((u8 *)src + 0x6A79E)[i * 4 + 2];
        dst->unk15[i][3] = ((u8 *)src + 0x6A79E)[i * 4 + 3];
    }
    dst->unk78 = *((u8 *)src + 0x401C);
    dst->unk7E = *(u16 *)((u8 *)src + 0x67352);
    dst->unk7F = *(u16 *)((u8 *)src + 0x67354);
    dst->unk80 = *(u16 *)((u8 *)src + 0x67356);
    dst->unk79[0] = arg0[0x69942];
    dst->unk79[1] = arg0[0x69943];
    dst->unk79[2] = arg0[0x69944];
    dst->unk79[3] = arg0[0x69945];
    dst->unk79[4] = arg0[0x69946];
    memcpy(dst->unk81, (u8 *)src + 0x67500, 8);
}
