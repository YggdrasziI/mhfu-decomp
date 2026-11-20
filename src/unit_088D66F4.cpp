/* unit_088D66F4: 0x088D66F4-0x088D6924 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D64E0 and unit_088D6924.
 *
 * NonMatching, 99.7 %. Copies bytes of the record at +0x4A0 of the global
 * object and its six 12-byte items to the object (+0x4E0, +0x4E8), and looks
 * up the kind (+0x1E8) of the first item. One gap: in the last two item
 * copies the three `s16` are loaded y, z, x (x in the register of the
 * previous temporary) where the original loads x, y, z into descending
 * registers. Tried: the copy as an inline function (locals, `s32` locals,
 * reversed declarations, arguments in both orders, by value, by reference,
 * a member function, array form): all six copies have the gap; function
 * locals shared by a macro (this version): the first four match; other
 * declaration orders, separate locals per copy or per group, the five last
 * copies as a loop: worse.
 */

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

typedef struct Pair {
    u16 unk0;
    s16 unk2;
} Pair;

typedef struct Rec {
    char pad0[0x13];
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    char pad18[4];
    s32 unk1C;
    Item unk20[6];
    char pad68[0x3EC0];
    Pair unk3F28[0x18];
} Rec;

extern "C" {

extern char *D_089CC438;
extern char *D_08A62C54;
extern u8 D_08978488[];

extern s32 func_0885CDB8(char *, Item *);
extern s32 func_0885CE00(char *, u8);
extern s32 func_0885CE1C(char *, u8);
extern s32 func_0885DF38(char *, Item *);
extern void func_088DA974(char *, char *, s32);

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

void func_088D66F4(char *arg0) {
    Rec *rec = (Rec *)(D_089CC438 + 0x4A0);
    s16 x;
    s16 y;
    s16 z;

    *(u8 *)(arg0 + 0x4E0) = rec->unk13;
    *(u8 *)(arg0 + 0x530) = rec->unk15;
    *(u8 *)(arg0 + 0x531) = rec->unk16;
    *(u8 *)(arg0 + 0x532) = rec->unk17;
    *(s32 *)(arg0 + 0x4E4) = rec->unk1C;
    *(u8 *)(arg0 + 0x4E1) = rec->unk14;
    func_088DA974(arg0, (char *) rec + 0x6A79E, 0xFF);
    *(u16 *)(arg0 + 0x534) = func_0885DF38(D_08A62C54, &rec->unk20[0]);
    ITEM_COPY((Item *)(arg0 + 0x4E8), &rec->unk20[0]);
    *(u8 *)(arg0 + 0x1E8) = D_08978488[*(u16 *)(arg0 + 0x534)];
    *(u8 *)(arg0 + 0x5F3) = func_0885CE00(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    *(u8 *)(arg0 + 0x5F4) = func_0885CE1C(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    *(u8 *)(arg0 + 0x5F5) = func_0885CDB8(D_08A62C54, (Item *)(arg0 + 0x4E8));
    ITEM_COPY((Item *)(arg0 + 0x4F4), &rec->unk20[1]);
    ITEM_COPY((Item *)(arg0 + 0x500), &rec->unk20[2]);
    ITEM_COPY((Item *)(arg0 + 0x50C), &rec->unk20[3]);
    ITEM_COPY((Item *)(arg0 + 0x518), &rec->unk20[4]);
    ITEM_COPY((Item *)(arg0 + 0x524), &rec->unk20[5]);
}

}
