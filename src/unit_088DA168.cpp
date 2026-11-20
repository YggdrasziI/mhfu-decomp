/* unit_088DA168: 0x088DA168-0x088DA2C4 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088DA150 and unit_088DA2C4.
 *
 * func_088DA168 tells whether the object whose id is the global one holds
 * pair 0x2B. func_088DA1B0 rebuilds the entries (func_088D897C) and tells
 * whether none of the 24 pairs of the global record holds an id of kind 2
 * whose bit is in the mask of func_088D7D6C; 0 when the first item is not
 * of type 6 or its kind is 0xA.
 *
 * C++: an inline test of the object id against the global one. Optimized
 * for speed (loop over the pairs through a stepped pointer).
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

typedef struct Pair {
    u16 unk0;
    s16 unk2;
} Pair;

typedef struct Rec {
    char pad0[0x20];
    Item unk20[6];
    char pad68[0x3EC0];
    Pair unk3F28[0x18];
} Rec;

typedef struct Info {
    u8 unk0;
    u8 unk1;
    char pad2[6];
    s16 unk8;
    char padA[0xE];
} Info;

typedef struct Kind {
    u16 unk0;
    char pad2[0x1A];
} Kind;

extern "C" {

extern char *D_089CC438;
extern Info D_0899D198[];
extern Kind D_08960B9C[];
extern u8 D_08978488[];

extern s32 func_088568AC(char *, s32);
extern void func_088D897C(char *);
extern s32 func_088D7D6C(char *);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

s32 func_088DA168(char *arg0) {
    if (is_own(arg0) == 0) {
        return 0;
    }
    return func_088568AC(D_089CC438, 0x2B) != 0;
}

s32 func_088DA1B0(char *arg0) {
    Rec *rec = (Rec *)(D_089CC438 + 0x4A0);
    s32 mask;
    s32 i;
    s32 id;
    Info *info;

    if (rec->unk20[0].unk1 != 6) {
        return 0;
    }
    if (D_08978488[D_08960B9C[rec->unk20[0].unk2].unk0] == 0xA) {
        return 0;
    }
    func_088D897C(arg0);
    mask = func_088D7D6C(arg0);
    for (i = 0; i < 0x18; i++) {
        id = rec->unk3F28[i].unk0;
        if (id != 0 && rec->unk3F28[i].unk2 > 0) {
            info = &D_0899D198[id];
            if (info->unk1 == 2 && (mask & (1 << info->unk8))) {
                return 0;
            }
        }
    }
    return 1;
}

}
