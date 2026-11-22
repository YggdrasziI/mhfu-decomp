/* unit_0889BCB4: 0x0889BCB4-0x0889BE7C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

/* func_0889BCB4: copies a 0x70-byte record member by member and returns
 * the destination. Member types follow the loads of the original. */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[18];
} B18;

typedef struct {
    s8 b[16];
} B16;

typedef struct {
    u8 b[3];
} U3;

typedef struct {
    s16 a;
    s16 b;
} S2;

typedef struct {
    float a;
    float b;
} F2;

typedef struct {
    s8 unk0;
    u8 unk1;
    s8 unk2;
    s8 unk3;
    s16 unk4;
    s8 unk6;
    U3 unk7;
    U3 unkA;
    s8 unkD;
    s8 unkE;
    u8 unkF;
    u16 unk10;
    S2 unk12;
    u8 unk16;
    float unk18;
    float unk1C;
    u16 unk20;
    u16 unk22;
    u8 unk24;
    u8 unk25;
    u16 unk26;
    u8 unk28;
    s8 unk29;
    s16 unk2A;
    u8 unk2C;
    s32 unk30;
    F2 unk34;
    F2 unk3C;
    U3 unk44;
    U3 unk47;
    u8 unk4A;
    u8 unk4B;
    u8 unk4C;
    u8 unk4D;
    B18 unk4E;
    B16 unk60;
} Rec;

Rec *func_0889BCB4(Rec *d, Rec *s) {
    d->unk0 = s->unk0;
    d->unk1 = s->unk1;
    d->unk2 = s->unk2;
    d->unk3 = s->unk3;
    d->unk4 = s->unk4;
    d->unk6 = s->unk6;
    d->unk7 = s->unk7;
    d->unkA = s->unkA;
    d->unkD = s->unkD;
    d->unkE = s->unkE;
    d->unkF = s->unkF;
    d->unk10 = s->unk10;
    d->unk12 = s->unk12;
    d->unk16 = s->unk16;
    d->unk18 = s->unk18;
    d->unk1C = s->unk1C;
    d->unk20 = s->unk20;
    d->unk22 = s->unk22;
    d->unk24 = s->unk24;
    d->unk25 = s->unk25;
    d->unk26 = s->unk26;
    d->unk28 = s->unk28;
    d->unk29 = s->unk29;
    d->unk2A = s->unk2A;
    d->unk2C = s->unk2C;
    d->unk30 = s->unk30;
    d->unk34 = s->unk34;
    d->unk3C = s->unk3C;
    d->unk44 = s->unk44;
    d->unk47 = s->unk47;
    d->unk4A = s->unk4A;
    d->unk4B = s->unk4B;
    d->unk4C = s->unk4C;
    d->unk4D = s->unk4D;
    d->unk4E = s->unk4E;
    d->unk60 = s->unk60;
    return d;
}
