/* unit_088AE894: 0x088AE894-0x088AE988 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern u8 D_09A1FDE0;
extern s32 D_09A1FDE4;
extern u8 D_09A1FDE9;
extern s8 D_09A202B4;
extern s32 D_09A202C8;
extern s32 D_09A202D0;
extern int func_088ADBA4(s32);
extern int func_088AE988(s32);
extern void func_088AEC3C(void);
extern void func_088AF020(void);
extern s32 func_088AFC34(s32, s32, char *);
extern void func_088B6E8C(void);
extern void func_088B7004(void);
extern void func_088B70E8(void);
extern void func_088B72CC(void);
extern void func_088B7580(void);

s32 func_088AE894(void) {
    s32 sp1C;
    s32 temp_v0;

    D_09A202B4 = 0;
    func_088ADBA4(D_09A202D0);
    if ((D_09A202C8 != 0) && (D_09A202D0 != 0)) {
loop_2:
        temp_v0 = func_088AFC34(D_09A202D0, 0x2710, (char *) (&sp1C));
        if (temp_v0 != 0) {
            func_088AE988(temp_v0);
            goto loop_2;
        }
    }
    if ((D_09A1FDE4 == 0) && (D_09A1FDE9 == 0)) {
        func_088AEC3C();
        func_088AF020();
    }
    if (D_09A1FDE0 != 2) {
        if (D_09A1FDE4 != 0) {
            func_088B7580();
        }
        func_088B7004();
        func_088B70E8();
        func_088B72CC();
        func_088B6E8C();
    }
    return 0;
}
