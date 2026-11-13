/* unit_08899954: 0x08899954-0x08899B94 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern int func_0880C084(void *, void *, s32);
extern int func_0880C464(void *, s32, s32);
extern char func_0889A290;
extern char func_0889AEB0;
extern char func_0889AEF4;
extern char func_0889AF48;
extern char func_0889AFAC;
extern char func_0889B160;
extern char func_0889B1A4;
extern char func_0889BE7C;
extern char func_0889BEC0;
extern char func_0889BF08;
extern char func_0889BFA0;
extern char func_0889C0D4;
extern char func_0889C144;
extern char func_0889C1AC;
extern char func_0889C214;
extern char func_0889C2F0;
extern char func_0889C48C;
extern char func_0889C4D0;
extern int func_088B0B14(char *);
extern int func_088B0C3C(s32, char *, char *);
extern int func_088B0D58(char *, char *);

void func_08899954(char *arg0, char *arg1, char *arg2, s32 arg3) {
    *(u8 *)(arg0 + 0x12D6) = 0U;
    func_0880C464(arg0 + 0x20, 0, 0xBC);
    if (arg1 != 0) {
        func_0880C084(arg0 + 0x20, arg1, 0x12);
    }
    *(s16 *)(arg0 + 0x32) = 0x12;
    *(u8 *)(arg0 + 0xD6) = (u8) *(u8 *)(arg0 + 0x12D6);
    *(u8 *)(arg0 + 0xD7) = (u8) *(u8 *)(arg0 + 0x12D5);
    *(s16 *)(arg0 + 0xD8) = 0;
    if (arg3 != 0) {
        func_0880C084(arg0 + 0x38, arg2, arg3);
        *(s16 *)(arg0 + 0xD8) = 0xA0;
    }
    *(s8 *)(arg0 + 0x12D4) = 0;
    func_088B0B14(arg0 + 0x20);
    *(s8 *)(arg0 + 0xEE3) = 0;
    func_0880C464(arg0 + 0x57C, 0, 0x320);
    func_088B0C3C(1, &func_0889AEB0, arg0);
    func_088B0C3C(3, &func_0889AEF4, arg0);
    func_088B0C3C(5, &func_0889AF48, arg0);
    func_088B0C3C(6, &func_0889AFAC, arg0);
    func_088B0C3C(8, &func_0889B160, arg0);
    func_088B0C3C(9, &func_0889B1A4, arg0);
    func_088B0C3C(0xA, &func_0889BE7C, arg0);
    func_088B0C3C(0xB, &func_0889BEC0, arg0);
    func_088B0C3C(0xC, &func_0889BF08, arg0);
    func_088B0C3C(0xD, &func_0889BFA0, arg0);
    func_088B0C3C(0xE, &func_0889C0D4, arg0);
    func_088B0C3C(0xF, &func_0889C144, arg0);
    func_088B0C3C(0x10, &func_0889C1AC, arg0);
    func_088B0C3C(0x11, &func_0889C214, arg0);
    func_088B0C3C(0x12, &func_0889C2F0, arg0);
    func_088B0C3C(0x14, &func_0889C48C, arg0);
    func_088B0C3C(0x13, &func_0889C4D0, arg0);
    *(s32 *)(arg0 + 0x12C0) = (s32) (*(s32 *)(arg0 + 0x12C0) | 8);
    func_088B0D58(&func_0889A290, arg0);
    *(s8 *)(arg0 + 0x146C) = 0;
    *(s32 *)(arg0 + 0x12C4) = 0;
}
