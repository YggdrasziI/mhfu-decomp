/* unit_0889615C: 0x0889615C-0x08896228 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 *
 * C++: the code only matches when compiled as C++.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

extern "C" {

extern char *D_089CC438;
extern s32 func_0884FA5C(s32, s32);
extern s32 func_088567C8(s32);

s32 func_0889615C(char *arg0) {
    if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 0x100) == 0) {
        return 1;
    }
    if ((func_0884FA5C((s32) D_089CC438, 0) & 0xFF) == 1) {
        return 1;
    }
    *(s8 *)(arg0 + 0x10FD) = 0;
    *(s8 *)(arg0 + 0x10FC) = 0;
    func_088567C8((s32) D_089CC438);
    *(s16 *)(arg0 + 0x1104) = 0;
    *(s8 *)(arg0 + 0x1106) = 8;
    *(s8 *)(arg0 + 0x1107) = 0;
    *(s8 *)(arg0 + 0x1108) = 0;
    *(u8 *)(arg0 + 0x1109) = (u8) ((s32) (*(u8 *)(arg0 + 0x1114) + 7) >> 3);
    *(s8 *)(arg0 + 0x110A) = (s8) (*(u8 *)(arg0 + 0x1114) - ((*(u8 *)(arg0 + 0x1109) - 1) * 8));
    *(s32 *)(arg0 + 0x5E8) = (s32) (*(s32 *)(arg0 + 0x5E8) & ~4);
    return 0;
}

}
