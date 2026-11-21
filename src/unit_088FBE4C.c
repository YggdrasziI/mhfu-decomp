/* unit_088FBE4C: 0x088FBE4C-0x088FC088 (ULES01213)
 *
 * Bounds (hypothesis): 1 function.
 * Draws a box for entry id with the two s8 fields at +0xF and +0x10 of
 * arg0.
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
extern s32 D_09B22D70;
extern s32 D_089B81F8[];
extern u16 D_089AD058[];
extern u16 D_09B05C08[];
extern u8 D_089B8344[];
extern u8 D_089B8345[];
extern u8 D_089B8346[];
extern s16 D_089B82E4[][8];

extern void func_08890E40(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_0882DCB0(char *, s32, s32, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s16, s16, char *, ...);
extern void func_0882DAC0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_0882B94C(char *, u16, u16, u8, u8, u8, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern char *func_09A7B790(s32, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);

void func_088FBE4C(char *arg0, s32 x, s32 y, s32 id, s32 kind)
{
    s32 i;

    func_08890E40(D_08A631A8, 0x10);
    func_0882DCB0(D_089CBBEC, (u16)x, (u16)y, 0xF0, 0x50, 0xFF, D_089B81F8[kind]);
    if (id < 0) {
        return;
    }
    func_08890E38(D_08A631A8, 2);
    func_08891474(D_08A631A8, x + 8, y + 6, func_0885151C(D_089CC438, D_089AD058[id]));
    func_0882DAC0(D_089CBBEC, x + 8, y + 0x16, x + 0xEA, y + 0x16, 0xFF, 0xFF, 0xFF);
    func_0882B94C(D_089CBBEC, (u16)(x + 6), (u16)(y + 0x18), D_089B8344[kind * 3], D_089B8345[kind * 3], D_089B8346[kind * 3], 0xFF, 0x102);
    i = *(s8 *)(arg0 + 0x10) + *(s8 *)(arg0 + 0xF) * 0x18;
    func_0882A9DC(D_089CBBEC, (u16)(x + 0xA), (u16)(y + 0x1C), D_089B82E4[i / 8][*(s8 *)(arg0 + 0x10) % 8]);
    func_08890E38(D_08A631A8, 0);
    func_088920A8(D_08A631A8, x + 0x28, y + 0x18, func_09A7B790(D_09B22D70, D_09B05C08[id]));
}
