/* unit_08832E34: 0x08832E34-0x08832F20 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089ACA08;
extern void func_0882DCA8(char *, u16, u16, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern char *func_0885151C(char *, u16);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);
extern void func_08832CE4(char *, s16, s16, s32, s32, s32);

void func_08832E34(char *arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5) {
    func_0882DCA8(arg0, arg1, arg2, 0x58, 0x30, 0xFF);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_088915B0(D_08A631A8, arg1 + 8, arg2 + 8, 5, func_0885151C(D_089CC438, D_089ACA08));
    func_08832CE4(arg0, arg1 + 0x34, arg2 + 0x12, arg3, arg4, arg5);
}
