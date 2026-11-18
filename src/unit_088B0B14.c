/* unit_088B0B14: 0x088B0B14-0x088B0C3C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0A58 and unit_088B0C3C.
 *
 * Starts a session with the settings arg0 (0x16 bytes, then 0xA4 bytes at
 * +0x18), kept twice (D_09A201F8 / D_09A20210 and D_09A28884 /
 * D_09A2889C) with the console address (D_09A201F0, D_09A2887C). The
 * state D_09A1FDE0 goes from 0 to 1 (timer started, func_088AAED0 with
 * 10000, func_088AFC28) or from 2 to 3 (func_088B7A5C). Returns 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    char unk0[0x12];
    u16 unk12;
} T14;

extern char D_09A2851C[];
extern u8 D_09A1FDE0;
extern u8 D_09A201F0[];
extern char D_09A201F8[];
extern char D_09A20210[];
extern s32 D_09A202D0;
extern s32 D_09A201E8;
extern s32 D_09A202C8;
extern u8 D_09A2887C[];
extern char D_09A28884[];
extern char D_09A2889C[];

extern void func_0880C464(void *, s32, s32);
extern void func_0880C084(void *, void *, s32);
extern s32 func_088B0554(u8 *);
extern s32 func_088AAED0(T14 *);
extern void func_088AFC28(void);
extern void func_088B7A5C(void);

s32 func_088B0B14(char *arg0) {
    T14 t;

    func_0880C464(D_09A2851C, 0, 0x1C740);
    func_088B0554(D_09A201F0);
    func_0880C084(D_09A201F8, arg0, 0x16);
    func_0880C084(D_09A20210, arg0 + 0x18, 0xA4);
    switch (D_09A1FDE0) {
    case 0:
        D_09A1FDE0 = 1;
        t.unk12 = 10000;
        D_09A202D0 = func_088AAED0(&t);
        func_088AFC28();
        D_09A201E8 = 60;
        break;
    case 1:
    case 3:
        break;
    case 2:
        D_09A1FDE0 = 3;
        func_088B7A5C();
        break;
    }
    D_09A202C8 = 1;
    func_088B0554(D_09A2887C);
    func_0880C084(D_09A28884, arg0, 0x16);
    func_0880C084(D_09A2889C, arg0 + 0x18, 0xA4);
    return 0;
}
