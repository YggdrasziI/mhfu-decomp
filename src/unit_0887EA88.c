/* unit_0887EA88: 0x0887EA88-0x0887EB20 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern int func_0880C084(char *, char *, s32);
extern int func_088D893C(s32);
extern s32 func_088DCEBC(s32, u8);

void func_0887EA88(void) {
    s32 temp_s2;
    char *temp_s0;
    char *temp_s1;

    temp_s2 = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    temp_s1 = D_089CC438 + 0x4A0;
    temp_s0 = D_089CC438 + 0x6ADFC;
    func_0880C084(temp_s1 + 0x3F28, temp_s0, 0x60);
    func_088D893C(temp_s2);
    func_0880C084(temp_s1 + 0x20, temp_s0 + 0x60, 0xC);
    func_0880C084(temp_s1 + 0x2C, temp_s0 + 0x6C, 0x3C);
}
