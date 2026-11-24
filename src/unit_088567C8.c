/* unit_088567C8: 0x088567C8-0x0885683C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

extern char *D_08A631A0;
extern s32 D_08A62D8C;
extern void func_08882F10(s32 arg0, s32 arg1);
extern void func_08885798(s32 arg0, s32 arg1, s32 arg2);

void func_088567C8(char *arg0) {
    if ((s32) ((*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) == 1) {
        *(u8 *)(arg0 + 0x6AF1A) = 0;
        return;
    }
    *(u8 *)(arg0 + 0x6AF1A) = 1;
    func_08882F10(D_08A62D8C, 1);
    func_08885798(D_08A62D8C, 4, 0);
}
