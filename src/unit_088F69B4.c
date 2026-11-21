/* unit_088F69B4: 0x088F69B4-0x088F7108 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a status page: eleven frame pieces, a name, seven numbered lines,
 * six icons with their names, up to 48 two-byte glyphs on a grid of 24
 * columns, a gauge and two counters.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    /* 0x0 */ u16 x;
    /* 0x2 */ u16 y;
    /* 0x4 */ u16 w;
    /* 0x6 */ u16 h;
} Piece;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern char *D_08A62C54;
extern char *D_089CC438;
extern s32 D_09B22D70;
extern u16 D_09B0556A;
extern u16 D_09B0556C;
extern u16 D_09B0556E;
extern u16 D_09B05570;
extern u16 D_09B05572;
extern u16 D_09B05574;
extern u16 D_09B05576;
extern u16 D_09B05578;
extern u16 D_09B0557A;
extern u16 D_09B055DA;
extern u16 D_09B055DC;
extern s32 D_089B81F8[];
extern Piece D_089B8214[];
extern u8 D_089B8590[];
extern char D_089B8598[];
extern char D_089B85A0[];

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern int func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern void func_08831338(char *, s16, s16, u16, u16, s32, s32, s32, s32);
extern char *func_08851598(char *, u16);
extern char *func_088515C4(char *, u16);
extern char *func_088515F0(char *, u16);
extern char *func_0885161C(char *, u16);
extern char *func_08851648(char *, u16);
extern char *func_0885C968(char *, u8, u16);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_088F4210(char *, s32, s32, s32);
extern void func_088F4518(char *, s32, s32, s32);
extern void func_08901924(char *, char *, char *);
extern char *func_09A7B790(s32, u16);

void func_088F69B4(char *arg0, char *arg1, s32 arg2) {
    u16 glyph[2];
    s32 k;
    s32 j;
    s32 y;
    u8 *p;
    Piece *piece = D_089B8214;
    char *temp;
    s32 i;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    for (i = 0; i < 0xB; i++, piece++) {
        func_0882DCB0(D_089CBBEC, piece->x, piece->y, piece->w, piece->h, 0xFF, D_089B81F8[arg2]);
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_08901924(arg0, arg0 + 0x88, arg1 + 0x9A);
    func_08890E38(D_08A631A8, 1);
    func_08891474(D_08A631A8, 0x16, 0x11, arg0 + 0x88);
    func_08890E38(D_08A631A8, 2);
    func_08891474(D_08A631A8, 0x18, 0x13, arg0 + 0x88);
    func_08890E38(D_08A631A8, 6);
    func_08890DE8(D_08A631A8, 0x10, 0xE);
    func_088912BC(D_08A631A8, 0x16, 0x2F, arg1);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_0880E8F0(arg0 + 0x88, D_089B8598, func_09A7B790(D_09B22D70, D_09B0556C), *(u8 *)(arg1 + 0x97) + 1);
    func_08891474(D_08A631A8, 0x126, 0x12, arg0 + 0x88);
    for (j = 0, y = 0x4A, p = D_089B8590; j < 7; j++, y += 0x10, p++) {
        func_08891474(D_08A631A8, 0x6C, y, func_09A7B790(D_09B22D70, D_09B05576));
        func_08891474(D_08A631A8, 0x73, y, D_089B85A0, *(u16 *)(arg1 + 0x20 + *p * 2));
    }
    func_08891474(D_08A631A8, 0x16, 0x4A, func_09A7B790(D_09B22D70, D_09B0556E));
    func_08891474(D_08A631A8, 0x16, 0x5A, func_09A7B790(D_09B22D70, D_09B055DA));
    func_08891474(D_08A631A8, 0x16, 0x6A, func_09A7B790(D_09B22D70, D_09B05570));
    func_08891474(D_08A631A8, 0x16, 0x7A, func_09A7B790(D_09B22D70, D_09B05572));
    func_08891474(D_08A631A8, 0x16, 0x8A, func_09A7B790(D_09B22D70, D_09B055DC));
    func_08891474(D_08A631A8, 0x16, 0x9A, func_09A7B790(D_09B22D70, D_09B0557A));
    func_08891474(D_08A631A8, 0x16, 0xAA, func_09A7B790(D_09B22D70, D_09B05574));
    func_08831338(D_089CBBEC, *(u16 *)(arg1 + 0x12), *(u16 *)(arg1 + 0x14), 0xA4, 0x28, 0x18, 0x18, 0xFF, 0);
    func_08831338(D_089CBBEC, 1, *(u16 *)(arg1 + 0x18), 0xA4, 0x42, 0x18, 0x18, 0xFF, 0);
    func_08831338(D_089CBBEC, 2, *(u16 *)(arg1 + 0x1A), 0xA4, 0x5C, 0x18, 0x18, 0xFF, 0);
    func_08831338(D_089CBBEC, 3, *(u16 *)(arg1 + 0x1C), 0xA4, 0x76, 0x18, 0x18, 0xFF, 0);
    func_08831338(D_089CBBEC, 4, *(u16 *)(arg1 + 0x1E), 0xA4, 0x90, 0x18, 0x18, 0xFF, 0);
    func_08831338(D_089CBBEC, 0, *(u16 *)(arg1 + 0x16), 0xA4, 0xAA, 0x18, 0x18, 0xFF, 0);
    func_08891474(D_08A631A8, 0xC8, 0x2D, func_0885C968(D_08A62C54, *(u16 *)(arg1 + 0x12), *(u16 *)(arg1 + 0x14)));
    func_08891474(D_08A631A8, 0xC8, 0x47, func_08851598(D_089CC438, *(u16 *)(arg1 + 0x18)));
    func_08891474(D_08A631A8, 0xC8, 0x61, func_088515C4(D_089CC438, *(u16 *)(arg1 + 0x1A)));
    func_08891474(D_08A631A8, 0xC8, 0x7B, func_088515F0(D_089CC438, *(u16 *)(arg1 + 0x1C)));
    func_08891474(D_08A631A8, 0xC8, 0x95, func_0885161C(D_089CC438, *(u16 *)(arg1 + 0x1E)));
    func_08891474(D_08A631A8, 0xC8, 0xAF, func_08851648(D_089CC438, *(u16 *)(arg1 + 0x16)));
    for (k = 0; k < 0x30; k++) {
        if (*(u16 *)(arg1 + 0x34 + k * 2) == 0) {
            break;
        }
        glyph[0] = *(u16 *)(arg1 + 0x34 + k * 2);
        glyph[1] = 0;
        func_088912BC(D_08A631A8, 0x16 + (k % 0x18 + 4) * 7, 0xD6 + (k / 0x18) * 0x10, (char *) glyph);
    }
    func_0882A9DC(D_089CBBEC, 0x15A, 0x3C, 0x125);
    func_088F4210(arg0, 0x180, 0x5E, *(u32 *)(arg1 + 0x30) % 100);
    func_0882A9DC(D_089CBBEC, 0x152, 0x9A, 0x123);
    func_088F4518(arg0, 0x165, 0xDC, 4);
    func_0882A9DC(D_089CBBEC, 0x16E, 0xD4, 0x126);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08827918(D_089CBBEC, 0x198, 0x2D, func_09A7B790(D_09B22D70, D_09B0556A), 0xE, 0x10);
    func_08890DE8(D_08A631A8, 0x14, 0x14);
    func_08891474(D_08A631A8, 0x198, 0xE2, func_09A7B790(D_09B22D70, D_09B05578));
    func_08891474(D_08A631A8, 0x1A6, 0xE2, D_089B85A0, *(u32 *)(arg1 + 0x30) / 100);
}
