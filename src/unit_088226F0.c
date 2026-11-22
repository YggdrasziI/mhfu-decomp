/* unit_088226F0: 0x088226F0-0x08822990 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08822594 and unit_08822990). Sibling of func_0882232C.
 *
 * The two colours are s8 locals: as s32 they are sign-extended for
 * func_08890E38's s8 parameter.
 */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CC438;
extern char *D_08A631A8;
extern u16 D_089AC98A;
extern char D_089385F0;

extern void func_08821890(char *, s32);
extern void func_08821A10(char *, s32, s32);
extern void func_08821924(char *, s32);
extern u8 func_08822990(char *, s32);
extern s32 func_088DA398(s32, s32);
extern u8 func_088D6A1C(s32, s32);
extern void func_08890E38(char *, s8);
extern char *func_0885151C(char *, u16);
extern void func_08891474(char *, s32, s16, char *, ...);
extern int func_0880E8F0(char *, char *, ...);
extern int func_0880ED70(char *, char *);
extern void func_08891700(char *, s16, s16, char *, ...);

void func_088226F0(char *arg0, s32 arg1, u8 *arg2, u16 x, u16 y, s32 arg5) {
    s16 own;
    s16 other;
    char name[16];
    s8 mark;
    char text[8];
    s8 colour;

    if (arg2[1] != 6 && arg2[1] != 5) {
        return;
    }
    func_08821890(arg0, arg1);
    colour = 5;
    mark = 0;
    func_08821A10(arg0, arg1, (s32) arg2);
    own = 0;
    if (func_08822990(arg0, arg1) == 1) {
        own = func_088DA398(arg1, 8);
        if (func_088D6A1C(arg1, 0x20) == 1 || func_088D6A1C(arg1, 0x21) == 1 ||
            func_088D6A1C(arg1, 0x22) == 1 || func_088D6A1C(arg1, 0x23) == 1 ||
            func_088D6A1C(arg1, 0x24) == 1 || func_088D6A1C(arg1, 0x25) == 1) {
            mark = 3;
            colour = mark;
        }
    }
    func_08821924(arg0, arg1);
    if (arg5 != 0) {
        func_08821A10(arg0, arg1, arg5);
        other = 0;
        if (func_08822990(arg0, arg1) == 1) {
            other = func_088DA398(arg1, 8);
        }
        func_08821924(arg0, arg1);
        if (other < own) {
            mark = 4;
        } else if (own < other) {
            mark = 2;
        }
    }
    func_08890E38(D_08A631A8, colour);
    func_08891474(D_08A631A8, (s16) x, y, func_0885151C(D_089CC438, D_089AC98A));
    func_08890E38(D_08A631A8, mark);
    func_0880E8F0(text, &D_089385F0, own);
    func_0880ED70(name, text);
    func_08891700(D_08A631A8, x + 0x38, y, name);
}