/* unit_0887EB20: 0x0887EB20-0x0887EB80 (ULES01213)
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

void func_0887EB20(void) {
    s32 temp_s0;

    temp_s0 = func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28));
    func_0880C084(D_089CC438 + 0x43C8, D_089CC438 + 0x6ADFC, 0x60);
    func_088D893C(temp_s0);
}
