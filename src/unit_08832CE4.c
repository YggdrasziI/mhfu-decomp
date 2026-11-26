/* unit_08832CE4: 0x08832CE4-0x08832E34 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern s16 D_08939904[];
extern char D_089386E8[];
extern char *D_08A631A8;

extern void func_0882C7B4(char *, u16, u16, s16, s16, u8, u8, u8, u8, s32, s32);
extern int func_0880E8F0(char *, char *, ...);
extern void func_08890DE8(char *, s8, u8);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_08832CE4(char *arg0, s16 arg1, s16 arg2, u32 arg3, u32 arg4, s32 arg5) {
    char buf[16];
    s16 *tbl = D_08939904;

    if (!(arg5 & 1)) {
        if (arg3 < arg4) {
            func_0882C7B4(arg0, arg1 + 6, arg2 - 0x10, tbl[2], tbl[3], 0, 0xC0, 0x40, 0xFF, 0x9D, 0);
        }
        if (arg3 != 1) {
            func_0882C7B4(arg0, arg1 + 6, arg2 + 0x10, tbl[2], tbl[3], 0, 0xC0, 0x40, 0xFF, 0x9D, 4);
        }
    }
    func_0880E8F0(buf, D_089386E8, arg3);
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_088915B0(D_08A631A8, arg1 + 5, arg2, 0, buf);
}
