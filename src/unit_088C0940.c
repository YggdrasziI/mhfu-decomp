/* unit_088C0940: 0x088C0940-0x088C0BBC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_088C05FC and text_088C0BBC).
 *
 * Optimized for speed: the divisions by 60 are multiplications. The record
 * pointer is recomputed from the index (`arg1 + i * 0x6B100`). Parameter types
 * of func_08891474 and func_088912BC are the ones that schedule the argument
 * loads as in the original.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A8;
extern s16 D_089B2DF0[][10];
extern char D_089B4E3C;
extern char D_089B4E58;

extern char *func_08851680(char *, u16);
extern int func_0880E8F0(char *, char *, ...);
extern void func_088BA5BC(s16, s16, s16, s16);
extern void func_08891474(char *, s32, s16, char *, ...);
extern void func_08890DE8(char *, s8, u8);
extern void func_088912BC(char *, s16, s32, char *);
extern void func_08831F3C(char *, u16, u16, u16, u16, s32, s32, s32);

void func_088C0940(char *arg0, char *arg1) {
    char text[0x100];
    s32 i;
    char *name;
    char *unit;
    u32 t;
    s16 *e;
    char *p;

    for (i = 0; i < 3; i++) {
        p = arg1 + i * 0x6B100;
        if (*(u8 *)(p + 0x1012) != 0) {
            if (*(u8 *)(p + 0x1013) == 0) {
                name = func_08851680(D_089CC438, 0x10);
            } else {
                name = func_08851680(D_089CC438, 0x11);
            }
            t = *(u32 *)(p + 0x4FC8) / 60;
            unit = func_08851680(D_089CC438, 0xF);
            func_0880E8F0(text, &D_089B4E3C, i + 1, unit, t / 60, t % 60, name, func_08851680(D_089CC438, 0x12), *(s32 *)(p + 0x6A250));
        } else {
            func_0880E8F0(text, &D_089B4E58, i + 1, func_08851680(D_089CC438, 0x13));
        }
        e = D_089B2DF0[i + 2];
        func_088BA5BC(e[0], e[1], e[2], e[3]);
        func_08891474(D_08A631A8, e[6], e[7], text);
        if (*(u8 *)(p + 0x1012) != 0) {
            func_08890DE8(D_08A631A8, 0x10, 0xE);
            func_088912BC(D_08A631A8, (u16) D_089B2DF0[i][0x1A] + 0xE, D_089B2DF0[i][0x1B], p + 0x1000);
            func_08890DE8(D_08A631A8, 0xE, 0xE);
        }
    }
    e = D_089B2DF0[*(s32 *)(arg0 + 8) + 2];
    func_08831F3C(D_089CBBEC, (u16) e[0] + 4, (u16) e[1] + 3, (u16) e[2] - 8, (u16) e[3] - 6, 0, 0x80, 0);
}