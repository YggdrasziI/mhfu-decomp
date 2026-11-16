/* unit_0887F54C: 0x0887F54C-0x0887F794 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (state machine on +0x1C, same shape as
 * unit_088B9BF8; the cases of the switch compare in reverse source order) between
 * code already in units.
 *
 * C++: the flag test is a bool conversion.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { float v[3]; } T;

extern "C" {

extern s32 __ptmf_test(void *);
extern float D_089A8A18[2];
extern float D_089A8A20;
extern float D_089A8A24;
extern float D_089A8A28[2];
extern float D_089A8A30;
extern char *D_089CC01C;
extern char *D_089CC438;
extern char *D_09A44C60;
extern char *D_09C1B720;
extern char *D_08A631A0;
extern void func_0884D754(void *, s16, s8, s32);
extern int func_08890144(void *, s32, s32);
extern s32 func_088901E0(void *, s32);
extern int func_088901F8(void *, s32, s32);
extern s32 func_08890284(void *, s32, s32);

void func_0887F54C(char *arg0, s32 arg1) {
    T t1;
    T t2;

    switch (*(s32 *)(arg0 + 0x1C)) {
    case 0:
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
        if (*(u8 *)(D_089CC438 + 0x494) != 0) {
            if (*(u8 *)(D_09A44C60 + 0x9A2) == 0) {
                *(s32 *)(D_089CC438 + 0x498) = 0;
            } else {
                *(s32 *)(D_089CC438 + 0x498) = 1;
            }
        }
        *(u8 *)(D_089CC438 + 0x494) = 0;
        *(s32 *)(arg0 + 0x1C) = 0;
        if ((bool) *(u8 *)D_09C1B720 != 0) {
            t1.v[0] = D_089A8A18[1];
            t1.v[1] = D_089A8A20;
            t1.v[2] = D_089A8A24;
            if (__ptmf_test(&t1)) {
                *(T *)(arg0 + 4) = t1;
            }
        } else {
            t2.v[0] = D_089A8A28[0];
            t2.v[1] = D_089A8A28[1];
            t2.v[2] = D_089A8A30;
            if (__ptmf_test(&t2)) {
                *(T *)(arg0 + 4) = t2;
            }
        }
        break;
    }
}

}
