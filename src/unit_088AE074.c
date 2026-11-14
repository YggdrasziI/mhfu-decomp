/* unit_088AE074: 0x088AE074-0x088AE0BC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_09A1FDE4;
extern u8 D_09A1FDE8;

void func_088AE074(char *arg0) {
    if (D_09A1FDE8 != 0) {
        *(u8 *)(arg0 + 0x21) = 1;
        *(u8 *)(arg0 + 0x22) = 0;
        return;
    }
    if (D_09A1FDE4 != 0) {
        *(u8 *)(arg0 + 0x21) = 2;
        *(u8 *)(arg0 + 0x22) = 0;
        *(u16 *)(arg0 + 0x26) = 0x8003;
    }
}
