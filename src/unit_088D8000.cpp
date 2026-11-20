/* unit_088D8000: 0x088D8000-0x088D81E4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088D7D6C and unit_088D81E4.
 *
 * For the object whose id is the global one, in state 6 (+0x4E9) with a
 * selected pair (+0x686): refreshes the level (+0x55C), the count (+0x646)
 * and the capacity (+0x67D) from the tables, clears +0x67C and, for kind
 * 10 (+0x1E8), picks the level through func_088D81E4 / func_088D81F0.
 *
 * C++: bool conversion, an inline test of the object id against the global
 * one.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct Pair {
    u16 unk0;
    s16 unk2;
} Pair;

typedef struct Info {
    s16 unk0;
    char pad2[0x16];
} Info;

typedef struct Rec {
    u8 unk0;
    char pad1[0x1B];
} Rec;

extern "C" {

extern char *D_089CC438;
extern char *D_08A62C50;
extern Rec D_08960BAC[];
extern u8 D_089786F8[][0x20];
extern Info D_0899D1A0[];

extern Pair *func_08856884(char *, s32);
extern char *func_0885C580(char *, u16);
extern u8 func_088D6A1C(char *, s32);
extern void func_088D81E4(char *);
extern void func_088D81F0(char *);

static inline bool is_own(char *obj) {
    return *(u16 *)(obj + 0x1E6) == *(u8 *)(D_089CC438 + 0x28);
}

void func_088D8000(char *arg0) {
    u16 id;

    if (is_own(arg0) == 0) {
        return;
    }
    if (*(u8 *)(arg0 + 0x4E9) != 6) {
        return;
    }
    if (*(u16 *)(arg0 + 0x686) == 0xFF) {
        return;
    }
    *(u8 *)(arg0 + 0x55C) = *(s16 *)(func_0885C580(D_08A62C50, *(u16 *)(arg0 + 0x686)) + 8);
    if (*(u8 *)(func_0885C580(D_08A62C50, *(u16 *)(arg0 + 0x686)) + 3) == 0xFF) {
        *(s16 *)(arg0 + 0x646) = 0xFF;
    } else {
        *(s16 *)(arg0 + 0x646) = func_08856884(D_089CC438, *(u16 *)(arg0 + 0x686))->unk2;
    }
    *(u8 *)(arg0 + 0x67D) = D_089786F8[D_08960BAC[*(u16 *)(arg0 + 0x4EA)].unk0][*(u8 *)(arg0 + 0x55C)];
    if (func_088D6A1C(arg0, 0xAA) == 1) {
        *(u8 *)(arg0 + 0x67D) += 1;
    }
    *(u8 *)(arg0 + 0x67C) = 0;
    if (*(u8 *)(arg0 + 0x1E8) == 0xA) {
        if (func_088D6A1C(arg0, 0xD9) == 1) {
            id = ((Pair *)(D_089CC438 + 0x6AEA6))[*(u16 *)(arg0 + 0x686)].unk0;
            if (id == 0x80 || id == 0) {
                func_088D81F0(arg0);
            } else {
                func_088D81E4(arg0);
                *(u8 *)(arg0 + 0x55C) = D_0899D1A0[((Pair *)(D_089CC438 + 0x6AEA6))[*(u8 *)(arg0 + 0x5F6)].unk0].unk0;
            }
        } else {
            func_088D81F0(arg0);
        }
    }
}

}
