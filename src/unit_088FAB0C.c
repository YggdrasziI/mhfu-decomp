/* unit_088FAB0C: 0x088FAB0C-0x088FAE30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a page of nine lines out of a list of 31 eight-byte entries (at
 * +0x150 of arg1; an entry shows when its bit 0 is set or its 14-bit count is
 * not zero), with the frame, the captions and the page number.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B05580;
extern u16 D_09B05582;
extern u16 D_09B05584;
extern u16 D_09B05586;
extern u16 D_09B05588;
extern s32 D_089B81F8[];
extern char D_089B8588[];

extern void func_08825DA8(char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882DAC0(char *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_08891474(char *, s32, s16, char *, ...);
extern void func_088FC088(char *, s32, s32, char *, s32);
extern char *func_09A7B790(s32, u16);

void func_088FAB0C(char *arg0, char *arg1, s32 arg2) {
    char *temp;
    s32 shown;
    s32 i;
    s32 first;
    char *entry;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_0882DCB0(D_089CBBEC, 0x10, 0x28, 0x1C0, 0xD8, 0xFF, D_089B81F8[arg2]);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, func_09A7B790(D_09B22D70, D_09B05580), 0xE, 0x10);
    func_0882DAC0(D_089CBBEC, 0x26, 0x40, 0x1BC, 0x40, 0xFF, 0xFF, 0xFF);
    func_08890E38(D_08A631A8, 0);
    func_08891474(D_08A631A8, 0x26, 0x30, func_09A7B790(D_09B22D70, D_09B05584));
    func_08827918(D_089CBBEC, 0xFF, 0x30, func_09A7B790(D_09B22D70, D_09B05588), 0xE, 0x10);
    func_08827918(D_089CBBEC, 0x192, 0x30, func_09A7B790(D_09B22D70, D_09B05586), 0xE, 0x10);
    shown = 0;
    first = *(s8 *)(arg0 + 0x10) * 9;
    for (i = 0, entry = arg1; i < 0x1F; i++, entry += 8) {
        if (!(*(u8 *)(entry + 0x150) & 1) && (*(u16 *)(entry + 0x152) & 0x3FFF) <= 0) {
            continue;
        }
        if (shown >= first) {
            if (shown < first + 9) {
                func_088FC088(arg0, 0x26, (shown - first) * 0x12 + 0x44, arg1, i);
            }
        }
        shown++;
    }
    if (shown == 0) {
        if (*(s8 *)(arg0 + 0x10) == 0) {
            func_088FC088(arg0, 0x26, 0x44, arg1, 0);
        }
    }
    if (shown > 9) {
        func_0882A9DC(D_089CBBEC, 0x14A, 0xE8, 0x35);
        func_08891474(D_08A631A8, 0x162, 0xEA, func_09A7B790(D_09B22D70, D_09B05582));
        func_08890E38(D_08A631A8, 5);
        func_08891474(D_08A631A8, 0x1A8, 0xEA, D_089B8588, *(s8 *)(arg0 + 0x10) + 1, *(s8 *)(arg0 + 0x1F));
    }
}
