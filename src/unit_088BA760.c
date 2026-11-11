/* unit_088BA760: 0x088BA760-0x088BA860 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef int s32;

extern s32 D_09A0B540;
extern int func_0880C464(s32, s32, s32);
extern s32 func_08898694(s32, s32, s32);

void func_088BA760(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    s32 temp_v0;

    *(s8 *)(arg0 + 0x970) = 0;
    *(s8 *)(arg0 + 0x971) = 0;
    temp_s0 = arg1 & 0x80;
    *(s32 *)(arg0 + 0x94C) = 0;
    if (temp_s0 == 0) {
        temp_v0 = func_08898694(D_09A0B540, 0x19, 0x16A100);
        *(s32 *)(arg0 + 0x94C) = temp_v0;
        func_0880C464(temp_v0, 0, 0x16A100);
    }
    if (arg2 != 0) {
        *(s32 *)(arg0 + 0x950) = arg2;
    }
    *(s32 *)(arg0 + 0x10) = 0;
    *(s32 *)(arg0 + 0x14) = 0;
    if (temp_s0 == 0) {
        *(s32 *)(arg0 + 0x10) = func_08898694(D_09A0B540, 0x19, 0x7000);
        *(s32 *)(arg0 + 0x14) = func_08898694(D_09A0B540, 0x19, 0x3E800);
    }
    *(s32 *)(arg0 + 0xC) = 0;
    *(s32 *)(arg0 + 0x990) = arg1;
    if (arg1 & 0x10) {
        *(s8 *)(arg0 + 0x9A3) = 1;
    } else {
        *(s8 *)(arg0 + 0x9A3) = 0;
    }
    *(s32 *)(arg0 + 0x958) = 0;
    *(s32 *)(arg0 + 0x954) = 0;
    *(s32 *)(arg0 + 0x95C) = 0;
    *(s32 *)(arg0 + 0x960) = 0;
}
