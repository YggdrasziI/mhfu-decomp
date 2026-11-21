/* unit_088F56B8: 0x088F56B8-0x088F5C88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a box with a title, two captions, four framed fields (the selected
 * one highlighted), three texts picked from tables, a name of up to 48
 * characters on lines of 24 and three button captions.
 *
 * .data 0x089B84FC-0x089B852A: the constants of the two initialised locals
 * (four rectangles, then seven widths), followed by 2 bytes of padding.
 *
 * Optimized for speed: the division by 24 is a multiplication.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 w;
    /* 0x6 */ s16 h;
} Rect;

extern char *D_089CBBEC;
extern char *D_08A631A0;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B05568;
extern u16 D_09B05592;
extern u16 D_09B05594;
extern u16 D_09B05598;
extern u16 D_09B0559A;
extern u16 D_09B055A2;
extern u16 D_09B056D0[];
extern u16 D_09B05A18[];
extern u16 D_089B84D4;
extern u16 D_089B84D6;
extern s16 D_089B84F8;

extern void func_08825DA8(char *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882D8DC(char *, u16, u16, u16, u16, s32, s32, s32, s32);
extern void func_0882F580(char *, u16 *, char *, s32, s32, s32);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s16, s16, u16 *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);

void func_088F56B8(char *arg0, char *arg1, s32 arg2) {
    Rect rects[4] = {
        { 0x0C, 0x2F, 0x69, 0x10 },
        { 0x7C, 0x2F, 0x38, 0x10 },
        { 0xBB, 0x2F, 0x69, 0x10 },
        { 0x28, 0x59, 0xE0, 0x30 },
    };
    char *temp;
    s32 i;
    Rect *p;
    s32 x;
    s32 y;
    s32 j;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xB;
    func_08890E08(D_08A631A8, 2);
    func_08825DA8(temp);
    {
        s16 widths[7] = { 0, 0, -0x14, 0, -0xA, -0xA, 0 };

        D_089B84F8 = widths[*(s32 *)(D_08A631A0 + 0xF7A574)] + 0xEA;
        func_0882F580(D_089CBBEC, &D_089B84D4, func_09A7B790(D_09B22D70, D_09B05594), 0, 0xFF, 3);
    }
    func_08890E38(D_08A631A8, 6);
    func_08891474(D_08A631A8, D_089B84D4 + 0xC, D_089B84D6 + 0x21, func_09A7B790(D_09B22D70, D_09B055A2));
    func_08891474(D_08A631A8, D_089B84D4 + 0xC, D_089B84D6 + 0x4B, func_09A7B790(D_09B22D70, D_09B05568));
    for (i = 0, p = rects; i < 4; i++, p++) {
        if (i == arg2) {
            func_0882D8DC(D_089CBBEC, D_089B84D4 + p->x - 2, D_089B84D6 + p->y - 2, p->w + 4, p->h + 4, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        func_0882D8DC(D_089CBBEC, D_089B84D4 + p->x, D_089B84D6 + p->y, p->w, p->h, 0, 0, 0, 0xFF);
    }
    func_08890E38(D_08A631A8, 0);
    func_08891474(D_08A631A8, D_089B84D4 + rects[0].x + 1, D_089B84D6 + rects[0].y + 2, func_09A7B790(D_09B22D70, D_09B056D0[*(u16 *)(arg1 + 0x9A)]));
    func_08891474(D_08A631A8, D_089B84D4 + rects[1].x + 1, D_089B84D6 + rects[1].y + 2, func_09A7B790(D_09B22D70, D_09B05A18[*(u16 *)(arg1 + 0x9C)]));
    func_08891474(D_08A631A8, D_089B84D4 + rects[2].x + 1, D_089B84D6 + rects[2].y + 2, func_09A7B790(D_09B22D70, D_09B056D0[*(u16 *)(arg1 + 0x9E)]));
    y = D_089B84D6 + rects[3].y + 2;
    x = D_089B84D4 + rects[3].x + 1;
    for (j = 0; j < 0x30; j++, arg1 += 2) {
        u16 str[2];

        if (*(u16 *)(arg1 + 0x34) == 0) {
            break;
        }
        str[0] = *(u16 *)(arg1 + 0x34);
        str[1] = 0;
        func_088912BC(D_08A631A8, x + (j % 24 + 4) * 7, y + ((j / 24) * 16 + 8), str);
    }
    func_0882A9DC(D_089CBBEC, D_089B84D4 + 0x36, D_089B84D6 + 0x8F, 0x33);
    func_0882A9DC(D_089CBBEC, D_089B84D4 + 0x7C, D_089B84D6 + 0x8F, 0x32);
    func_0882A9DC(D_089CBBEC, D_089B84D4 + 0xC2, D_089B84D6 + 0x8F, 0x35);
    func_08891474(D_08A631A8, D_089B84D4 + 0x46, D_089B84D6 + 0x91, func_09A7B790(D_09B22D70, D_09B05598));
    func_08891474(D_08A631A8, D_089B84D4 + 0x8C, D_089B84D6 + 0x91, func_09A7B790(D_09B22D70, D_09B0559A));
    func_08891474(D_08A631A8, D_089B84D4 + 0xD2, D_089B84D6 + 0x91, func_09A7B790(D_09B22D70, D_09B05592));
}
