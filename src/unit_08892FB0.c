/* unit_08892FB0: 0x08892FB0-0x088930A0 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef int s32;

extern s32 D_08A62C40;
extern int func_088596C8(s32, char *, s32, s32);
extern char *func_088597FC(s32);
extern int func_0885980C(s32, char *);
extern int func_088930A8(s32);
extern int func_08893390(s32);
extern int func_08894988(s32);

void func_08892FB0(s32 arg0) {
    s32 temp_s0;
    char *temp_v0;

    temp_s0 = func_08894988(arg0);
    temp_v0 = func_088597FC(D_08A62C40);
    *(s32 *)temp_v0 = 0x23000000;
    *(s32 *)(temp_v0 + 4) = 0xDE000000;
    *(s32 *)(temp_v0 + 8) = 0x21000001;
    *(s32 *)(temp_v0 + 0xC) = 0xDF000032;
    *(s32 *)(temp_v0 + 0x10) = 0x22000001;
    *(s32 *)(temp_v0 + 0x14) = 0xDBFF0003;
    *(s32 *)(temp_v0 + 0x18) = 0xC9000100;
    *(s32 *)(temp_v0 + 0x1C) = 0xC0000000;
    *(s32 *)(temp_v0 + 0x20) = 0xC7000000;
    *(s32 *)(temp_v0 + 0x24) = 0xC6000101;
    *(s32 *)(temp_v0 + 0x28) = 0x10000000;
    *(s32 *)(temp_v0 + 0x2C) = 0x08000000;
    func_088596C8(D_08A62C40, temp_v0, 0xC, temp_s0);
    func_0885980C(D_08A62C40, temp_v0 + 0x30);
    func_088930A8(arg0);
    func_08893390(arg0);
}
