/* unit_0883E4B8: 0x0883E4B8-0x0883E928 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. It owns one initialised local, the
 * layout record (0x0893B488-0x0893B49C, 20 bytes). The frame record
 * D_0893B0F4 is a global copied whole (member by member in C++).
 * Speed setting: the record copies are unrolled. The two early returns
 * are one `||` guard; the instructions left dead after each `b` (blocks
 * whose first instruction fills a branch-likely slot) come with it.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;
typedef unsigned int u32;

typedef struct Box {
    u8 unk0[0xC];
    s16 x;
    u16 y;
    u16 h;
    u8 unk12[6];
    s32 color;
    u8 unk1C[0xC];
} Box;

typedef struct Frame {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 u;
    u16 v;
    s32 color;
} Frame;

typedef struct Layout {
    u16 x;
    u16 y;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u16 w;
    u16 h;
    u16 u;
    u16 v;
    u32 color;
} Layout;

extern "C" {
extern s32 D_0893AA94[];
extern s32 D_0893AAB0[];
extern const Frame D_0893B0F4;
extern char D_0893B108;
extern char D_0893B11C;
extern char D_0893B130;
extern u16 D_089AC600;
extern u16 D_089AC602;
extern u16 D_089AC84C;
extern u16 D_089AC84E;
extern u16 D_089AC9FE;
extern char *D_089CC438;
extern char *D_08A62C50;
extern char *D_08A631A8;
extern u16 D_09B04E06;
extern s32 D_09B22D70;

extern void func_0880E8F0(char *, char *, ...);
extern void func_08819128(char *, s32, u16, s32);
extern void func_088197A0(char *, s32, s32, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882F9A8(char *, char *, char *, s32, s32, s32);
extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882FC50(char *, Frame *, char *, s32);
extern char *func_0885151C(char *, u16);
extern char *func_08851528(char *, u16);
extern s32 func_0885C3DC(char *, u16);
extern s32 func_08890E48(char *, char *);
extern int func_088915B0(char *, s32, s16, s32, char *, ...);
extern char *func_09A7B790(s32, u16);

}

extern "C" void func_0883E4B8(char *p) {
    Layout layout = {0xE0, 0xB8, 0x0E, 0x0E, 0x00, 0x01, 0x0C, 0x03, 0, 0, 0x8000C040};
    s8 lvl;
    s32 n;
    u8 c;

    if (*(u8 *)(p + 0x52F) <= 2 || *(u8 *)(p + 0x52F) == 7) {
        return;
    }
    func_088197A0(p, *(u8 *)(p + 0x586), D_0893AA94[*(u8 *)(p + 0x52F)], 0x10, 0);
    if (*(s8 *)(p + 0x592) == 0) {
        Frame f = D_0893B0F4;

        n = func_08890E48(D_08A631A8, func_0885151C(D_089CC438, D_089AC84C));
        n = n * f.b0;
        f.u = 0xF0 - (n >> 2);
        f.w = ((n >> 1) + 0x20) / 16 * 16;
        f.x = 0xF0 - (f.w >> 1);
        func_0882FC50(p, &f, func_0885151C(D_089CC438, D_089AC84C), 0xFF);
        *(s32 *)(*(char **)(p + 0x530) + 0x614) &= ~1;
    } else {
        lvl = *(s8 *)(p + 0x593);
        if (lvl < 2) {
            func_0882FC50(p, (Frame *)&D_0893B108, func_08851528(D_089CC438, *(u16 *)(p + 0x590)), 0xFF);
        } else {
            char buf[64];

            func_0880E8F0(buf, func_0885151C(D_089CC438, D_089AC84E), func_08851528(D_089CC438, *(u16 *)(p + 0x590)), lvl);
            func_0882FC50(p, (Frame *)&D_0893B11C, buf, 0xFF);
        }
    }
    func_08819128(p, 1, *(u16 *)(p + 0x58E), -1);
    switch (*(u8 *)(p + 0x52F)) {
    case 4:
        if (*(u8 *)(p + 0x5DA) == 0) {
            func_0882A9DC(p, 0x10E, 0x50, 0x35);
            func_088915B0(D_08A631A8, 0x120, 0x52, 0, func_0885151C(D_089CC438, D_089AC9FE));
        }
    case 3: {
        Box box;

        func_0882FA24(&box, (char *)&layout, 0, 0, 0);
        box.color = D_0893AAB0[*(u8 *)(p + 0x52F)];
        func_0882F580(p, &box, 0, *(u8 *)(p + 0x58C), 0xFF, 0);
        c = ((s32)(func_0885C3DC(D_08A62C50, *(u16 *)(p + 0x590)) < *(s8 *)(p + 0x593)) == 0) ? (u8)0 : (u8)10;
        func_088915B0(D_08A631A8, box.x, (s16)box.y, (s8)c, func_09A7B790(D_09B22D70, D_09B04E06));
        func_088915B0(D_08A631A8, box.x, (s16)(box.y + box.h), 0, func_0885151C(D_089CC438, D_089AC600));
        func_088915B0(D_08A631A8, box.x, (s16)(box.y + box.h * 2), 0, func_0885151C(D_089CC438, D_089AC602));
        break;
    }
    case 5:
        func_0882F9A8(p, &D_0893B130, 0, *(u8 *)(p + 0x537), 0xFF, 0);
    }
}
