/* unit_088B63A4: 0x088B63A4-0x088B650C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern int func_088AFE78(void);
extern int func_088AFFE8(s32, u8);
extern int func_088B0010(s32, u16);
extern int func_088B0044(s32, s32);
extern int func_088B00DC(s32, char *, u16);
extern int func_088B0240(s32, char *);
extern int func_088B0318(char *, s32);
extern s32 func_088B03BC(char *, s32);
extern s32 func_088B03CC(u16 *, s32);
extern s32 func_088B03E4(char *, s32);
extern s32 func_088B040C(s32, s32, s32);

void func_088B63A4(char *arg0) {
    s32 temp_v0;
    s32 var_s0;

    temp_v0 = func_088AFE78();
    func_088B0240(temp_v0, arg0);
    func_088B00DC(temp_v0, arg0 + 8, *(u16 *)(arg0 + 0x4A));
    func_088B0044(temp_v0, *(s32 *)(arg0 + 0x50));
    func_088AFFE8(temp_v0, *(u8 *)(arg0 + 0x54));
    func_088AFFE8(temp_v0, *(u8 *)(arg0 + 0x56));
    func_088AFFE8(temp_v0, *(u8 *)(arg0 + 0x55));
    func_088B0010(temp_v0, *(u16 *)(arg0 + 0x58));
    var_s0 = 0;
    do {
        func_088AFFE8(temp_v0, *(u8 *)((char *)((arg0 + var_s0)) + 0x5C));
        var_s0 += 1;
    } while (var_s0 < 8);
}

void func_088B6458(char *arg0, s32 arg1) {
    u16 sp1E;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s0;

    temp_v0 = func_088B0318(arg0, arg1);
    func_088B03CC(&sp1E, temp_v0);
    *(u16 *)(arg0 + 0x4A) = sp1E;
    var_a1 = func_088B03CC((unsigned short *) (arg0 + 0x58), func_088B03BC(arg0 + 0x55, func_088B03BC(arg0 + 0x56, func_088B03BC(arg0 + 0x54, func_088B03E4(arg0 + 0x50, func_088B040C((int) (arg0 + 8), 0x42, temp_v0))))));
    var_s0 = 0;
    do {
        temp_v0_2 = func_088B03BC(arg0 + var_s0 + 0x5C, var_a1);
        var_s0 += 1;
        var_a1 = temp_v0_2;
    } while (var_s0 < 8);
}
