/* unit_08818264: 0x08818264-0x088188A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08818264 (ULES01213)
 *
 * C++: the flag test keeps its `sltu` (bool). The 0x28-byte box is copied
 * field by field from D_0893B040..D_0893B066 (one extern per field, as splat
 * names them). The page index is kept twice: an `s32` masked as
 * `(n & 0xFF)` for the text pointer and a `u8` copy for the test and the
 * switch (a `(u8)n` at both uses is merged into one register).
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u16 unk0;
    u16 unk2;
    u16 w;
    u16 unk6;
    u8 col;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u16 x;
    u16 y;
    u16 h;
    u16 unk12;
    s32 text;
    s32 unk18;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u16 unk24;
    u16 unk26;
} Box;

extern "C" {

extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C7C;
extern u16 D_089AC7C4;
extern u16 D_089AC7C6;
extern u16 D_089AC7C8;
extern char D_089AC7CC[];
extern u16 D_089ACC04[];
extern u16 D_089ACC44[];
extern char D_0893854C;
extern char D_08938478;
extern Box D_0893B040;
extern u16 D_0893B042;
extern u16 D_0893B044;
extern u16 D_0893B046;
extern u8 D_0893B048;
extern u8 D_0893B049;
extern u8 D_0893B04A;
extern u8 D_0893B04B;
extern u16 D_0893B04C;
extern u16 D_0893B04E;
extern u16 D_0893B050;
extern u16 D_0893B052;
extern s32 D_0893B054;
extern s32 D_0893B058;
extern u16 D_0893B05C;
extern u16 D_0893B05E;
extern u16 D_0893B060;
extern u16 D_0893B062;
extern u16 D_0893B064;
extern u16 D_0893B066;

extern char *func_0885151C(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern char *func_0886BEA4(char *, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_08849D7C(char *);
extern char *func_088298E4(char *);
extern void func_0881A8E0(char *, s16, s16, s32);
extern void func_0881A8F8(char *, s16, s16, u8);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_08890DFC(char *, s16, s16);
extern void func_0881A9D8(char *, s8);

void func_08818264(char *arg0) {
    char text[0x40];
    Box box;
    s32 n;
    u8 m;
    s16 x;

    func_0880E8F0(text, &D_0893854C, func_0885151C(D_089CC438, D_089AC7C4));
    if (!(*(s32 *)(arg0 + 0x528) & 0x40)) {
        func_0882F580(arg0, &D_0893B040, text, -1, 0xFF, 0);
        func_088915B0(D_08A631A8, 0xFC, 0x86, 0, &D_08938478, func_0885151C(D_089CC438, D_089AC7C6));
        return;
    }
    box.unk0 = D_0893B040.unk0;
    box.unk2 = D_0893B042;
    box.w = D_0893B044;
    box.unk6 = D_0893B046;
    box.col = D_0893B048;
    box.unk9 = D_0893B049;
    box.unkA = D_0893B04A;
    box.unkB = D_0893B04B;
    box.x = D_0893B04C;
    box.y = D_0893B04E;
    box.h = D_0893B050;
    box.unk12 = D_0893B052;
    box.text = D_0893B054;
    box.unk18 = D_0893B058;
    box.unk1C = D_0893B05C;
    box.unk1E = D_0893B05E;
    box.unk20 = D_0893B060;
    box.unk22 = D_0893B062;
    box.unk24 = D_0893B064;
    box.unk26 = D_0893B066;
    n = *(u8 *)(arg0 + 0x57F);
    if ((bool)(*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 1) {
        n = (u8)(n + 1);
    }
    m = (u8)n;
    if (m == 0) {
        func_0880E8F0(text, &D_0893854C, func_0885151C(D_089CC438, D_089AC7C8));
    }
    box.text = (s32)(D_089AC7CC + (n & 0xFF) * 26);
    func_0882F580(arg0, &box, text, -1, 0xFF, 0);
    func_0882FB38(arg0, &box, *(u8 *)(arg0 + 0x57F), *(u8 *)(arg0 + 0x581), 0, 0);
    func_088915B0(D_08A631A8, (s16)box.x, box.y + box.h - 2, 0, &D_08938478, func_0886BEA4(D_08A62C7C, 0));
    func_0882D6F0(arg0, box.x, box.y + box.h * 2 - 3, box.w - 0x18, 1, 0x80, 0x80, 0x80);
    switch (m) {
    case 0:
        func_08849D7C(arg0);
        break;
    case 1:
        x = box.x + box.col * 5;
        func_0881A8E0(arg0, x, box.y + box.h * 2, *(s32 *)(func_088298E4(arg0) + 8));
        func_0881A8E0(arg0, x, box.y + box.h * 3, *(s32 *)(func_088298E4(arg0) + 4));
        func_0881A8F8(arg0, x, box.y + box.h * 4, 1);
        func_08891474(D_08A631A8, x, box.y + box.h * 5, &D_08938478,
                      func_0885151C(D_089CC438, D_089ACC04[*(s8 *)(func_088298E4(arg0) + 0x1C)]));
        func_08891474(D_08A631A8, (s16)box.x, box.y + box.h * 7, &D_08938478, func_0886BEA4(D_08A62C7C, 4));
        func_08891474(D_08A631A8, (s16)box.x, box.y + box.h * 10, &D_08938478,
                      func_0885151C(D_089CC438, D_089ACC44[*(u8 *)(func_088298E4(arg0) + 0x1D)]));
        break;
    case 2:
        func_08890DFC(D_08A631A8, box.x + box.col * 6, box.y + box.h * 2);
        func_0881A9D8(arg0, *(s8 *)(func_088298E4(arg0) + 0x1A));
        func_08891474(D_08A631A8, (s16)box.x, box.y + box.h * 5, &D_08938478, func_0886BEA4(D_08A62C7C, 1));
        func_08891474(D_08A631A8, (s16)box.x, box.y + box.h * 9, &D_08938478, func_0886BEA4(D_08A62C7C, 2));
        break;
    case 3:
        func_08891474(D_08A631A8, box.x + box.col * 4, box.y + box.h * 2, &D_08938478, func_0886BEA4(D_08A62C7C, 5));
        func_08891474(D_08A631A8, (s16)box.x, box.y + box.h * 4, &D_08938478, func_0886BEA4(D_08A62C7C, 3));
        break;
    }
}

}
