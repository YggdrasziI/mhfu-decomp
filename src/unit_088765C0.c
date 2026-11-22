/* unit_088765C0: 0x088765C0-0x08876710 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef short s16;
typedef int s32;
typedef unsigned char u8;

extern char *D_08A62CB4;
extern char *D_08A62C7C;
extern char *D_089CC438;
extern s32 D_09A4F0C4;
extern char *D_08A631A0;

extern s32 func_0886A30C(char *, s32);
extern char *func_088DCEBC(s32, u8);
extern s32 func_088D6A54(char *, u8);
extern u8 func_0887CA08(char *);

void func_088765C0(char *arg0) {
    *(s16 *)(arg0 + 0xA4) = 0;
    *(s16 *)(arg0 + 0xA6) = 0;
    *(s16 *)(arg0 + 0xAA) = 0xE10;
    *(s32 *)(D_08A62CB4 + 0x14) = 0;
    *(s16 *)(arg0 + 0xA8) = 10;
    if (func_0886A30C(D_08A62C7C, 1) == 1) {
        if (func_088D6A54(func_088DCEBC(D_09A4F0C4, *(u8 *)(D_089CC438 + 0x28)), 0x31) == 0) {
            *(s32 *)(D_08A62CB4 + 0x14) = *(s32 *)(D_08A62C7C + 0x14);
        } else {
            *(s32 *)(D_08A62CB4 + 0x14) = *(s32 *)(D_08A62C7C + 0x14) * 2;
        }
        if ((s32)((*(s32 *)(D_08A631A0 + 0xF80000 - 0x5A84) & 1) != 0) == 1) {
            if (func_0887CA08(arg0) == 1) {
                *(s32 *)(D_08A62CB4 + 0x14) += *(s32 *)(*(char **)(D_08A62C7C + 0x68) + 4) * 2;
            }
        } else {
            *(s32 *)(D_08A62CB4 + 0x14) += *(s32 *)(*(char **)(D_08A62C7C + 0x68) + 4) * 2;
        }
    }
}
