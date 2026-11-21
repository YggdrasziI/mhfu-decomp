/* unit_088FBC3C: 0x088FBC3C-0x088FBE4C (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Draws the caption of entry idx (24-byte records of D_0899D198) with a
 * separator line.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A8;
extern s32 D_089B81F8[];
extern u8 D_0899D198[][24];
extern u16 D_089AC864;

extern void func_08890E40(char *, s32);
extern void func_0882DCB0(char *, u16, u16, s32, s32, s32, s32);
extern void func_08890E38(char *, s8);
extern char *func_08851528(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_0882E2C0(char *, u16, u16, u16, s32, s32, s32, s32);
extern void func_0882DAC0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern s32 func_088303A0(char *, u8);
extern char *func_0885151C(char *, u16);
extern char *func_08851534(char *, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);

void func_088FBC3C(s32 arg0, s32 x, s32 y, s32 idx, s32 kind)
{
    u8 *entry;

    func_08890E40(D_08A631A8, 0x10);
    func_0882DCB0(D_089CBBEC, x, y, 0xF0, 0x50, 0xFF, D_089B81F8[kind]);
    if (idx < 0) {
        return;
    }
    func_08890E38(D_08A631A8, 2);
    func_08891474(D_08A631A8, x + 8, y + 6, func_08851528(D_089CC438, idx));
    func_0882E2C0(D_089CBBEC, idx, x + 0xE, y + 0x1C, 0x18, 0x18, 1, 0xFF);
    func_0882DAC0(D_089CBBEC, x + 8, y + 0x16, x + 0xEA, y + 0x16, 0xFF, 0xFF, 0xFF);
    entry = D_0899D198[idx];
    func_08890DE8(D_08A631A8, 0xC, 0xC);
    func_08890E38(D_08A631A8, func_088303A0(D_089CBBEC, entry[2]));
    func_088920A8(D_08A631A8, x + 8, y + 0x38, func_0885151C(D_089CC438, D_089AC864), entry[2] + 1);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_088920A8(D_08A631A8, x + 0x30, y + 0x18, func_08851534(D_089CC438, idx));
}
