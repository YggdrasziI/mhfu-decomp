/* unit_08852954: 0x08852954-0x08852A44 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/*
 * func_08852954: reads an s16 from the table D_0899CA50 indexed by the two
 * u8 arguments and a 0..3 selector from the bits 0xF0 of D_08A62C68 (or from
 * func_088900C4 when none is set).
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern char *D_08A631A0;
extern s32 D_08A62C68;
extern s16 D_0899CA50[];

extern u16 func_088900C4(char *, s32);

s16 func_08852954(s32 arg0, u8 arg1, u8 arg2) {
    u16 sel;
    s32 flags;

    func_088900C4(D_08A631A0, 1);
    func_088900C4(D_08A631A0, 1);
    func_088900C4(D_08A631A0, 1);
    flags = D_08A62C68;
    if (flags & 0xF0) {
        if (flags & 0x10) {
            sel = 0;
        } else if (flags & 0x40) {
            sel = 1;
        } else if (flags & 0x80) {
            sel = 2;
        } else {
            sel = 3;
        }
    } else {
        sel = func_088900C4(D_08A631A0, 1) & 3;
    }
    return D_0899CA50[sel + arg1 * 68 + arg2 * 4];
}
