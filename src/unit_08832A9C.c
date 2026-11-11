/* unit_08832A9C: 0x08832A9C-0x08832B98 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_08A62C40;
extern int func_088596C8(s32, char *, s32, u8);
extern char *func_088597FC(s32);
extern int func_0885980C(s32, char *);

void func_08832A9C(char *arg0, s32 arg1) {
    char *temp_s0;

    temp_s0 = func_088597FC(D_08A62C40);
    if (arg1 != 0) {
        *(s32 *)temp_s0 = 0x21000001;
        *(s32 *)(temp_s0 + 4) = 0xDF0000A2;
        *(s32 *)(temp_s0 + 8) = 0xE1FFFFFF;
        *(s32 *)(temp_s0 + 0xC) = 0x10000000;
        *(s32 *)(temp_s0 + 0x10) = 0x08000000;
        func_088596C8(D_08A62C40, temp_s0, 5, *(u8 *)(arg0 + 0x534));
        func_0885980C(D_08A62C40, temp_s0 + 0x14);
        return;
    }
    *(s32 *)temp_s0 = 0x21000001;
    *(s32 *)(temp_s0 + 4) = 0xDF000032;
    *(s32 *)(temp_s0 + 8) = 0x10000000;
    *(s32 *)(temp_s0 + 0xC) = 0x08000000;
    func_088596C8(D_08A62C40, temp_s0, 4, *(u8 *)(arg0 + 0x534));
    func_0885980C(D_08A62C40, temp_s0 + 0x10);
}
