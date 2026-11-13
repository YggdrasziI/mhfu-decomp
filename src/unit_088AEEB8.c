/* unit_088AEEB8: 0x088AEEB8-0x088AEF64 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char D_09A202B8;
extern u8 D_09A20608;
extern u8 D_09A20609;
extern int func_0880C084(void *, void *, s32);
extern int func_0880C464(void *, s32, s32);

void func_088AEEB8(char *arg0, s32 arg1) {
    s32 temp_a0;

    func_0880C464(arg0 + 0x18, 0, 0x300);
    func_0880C084(arg0 + 0xE, &D_09A202B8, 6);
    temp_a0 = arg1 & 0xFFFF;
    *(u8 *)(arg0 + 6) = (s8) ((s32) (temp_a0 & 0xFF00) >> 8);
    *(u8 *)(arg0 + 7) = temp_a0;
    *(u8 *)(arg0 + 5) = 2;
    *(u16 *)arg0 = 0;
    *(u16 *)(arg0 + 2) = 0;
    *(u8 *)(arg0 + 4) = 1;
    *(u8 *)(arg0 + 0x14) = 0;
    *(u8 *)(arg0 + 0xA) = (u8) D_09A20608;
    *(u8 *)(arg0 + 0xB) = (u8) D_09A20609;
    *(u8 *)(arg0 + 0xC) = 0;
    *(u8 *)(arg0 + 0xD) = 0;
    *(u8 *)(arg0 + 0x16) = 0xFF;
    *(u8 *)(arg0 + 0x17) = 0xFF;
}
