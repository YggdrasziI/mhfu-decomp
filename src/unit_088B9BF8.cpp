/* unit_088B9BF8: 0x088B9BF8-0x088B9DA8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (state machine on +0x1C; the cases of the switch
 * compare in reverse source order) between code already in units.
 *
 * C++ as its sibling unit_088B996C. The float constants are
 * declared as float arrays: as char symbols cast to float, the two loads come in
 * the other order.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { float v[3]; } T;

extern "C" {

extern s32 __ptmf_test(void *);
extern float D_089B2B58[2];
extern float D_089B2B60;
extern char *D_089CC01C;
extern char *D_089CC438;
extern s32 D_08A631A0;
extern void func_0884D754(void *, s16, s8, s32);
extern int func_08890144(s32, s32, s32);
extern s32 func_088901E0(s32, s32);
extern int func_088901F8(s32, s32, s32);
extern s32 func_08890284(s32, s32, s32);

void func_088B9BF8(char *arg0, s32 arg1) {
    T t;

    switch (*(s32 *)(arg0 + 0x1C)) {
    case 0:
        *(u8 *)(D_089CC438 + 0x494) = 1;
        func_0884D754(D_089CC01C, 1, 0, 1);
        if ((func_08890284(D_08A631A0, 0x3F, 1) & 0xFF) == 0) {
            func_08890144(D_08A631A0, 0x3F, 1);
            *(s32 *)(arg0 + 0x1C) += 1;
        } else {
            *(s32 *)(arg0 + 0x1C) = 2;
        }
        break;
    case 1:
        if (func_088901E0(D_08A631A0, 1) != 0) {
            break;
        }
        func_088901F8(D_08A631A0, 0x3F, 1);
        *(s32 *)(arg0 + 0x1C) += 1;
    case 2:
        if ((func_08890284(D_08A631A0, 0x4B, 2) & 0xFF) == 0) {
            func_08890144(D_08A631A0, 0x4B, 2);
            *(s32 *)(arg0 + 0x1C) += 1;
        } else {
            *(s32 *)(arg0 + 0x1C) = -1;
        }
        break;
    case 3:
        if (func_088901E0(D_08A631A0, arg1) != 0) {
            break;
        }
        func_088901F8(D_08A631A0, 0x4B, 2);
    default:
        *(s32 *)(arg0 + 0x1C) = 0;
        t.v[0] = D_089B2B58[0];
        t.v[1] = D_089B2B58[1];
        t.v[2] = D_089B2B60;
        if (__ptmf_test(&t)) {
            *(T *)(arg0 + 4) = t;
        }
        break;
    }
}

}
