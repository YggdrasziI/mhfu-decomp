/* unit_0886BA50: 0x0886BA50-0x0886BBE4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;
extern u16 D_089AC5B2;
extern char *D_089CBBEC;
extern s32 D_08A62D8C;

extern char *func_0885151C(char *, u16);
extern void func_088307BC(char *, char *);
extern void func_08883988(s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_0886BA50(char *arg0, char *arg1) {
    s32 flag;

    if (*(s8 *)(arg0 + 0x12D) == 0) {
        return;
    }
    switch (*(s8 *)(arg0 + 0x12D)) {
    case 2:
    if (*(s8 *)(arg0 + 0x12E) == 0) {
        flag = 0;
        if (*(s8 *)(arg0 + 0x786) != 0 && *(s8 *)(arg0 + 0x7B2) == 0) {
            flag = 1;
        } else if (*(s8 *)(arg0 + 0x786) != 0 && *(s8 *)(arg0 + 0x7B2) != 0
                   && *(s8 *)(arg0 + 0x781) != *(s8 *)(*(char **)(arg0 + 0x768) + 4)
                   && *(s8 *)(arg0 + 0x7AD) != *(s8 *)(*(char **)(arg0 + 0x794) + 4)) {
            flag = 1;
        }
        if (*(s8 *)(arg0 + 0x12F) > 0) {
            *(s8 *)(arg0 + 0x12F) -= 1;
        }
        if (*(s8 *)(arg0 + 0x12F) <= 0 && flag != 0) {
            *(s8 *)(arg0 + 0x12D) = 0;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5B2));
            func_08883988(D_08A62D8C, 1, 0x77, 0, 0, 0, 0, 0, 0);
        }
    } else if (*(s8 *)(arg0 + 0x12E) == *(u8 *)(arg1 + 0x1E8)) {
        if (--*(s8 *)(arg0 + 0x12F) <= 0) {
            *(s8 *)(arg0 + 0x12D) = 0;
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089AC5B2));
            func_08883988(D_08A62D8C, 1, 0x77, 0, 0, 0, 0, 0, 0);
        }
    }
    break;
    }
}
