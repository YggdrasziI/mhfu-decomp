/* unit_08896D24: 0x08896D24-0x08896EB8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Fills a box (local one when none is given), centres a text in it, draws
 * it, then prints the string of D_089AD0B8 under it.
 */

typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Box {
    u16 x;
    u8 unk2[2];
    u16 w;
    u8 unk6[5];
    u8 unkB;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u8 unk12[0x12];
    u16 unk24;
    u8 unk26[2];
} Box;

extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089AD0B8;
extern char D_089B1680[];
extern char D_089B167C[];

extern void func_0882FA24(Box *, char *, s32, s32, s32);
extern s32 func_08890E48(char *, char *);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);
extern void func_0882FB38(char *, Box *, u16, u16, s32, s32);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern char *func_0885151C(char *, u16);
extern int func_088915B0(char *, s16, s16, s32, char *, ...);

void func_08896D24(char *arg0, Box *box, char *text, s8 color, u8 arg4, u8 arg5, s32 arg6) {
    Box local;
    s32 w;

    if (box == 0) {
        box = &local;
    }
    func_0882FA24(box, D_089B1680, 1, 0, 0);
    if (arg6 != 0) {
        box->unkB = 2;
    }
    w = func_08890E48(D_08A631A8, text) * 7;
    box->unk24 = box->x + ((box->w - w) >> 1);
    func_0882F580(arg0, box, text, color, 0xFF, 0);
    if (arg5 > 1) {
        func_0882FB38(arg0, box, arg4, arg5, 0, 0);
    }
    func_0882A9DC(arg0, box->unkC + 0x108, box->unkE + box->unk10 * 8 - 1, 0x33);
    func_088915B0(D_08A631A8, box->unkC + 0x118, box->unkE + box->unk10 * 8 + 1, 0, D_089B167C,
                  func_0885151C(D_089CC438, D_089AD0B8));
}
