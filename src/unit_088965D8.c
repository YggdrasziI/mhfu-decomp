/* unit_088965D8: 0x088965D8-0x088966C0 (ULES01213) */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u16 x;
    u16 y;
    u8 pad4[0x24 - 0x1C];
    s16 tx;
    s16 ty;
    u8 font;
    u8 pad11[0x28 - 0x11];
} Box;

extern char *D_08A631A8;
extern char D_089B167C[];

extern s32 func_08896C58(char *, u8, u8);
extern void func_08896EB8(char *, Box *, s32, u8, u8, s32);
extern void func_08890E40(char *, s32);
extern char *func_08896CA0(char *, u8, u8, u8);
extern void func_08892148(char *, s32, s32, s8, char *, ...);
extern void func_0882DCA0(char *, u16, u16, u16, u16, s32);
extern s32 func_0882FE34(char *, u16, u16, u8, u8);

void func_088965D8(char *arg0, s32 arg1) {
    Box box;

    func_08896EB8(arg0, &box,
                  func_08896C58(arg0, *(u8 *)(arg0 + 0x1111), *(u8 *)(arg0 + 0x1112)),
                  *(u8 *)(arg0 + 0x110E), *(u8 *)(arg0 + 0x1110), arg1);
    func_08890E40(D_08A631A8, box.font);
    func_08892148(D_08A631A8, box.tx, box.ty, 0, D_089B167C,
                  func_08896CA0(arg0, *(u8 *)(arg0 + 0x1111), *(u8 *)(arg0 + 0x1112), *(u8 *)(arg0 + 0x110E)));
    func_0882DCA0(arg0, box.x - 0x40, box.y, 0x40, 0x40, 0xFF);
    func_0882FE34(arg0, box.x - 0x3A, box.y + 7, 0x6C, 0xB4);
}
