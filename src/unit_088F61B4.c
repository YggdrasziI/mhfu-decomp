/* unit_088F61B4: 0x088F61B4-0x088F6450 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Draws a box with a title, up to three coloured lines of text (0x1C-byte
 * entries) and two button captions.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x00 */ u16 kind;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ char text[0x18];
} Line;

extern char *D_089CBBEC;
extern char *D_08A631A8;
extern s32 D_09B22D70;
extern u16 D_09B05596;
extern u16 D_09B055B2;
extern u16 D_09B055B4;
extern u16 D_089B8560;
extern u16 D_089B8562;
extern s16 D_089B856C;
extern u16 D_089B856E;
extern u16 D_089B8570;

extern void func_08825DA8(char *);
extern s32 func_0882A9DC(char *, u16, u16, s32);
extern void func_0882D6F0(char *, u16, u16, u16, u16, s32, s32, s32);
extern void func_0882F580(char *, u16 *, char *, s32, s32, s32);
extern void func_08890DE8(char *, s8, u8);
extern int func_08890E08(char *, s32);
extern void func_08890E38(char *, s8);
extern void func_088912BC(char *, s32, s16, char *);
extern void func_08891474(char *, s16, s16, char *, ...);
extern char *func_09A7B790(s32, u16);

void func_088F61B4(char *arg0, Line *arg1, s8 arg2) {
    char *temp;
    s32 i;

    temp = D_089CBBEC;
    *(s8 *)(temp + 0x534) = 0xA;
    func_08890E08(D_08A631A8, 1);
    func_08825DA8(temp);
    func_0882F580(D_089CBBEC, &D_089B8560, func_09A7B790(D_09B22D70, D_09B05596), arg2, 0xFF, 3);
    func_08890DE8(D_08A631A8, 0x10, 0xE);
    for (i = 0; i < 3; i++, arg1++) {
        if (arg1->kind != 0) {
            if (arg1->kind == 1) {
                func_08890E38(D_08A631A8, 0);
            } else if (arg1->kind == 2) {
                func_08890E38(D_08A631A8, 5);
            } else {
                func_08890E38(D_08A631A8, 9);
            }
            func_088912BC(D_08A631A8, D_089B856C, D_089B856E + D_089B8570 * i, arg1->text);
        }
    }
    func_08890DE8(D_08A631A8, 0xE, 0xE);
    func_0882D6F0(D_089CBBEC, D_089B8560 + 7, D_089B8562 + 0x47, 0x92, 1, 0x80, 0x80, 0x80);
    func_0882A9DC(D_089CBBEC, D_089B8560 + 0xC, D_089B8562 + 0x48, 0x35);
    func_0882A9DC(D_089CBBEC, D_089B8560 + 0x52, D_089B8562 + 0x48, 0x33);
    func_08890E38(D_08A631A8, 0);
    func_08891474(D_08A631A8, D_089B8560 + 0x1C, D_089B8562 + 0x49, func_09A7B790(D_09B22D70, D_09B055B2));
    func_08891474(D_08A631A8, D_089B8560 + 0x62, D_089B8562 + 0x49, func_09A7B790(D_09B22D70, D_09B055B4));
}
