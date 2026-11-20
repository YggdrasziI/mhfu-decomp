/* unit_088DCFCC: 0x088DCFCC-0x088DD264 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DCF70 and unit_088DD264.
 *
 * Initialises an object from the 0x8C-byte record of its index (+0x1E6) in
 * D_089CC438 (+0x30): fixed fields, the six 12-byte items at +0x4E8, three
 * bytes at +0x530, then the values of func_0885187C, func_08851F20 and
 * func_0885CCD0, and the cleared tables at +0x5F7 and +0x6A0.
 *
 * C++, as the units that share its item copy. Optimized for speed
 * (unrolled loops).
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct S3 {
    s16 x;
    s16 y;
    s16 z;
} S3;

typedef struct Item {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    S3 unk6;
} Item;

typedef struct Rec {
    char pad0[0x10];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    char unk15[0x17];
    s32 unk2C;
    Item item[6];
} Rec;

typedef struct Obj {
    char pad0[0x2FF];
    u8 unk2FF[0x20];
    char pad31F[0x1C9];
    Item item[6];
    char pad530[0xC7];
    u8 unk5F7[0x15];
    char pad60C[0x94];
    u16 unk6A0[0x15];
} Obj;

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62C54;

extern s32 func_0885187C(char *, s32, s32);
extern s32 func_08851F20(char *, s32);
extern u8 func_0885CCD0(s32, u16);
extern void func_08864554(char *);
extern void func_088CF210(char *, u8);
extern void func_088D2C14(char *);
extern void func_088D5B54(char *);
extern void func_088DA974(char *, char *, s32);
extern void func_088DAAA0(char *);
extern u8 func_088DAB94(char *, s16);
extern void func_088DAD58(char *, u16);

#define ITEM_COPY(dst, src) \
    (dst)->unk0 = (src)->unk0; \
    (dst)->unk1 = (src)->unk1; \
    (dst)->unk2 = (src)->unk2; \
    (dst)->unk4 = (src)->unk4; \
    x = (src)->unk6.x; \
    y = (src)->unk6.y; \
    z = (src)->unk6.z; \
    (dst)->unk6.x = x; \
    (dst)->unk6.y = y; \
    (dst)->unk6.z = z

void func_088DCFCC(char *arg0) {
    Obj *o = (Obj *) arg0;
    Rec *rec;
    s32 i;
    s32 j;
    s32 k;
    s16 x;
    s16 y;
    s16 z;

    func_08864554(arg0);
    *(u32 *)(arg0 + 0x2AC) = 0x80808080;
    *(u32 *)(arg0 + 0x2B0) = 0x80808080;
    *(u32 *)(arg0 + 0x2B4) = 0x80808080;
    *(s32 *)(arg0 + 0x1C0) = 2;
    *(u8 *)(arg0 + 0x68E) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0;
    *(u8 *)(arg0 + 0x460) = *(u8 *)(arg0 + 0x298);
    *(u8 *)(arg0 + 0x461) = *(u8 *)(arg0 + 0x299);
    *(u8 *)(arg0 + 0x2C8) = 1;
    *(u8 *)(arg0 + 0x3D0) = 0xFF;
    *(s32 *)(arg0 + 0x614) |= 0x400;
    *(s16 *)(arg0 + 0x41E) = 100;
    *(s16 *)(arg0 + 0x2E4) = 100;
    *(s16 *)(arg0 + 0x62E) = 300;
    func_088D2C14(arg0);
    for (i = 0; i < 0x20; i++) {
        o->unk2FF[i] = 0;
    }
    rec = (Rec *)(D_089CC438 + *(u16 *)(arg0 + 0x1E6) * 0x8C + 0x30);
    *(u8 *)(arg0 + 0x4E0) = rec->unk10;
    *(u8 *)(arg0 + 0x4E1) = rec->unk11;
    *(s32 *)(arg0 + 0x4E4) = rec->unk2C;
    ITEM_COPY(&o->item[0], &rec->item[0]);
    for (j = 0; j < 5; j++) {
        ITEM_COPY(&o->item[j + 1], &rec->item[j + 1]);
    }
    *(u8 *)(arg0 + 0x530) = rec->unk12;
    *(u8 *)(arg0 + 0x531) = rec->unk13;
    *(u8 *)(arg0 + 0x532) = rec->unk14;
    func_088DA974(arg0, rec->unk15, 0xFF);
    *(u16 *)(arg0 + 0x53A) = func_0885187C(D_089CC438, *(u16 *)(arg0 + 0x1E6), 2);
    *(u16 *)(arg0 + 0x534) = func_08851F20(D_089CC438, *(u16 *)(arg0 + 0x1E6));
    *(u8 *)(arg0 + 0x1E8) = func_0885CCD0(D_08A62C54, *(u16 *)(arg0 + 0x534));
    func_088DAD58(arg0, *(u16 *)(arg0 + 0x534));
    func_088D5B54(arg0);
    func_088CF210(arg0, *(u8 *)(arg0 + 0x612));
    *(s16 *)(arg0 + 0x610) = 0;
    for (k = 0; k < 0x15; k++) {
        o->unk5F7[k] = 0;
        o->unk6A0[k] = 0;
    }
    *(s32 *)(arg0 + 0x6CC) = 0;
    func_088DAAA0(arg0);
    *(u8 *)(arg0 + 0x5F2) = func_088DAB94(arg0, *(s16 *)(arg0 + 0x60C));
}

}
