/* unit_088B7A38: 0x088B7A38-0x088B7A5C (ULES01213)
 *
 * Bounds (hypothesis): 2 small functions between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 D_09A2886C;
extern u16 D_09A28BF0;

s32 func_088B7A38(s32 arg0) {
    return D_09A28BF0 != (arg0 & 0xFFFF);
}

void func_088B7A50(s32 arg0) {
    D_09A2886C = arg0;
}
