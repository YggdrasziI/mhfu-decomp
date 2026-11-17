/* unit_0883E400: 0x0883E400-0x0883E4B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly. Its
 * initialised array (0x0893B474-0x0893B480, in .data) is linked from this
 * unit.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char D_0893B480;
extern s32 D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A8;

extern void func_0882DCA0(s32, u16, u16, u16, u16, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern void func_08891474(char *, s32, s32, char *, ...);

void func_0883E400(void) {
    u16 pos[6] = {0x168, 0, 0x70, 0x18, 0x194, 6};

    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_08890E38(D_08A631A8, 0);
    func_0882DCA0(D_089CBBEC, pos[0], pos[1], pos[2], pos[3], 0xFF);
    func_08891474(D_08A631A8, (s16) pos[4], (s16) pos[5], &D_0893B480, *(s32 *)(D_089CC438 + 0x696F0));
}