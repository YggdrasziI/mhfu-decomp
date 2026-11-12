/* unit_0884D790: 0x0884D790-0x0884D804 (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern void func_0884D754(void *, s16, s8, s32);

void func_0884D790(char *arg0, s16 arg1, s32 arg2) {
    func_0884D754(arg0, arg1, 0, arg2);
    *(s8 *)(arg0 + 0x2C) = 0;
    *(s8 *)(arg0 + 0x2D) = 0;
    *(s8 *)(arg0 + 0x2E) = 0;
}

void func_0884D7C8(char *arg0, s16 arg1, s32 arg2) {
    func_0884D754(arg0, arg1, 0, arg2);
    *(u8 *)(arg0 + 0x2C) = 0xFF;
    *(u8 *)(arg0 + 0x2D) = 0xFF;
    *(u8 *)(arg0 + 0x2E) = 0xFF;
}
