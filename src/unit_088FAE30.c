/* unit_088FAE30: 0x088FAE30-0x088FB2B0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between two units.
 * Draws a page of nine lines out of a list of 23 records: a name, a time
 * (minutes and seconds) and a count, each with an icon. A record is two
 * words, at +0x250 and +0x43C of arg1, each a 15-bit and a 17-bit field; it
 * shows when the 17-bit field of the first one is not zero.
 *
 * #pragma optimize_for_size off: the loop steps its pointers instead of
 * indexing (notes/COMPILER.md, "Speed and space").
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct {
    u32 icon : 15;
    u32 value : 17;
} Record;

typedef struct {
    char pad0[0x250];
    /* 0x250 */ Record times[0x17];
    char pad2AC[0x190];
    /* 0x43C */ Record counts[0x17];
} Save;

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B05582;
extern u16 D_09B055BE;
extern u16 D_09B055C0;
extern u16 D_09B055C2;
extern u16 D_09B055C4;
extern u16 D_09B05670[];
extern u16 D_089AC8E4;
extern u16 D_0893AE68[];
extern s32 D_089B81F8[];
extern char D_089B8588[];
extern char D_089B86C8[];
extern char D_089B86D4[];
extern char D_089B86D8[];
extern char D_089B86E0[];

extern int func_0880E8F0(char *, char *, ...);
extern void func_08825DA8(char *);
extern void func_08827918(char *, s32, s32, char *, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882DAC0(char *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern void func_0887D02C(s32, s32, char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_08891474(char *, s32, s16, char *, ...);
extern char *func_09A7B790(s32, u16);

void func_088FAE30(char *arg0, Save *arg1, s32 arg2) {
    char *temp;
    s32 shown;
    s32 first;
    s32 y;
    s32 i;
    Record *time;
    Record *count;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xD;
    func_08890E08(D_08A631A8, 4);
    func_08825DA8(temp);
    func_0882DCB0(D_089CBBEC, 0x10, 0x28, 0x1C0, 0xD8, 0xFF, D_089B81F8[arg2]);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_08890E38(D_08A631A8, 5);
    func_08827918(D_089CBBEC, 0x9A, 0x11, func_09A7B790(D_09B22D70, D_09B055BE), 0xE, 0x10);
    func_0882DAC0(D_089CBBEC, 0x26, 0x40, 0x1BC, 0x40, 0xFF, 0xFF, 0xFF);
    func_08890E38(D_08A631A8, 0);
    func_08891474(D_08A631A8, 0x26, 0x30, func_09A7B790(D_09B22D70, D_09B055C0));
    func_08827918(D_089CBBEC, 0x118, 0x30, func_09A7B790(D_09B22D70, D_09B055C2), 0xE, 0x10);
    func_08827918(D_089CBBEC, 0x18B, 0x30, func_09A7B790(D_09B22D70, D_09B055C4), 0xE, 0x10);
    shown = 0;
    first = *(s8 *)(arg0 + 0x10) * 9;
    for (i = 0; i < 0x17; i++) {
        time = &arg1->times[i];
        count = &arg1->counts[i];
        if (time->value != 0) {
            if (shown >= first) {
                if (shown < first + 9) {
                    y = (shown - first) * 0x12 + 0x44;
                    func_08891474(D_08A631A8, 0x26, y, func_09A7B790(D_09B22D70, D_09B05670[i]));
                    func_0880E8F0(arg0 + 0x88, D_089B86C8, time->value / 60, time->value % 60);
                    func_0887D02C(0x124, y, arg0 + 0x88, 0xE);
                    func_0882A9DC(D_089CBBEC, 0x12A, y, D_0893AE68[time->icon % 12U]);
                    func_0880E8F0(arg0 + 0x88, D_089B86D4, count->value);
                    func_0887D02C(0x19E, y, arg0 + 0x88, 0xE);
                    func_0882A9DC(D_089CBBEC, 0x1A4, y, D_0893AE68[count->icon % 12U]);
                }
            }
            shown++;
        }
    }
    if (shown == 0) {
        if (*(s8 *)(arg0 + 0x10) == 0) {
            func_08891474(D_08A631A8, 0x26, 0x44, func_0885151C(D_089CC438, D_089AC8E4));
            func_0887D02C(0x124, 0x44, D_089B86D8, 0xE);
            func_0887D02C(0x19E, 0x44, D_089B86E0, 0xE);
        }
    }
    if (shown > 9) {
        func_0882A9DC(D_089CBBEC, 0x14A, 0xE8, 0x35);
        func_08891474(D_08A631A8, 0x162, 0xEA, func_09A7B790(D_09B22D70, D_09B05582));
        func_08890E38(D_08A631A8, 5);
        func_08891474(D_08A631A8, 0x1A8, 0xEA, D_089B8588, *(s8 *)(arg0 + 0x10) + 1, *(s8 *)(arg0 + 0x20));
    }
}
