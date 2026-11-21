/* unit_088D66F4: 0x088D66F4-0x088D6924 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D64E0 and unit_088D6924.
 *
 * Copies bytes of the record at +0x4A0 of the global object and its six
 * 12-byte items to the object (+0x4E0, +0x4E8), and looks up the kind
 * (+0x1E8) of the first item. The item copies are C++ structure
 * assignments: the nested `S3` member loads x, y, z into descending
 * registers before its three stores.
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

void func_088D66F4(char *arg0) {
    Rec *rec = (Rec *)(D_089CC438 + 0x4A0);

    *(u8 *)(arg0 + 0x4E0) = rec->unk13;
    *(u8 *)(arg0 + 0x530) = rec->unk15;
    *(u8 *)(arg0 + 0x531) = rec->unk16;
    *(u8 *)(arg0 + 0x532) = rec->unk17;
    *(s32 *)(arg0 + 0x4E4) = rec->unk1C;
    *(u8 *)(arg0 + 0x4E1) = rec->unk14;
    func_088DA974(arg0, (char *) rec + 0x6A79E, 0xFF);
    *(u16 *)(arg0 + 0x534) = func_0885DF38(D_08A62C54, &rec->unk20[0]);
    *(Item *)(arg0 + 0x4E8) = rec->unk20[0];
    *(u8 *)(arg0 + 0x1E8) = D_08978488[*(u16 *)(arg0 + 0x534)];
    *(u8 *)(arg0 + 0x5F3) = func_0885CE00(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    *(u8 *)(arg0 + 0x5F4) = func_0885CE1C(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    *(u8 *)(arg0 + 0x5F5) = func_0885CDB8(D_08A62C54, (Item *)(arg0 + 0x4E8));
    *(Item *)(arg0 + 0x4F4) = rec->unk20[1];
    *(Item *)(arg0 + 0x500) = rec->unk20[2];
    *(Item *)(arg0 + 0x50C) = rec->unk20[3];
    *(Item *)(arg0 + 0x518) = rec->unk20[4];
    *(Item *)(arg0 + 0x524) = rec->unk20[5];
}

}
