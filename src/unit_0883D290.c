/* unit_0883D290: 0x0883D290-0x0883D3D4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;     /* 0x00 */
    u16 y;     /* 0x02 */
    u16 w;     /* 0x04 */
    u16 h;     /* 0x06 */
    u8 b8;     /* 0x08 */
    u8 b9;     /* 0x09 */
    u8 bA;     /* 0x0A */
    u8 bB;     /* 0x0B */
    u16 hC;    /* 0x0C */
    s16 hE;    /* 0x0E */
    s32 w10;   /* 0x10 */
} Box;

extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B052C0[];

extern void func_0882FC50(char *, Box *, char *, s32);
extern void func_08890DE8(char *, s8, u8);
extern void func_088912BC(char *, s16, s16, char *);
extern char *func_09A7B790(s32, u16);
extern void func_08891474(char *, s16, s16, char *, ...);

void func_0883D290(char *arg0) {
    s32 i;
    Box box = { 8, 0x58, 0xB0, 0xB0, 0xE, 0xE, 5, 0, 0x10, 0x60, 0x10 };

    func_0882FC50(arg0, &box, 0, 0xFF);
    for (i = 0; i < 5; i++, arg0 += 0x18) {
        if (*(s32 *)(arg0 + 0x620) != -1) {
            func_08890DE8(D_08A631A8, 0x10, 0xE);
            func_088912BC(D_08A631A8, box.hC, (u16)box.hE + i * box.w10 * 2, arg0 + 0x60C);
            func_08890DE8(D_08A631A8, 0xE, 0xE);
            func_08891474(D_08A631A8, box.hC, (u16)box.hE + i * box.w10 * 2,
                          func_09A7B790(D_09B22D70, D_09B052C0[*(s32 *)(arg0 + 0x620)]));
        }
    }
}
