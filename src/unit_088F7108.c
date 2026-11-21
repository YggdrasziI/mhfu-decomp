/* unit_088F7108: 0x088F7108-0x088F7620 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a bar chart: a scale of up to four graduations and eleven coloured
 * bars with their icon and value.
 *
 * The fifteen words at 0x089B85A4-0x089B85E0 (eleven colours, four scale
 * values) are copied to the stack one by one through float registers. They
 * are probably the constants of two initialised locals (hypothesis); an
 * initialiser does not give that copy, so they are read as externs through a
 * float view and stay in the data piece.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef union {
    float f;
    u8 b[4];
} Color;

typedef struct {
    Color a;
    Color b;
} Color2;

typedef struct {
    float a;
    float b;
} Pair;

typedef struct {
    /* 0x0 */ s32 column;
    /* 0x4 */ s32 icon;
} Bar;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B055CE;
extern u16 D_09B05582;
extern s32 D_089B81F8[];
extern Bar D_089B83B8[];
extern char D_089B8588[];
/* "%4d", then the constants of two initialised local arrays, eleven colours
 * and four scales, named by the symbols of the 8-byte pieces they are read
 * from; copied word by word through float members. */
extern char D_089B85A0[];
extern Color2 D_089B85A8;
extern Color2 D_089B85B0;
extern Color2 D_089B85B8;
extern Color2 D_089B85C0;
extern Color2 D_089B85C8;
extern Pair D_089B85D0;
extern float D_089B85D8;
extern float D_089B85DC;

extern int func_08890E08(char *, s32);
extern void func_08825DA8(char *);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern char *func_09A7B790(s32, u16);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_0882D6F0(char *, u16, u16, u16, u16, u8, u8, u8);
extern void func_0882BE60(char *, u16, u16, u16, u16, u8, u8, u8, s32);

void func_088F7108(char *arg0, char *arg1, s32 arg2) {
    Color col[11];
    union {
        float f;
        u32 u;
    } scale[4];
    char *temp;
    u32 max;
    u16 *val;
    u32 i;
    Color *c;
    u16 x;
    u16 y;
    u16 h;
    u16 ty;

    col[0].f = (*(Color *) (D_089B85A0 + 4)).f;
    col[1].f = D_089B85A8.a.f;
    col[2].f = D_089B85A8.b.f;
    col[3].f = D_089B85B0.a.f;
    col[4].f = D_089B85B0.b.f;
    col[5].f = D_089B85B8.a.f;
    col[6].f = D_089B85B8.b.f;
    col[7].f = D_089B85C0.a.f;
    col[8].f = D_089B85C0.b.f;
    col[9].f = D_089B85C8.a.f;
    col[10].f = D_089B85C8.b.f;
    scale[0].f = D_089B85D0.a;
    scale[1].f = D_089B85D0.b;
    scale[2].f = D_089B85D8;
    scale[3].f = D_089B85DC;
    max = scale[*(s8 *) (arg0 + 0x10)].u;
    val = (u16 *) (arg1 + 0x628);
    temp = D_089CBBEC;
    *(s8 *) (temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, func_09A7B790(D_09B22D70, D_09B055CE), 0xE, 0x10);
    func_08890E38(D_08A631A8, 0);
    if (*(s8 *) (arg0 + 0x1D) != 0) {
        func_0882DCB0(D_089CBBEC, 0x150, 0x2E, 0x80, 0x18, 0xFF, D_089B81F8[arg2]);
        func_0882A9DC(D_089CBBEC, 0x156, 0x32, 0x35);
        func_08891474(D_08A631A8, 0x16A, 0x34, func_09A7B790(D_09B22D70, D_09B05582));
        func_08891474(D_08A631A8, 0x1B4, 0x34, D_089B8588, *(s8 *) (arg0 + 0x10) + 1, *(s8 *) (arg0 + 0x1D) + 1);
    }
    func_0882DCB0(D_089CBBEC, 0x10, 0x4C, 0x1C0, 0xA8, 0xFF, D_089B81F8[arg2]);
    func_08890DE8(D_08A631A8, 0xC, 0xC);
    func_0882D6F0(D_089CBBEC, 0x32, 0x63, 0x19A, 1, 0xFF, 0, 0);
    func_08891474(D_08A631A8, 0x14, 0x5F, D_089B85A0, max);
    if (*(s8 *) (arg0 + 0x10)) {
        for (i = 0; i < *(s8 *) (arg0 + 0x10); i++) {
            y = 0xEF - (u16) (scale[i].u * 0x8C / max);
            if (y < 0xE5) {
                func_0882D6F0(D_089CBBEC, 0x32, y, 0x19A, 1, 0xFF, 0, 0);
                func_08891474(D_08A631A8, 0x14, y - 4, D_089B85A0, scale[i].u);
            }
        }
    }
    for (i = 0; i < 0xB; i++, val++) {
        if (!(max < *val)) {
            h = *val * 0x8C / max;
            y = 0xEF - h;
            ty = y - 0xE;
        } else {
            y = 0x4F;
            h = 0xA0;
            ty = 0x50;
        }
        c = &col[i];
        x = D_089B83B8[i].column * 0x25 + 0x38;
        func_0882D6F0(D_089CBBEC, x + *(s8 *) (arg0 + 0x10) * 2, y, 0x18 - *(s8 *) (arg0 + 0x10) * 4, h,
                      c->b[2], c->b[1], c->b[0]);
        func_0882BE60(D_089CBBEC, x + 4, 0xF6, 0x10, 0x10, c->b[2], c->b[1], c->b[0],
                      D_089B83B8[i].icon);
        func_08890E38(D_08A631A8, 1);
        func_08891474(D_08A631A8, x + 1, ty + 1, D_089B85A0, *val);
        func_08890E38(D_08A631A8, 0);
        func_08891474(D_08A631A8, x, ty, D_089B85A0, *val);
    }
}
