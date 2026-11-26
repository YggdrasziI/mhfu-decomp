/* unit_08845C68: 0x08845C68-0x08845EA8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * D_0893B654-D_0893B65A are declared `const`: their loads then do not wait
 * for the prologue stores, and the first `lui` is scheduled before `sw s0`.
 * Declaring the other globals `const` as well breaks the match.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern const u16 D_0893B654, D_0893B656, D_0893B658, D_0893B65A;
extern u16 D_0893B660, D_0893B662, D_0893B664, D_0893B666;
extern u16 D_0893B668, D_0893B66A, D_0893B66C, D_0893B66E;
extern u16 D_0893B670, D_0893B672, D_0893B674, D_0893B676;
extern u16 D_0893B678, D_0893B67A, D_0893B67C, D_0893B67E;
extern u16 D_0893B680, D_0893B682;
extern char *D_089CC438;
extern char *D_08A631A8;

extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern void func_0884711C(char *, u16, u16, u16, u16);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern void func_08832B98(char *, s32);
extern u8 func_0882693C(char *, u16);
extern u16 *func_08856884(char *, s32);
extern void func_0882E0D0(char *, u16, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_088474DC(char *, u8, s16);
extern void func_088471D8(char *, u16, u16, u16, u16, u8);

void func_08845C68(char *arg0) {
    char *p;
    s32 flag;
    s16 off;
    u16 y;
    s8 c;

    p = *(char **)(arg0 + 0x530);
    flag = *(u8 *)(p + 0x5F3) != 1;
    func_0882DCA0(arg0, D_0893B654, D_0893B656, D_0893B658, D_0893B65A, 0xFF);
    func_0884711C(arg0, D_0893B660, D_0893B662, D_0893B664, D_0893B666);
    func_0882A9DC(arg0, D_0893B668, D_0893B66A, 0x24);
    func_0882A9DC(arg0, 0x192, 0xE0, 0x1A1);
    func_0882C7B4(arg0, 0x166, 0xE0, 0x18, 0x10, 0xFF, 0xFF, 0xFF, 0xFF, 0x1A1, 1);
    func_08832B98(arg0, 1);
    off = 0;
    if (*(u8 *)(p + 0x674) & 1) {
        off += 2;
    }
    func_0882A9DC(arg0, D_0893B66C, D_0893B66E + off, 0x35);
    func_0882A9DC(arg0, D_0893B670, D_0893B672, 0x36);
    if (func_0882693C(arg0, *(u16 *)(p + 0x648)) == 1) {
        func_0882E0D0(arg0, *func_08856884(D_089CC438, *(u16 *)(p + 0x648)),
                      D_0893B674, D_0893B676, D_0893B678, D_0893B67A, 0);
    }
    if (!(u8)flag) {
        c = -1;
        y = D_0893B67E + 2;
        if (*(s16 *)(p + 0x646) != 0) {
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            c = *(s8 *)(p + 0x686);
            func_088474DC(arg0, c, (s16)y);
        }
        func_088471D8(arg0, D_0893B67C, D_0893B67E, D_0893B680, D_0893B682, c);
    }
}
