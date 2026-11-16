/* unit_0885B160: 0x0885B160-0x0885B21C (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;

extern s32 D_089CC438;
extern s32 func_088568AC(s32, s32);
extern s32 func_0885BD0C(s32, s32);
extern s32 func_088D6A1C(s32, s32);

s32 func_0885B160(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    if ((arg2 != 0) && !(*(u8 *)(arg2 + 7) & 1)) {
        return 1;
    }
    if ((func_088D6A1C(arg1, 0xA0) & 0xFF) == 1) {
        return 1;
    }
    if (func_088568AC(D_089CC438, 6) != 0) {
        return 1;
    }
    if (((arg3 & 0xFF) == 1) && ((func_0885BD0C(arg0, 6) & 0xFFFF) != 0xFFFF)) {
        return 1;
    }
    return 0;
}
