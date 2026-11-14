/* unit_088B118C: 0x088B118C-0x088B11EC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s8 D_09A1FDE0;
extern u8 D_09A28875;
extern void func_088B7078(s32, s32, s32);

void func_088B118C(char *arg0) {
    s32 temp_v1;

    if (D_09A28875 != 0) {
        *(u8 *)(arg0 + 0x21) = 2;
        *(u8 *)(arg0 + 0x22) = 0;
        *(u16 *)(arg0 + 0x26) = 0x8072;
        return;
    }
    temp_v1 = *(s32 *)(arg0 + 0xC) - 1;
    *(s32 *)(arg0 + 0xC) = temp_v1;
    if (temp_v1 < 0) {
        D_09A1FDE0 = 1;
        func_088B7078((s32) arg0, 0, 0);
    }
}
