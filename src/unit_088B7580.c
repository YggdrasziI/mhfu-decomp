/* unit_088B7580: 0x088B7580-0x088B75B8 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern u8 D_09A1FDE9;
extern int func_088B6A80(s32);

void func_088B7580(void) {
    if (D_09A1FDE9 == 0) {
        D_09A1FDE9 = 1;
        func_088B6A80(0x13);
    }
}
