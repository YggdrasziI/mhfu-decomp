/* unit_0887A838: 0x0887A838-0x0887A950 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *D_089CC438;
extern char *D_08A62C7C;

extern s32 func_0887E9AC(s32, s32, s32);
extern void func_088585E8(char *, char *, s32, s32, s32);

void func_0887A838(char *arg0) {
    *(s16 *)(arg0 + 0xA4) = 0;
    *(s16 *)(arg0 + 0xA6) = 0;
    *(s16 *)(arg0 + 0xAA) = 0xE10;
    *(s16 *)(arg0 + 0xA8) = 10;
    if (*(u8 *)(D_089CC438 + 0x28) == 0) {
        *(s32 *)(arg0 + 0xB0) = *(s32 *)(D_08A62C7C + 0x5B0);
        *(s32 *)(arg0 + 0xB4) = *(s32 *)(D_08A62C7C + 0x5B4);
    } else {
        *(s32 *)(arg0 + 0xB0) = *(s32 *)(D_08A62C7C + 0x5B4);
        *(s32 *)(arg0 + 0xB4) = *(s32 *)(D_08A62C7C + 0x5B0);
    }
    *(s32 *)(arg0 + 0xBC) = 0;
    *(s32 *)(arg0 + 0xB8) = 0;
    *(s32 *)(arg0 + 0x120) = *(s32 *)(arg0 + 0xB0) + *(s32 *)(arg0 + 0xB4);
    *(s32 *)(arg0 + 0x14) = func_0887E9AC((s32)arg0, *(s32 *)(arg0 + 0x120), 0);
    if (*(u32 *)(arg0 + 0x120) > ((u32 *)(D_089CC438 + 0x6397C))[*(u16 *)(D_089CC438 + 0x6AF12)]) {
        *(s16 *)(arg0 + 0xAC) = 1;
        func_088585E8(D_089CC438, D_08A62C7C + 0x684, 10, *(s32 *)(arg0 + 0x120), 0);
    } else {
        *(s16 *)(arg0 + 0xAC) = 0;
    }
}
