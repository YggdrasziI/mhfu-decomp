/* unit_08868CE8: 0x08868CE8-0x08868E54 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08868CE8: fills a parameter block (hypothesis: on-screen keyboard,
 * from the neighbouring code). */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    void *unk1C;
    void *unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
} Sub;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 pad1C[5];
    s32 unk30;
    Sub *unk34;
    s32 pad38[2];
    Sub sub;
    u8 pad74;
    u8 unk75;
    u8 unk76;
    u8 unk77;
} Params;

extern void memset(void *, s32, s32);
extern char D_08931628[];

void func_08868CE8(Params *p, u8 mode, void *a2, void *a3, s32 a4, s32 a5, s32 a6) {
    Sub *s;

    memset(p, 0, 0x40);
    p->unk0 = 0x40;
    p->unk4 = p->unk75;
    p->unk8 = p->unk76;
    p->unkC = 0x2A;
    p->unk10 = 0x2C;
    p->unk14 = 0x2B;
    p->unk18 = 0x29;
    p->unk30 = 1;
    s = &p->sub;
    p->unk34 = s;
    s->unk0 = 1;
    s->unk4 = 0;
    s->unk8 = p->unk77;
    s->unkC = 0;
    s->unk14 = a6;
    s->unk18 = 1;
    if (a2 == 0) {
        s->unk1C = D_08931628;
    } else {
        s->unk1C = a2;
    }
    if (a3 == 0) {
        s->unk20 = D_08931628;
    } else {
        s->unk20 = a3;
    }
    s->unk24 = a5;
    s->unk28 = a4;
    s->unk2C = 0;
    s->unk30 = 0;
    switch (mode) {
    case 1:
        s->unk10 = 0xDF00;
        break;
    case 2:
        s->unk10 = 0xF;
        break;
    case 3:
        s->unk10 = 0x101;
        break;
    case 4:
        s->unk10 = 1;
        break;
    default:
        s->unk10 = 0;
        break;
    }
}
