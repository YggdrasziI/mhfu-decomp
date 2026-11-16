/* unit_088B996C: 0x088B996C-0x088B9B0C (ULES01213)
 *
 * Bounds (hypothesis): 1 function (state machine on +0x34; the cases of the switch
 * compare in reverse source order) between code already in units.
 *
 * C++: the flag test of case 0 is a bool conversion. The float constants are
 * declared as float arrays: as char symbols cast to float, the two loads come in
 * the other order.
 */

typedef signed char s8;
typedef short s16;
typedef int s32;
typedef struct { float v[3]; } T;
typedef struct { float a, b; } F2;

extern "C" {

extern s32 __ptmf_test(void *);
extern float D_089B2B40[2];
extern float D_089B2B48;
extern char *D_089CC01C;
extern char *D_089CC438;
extern s32 D_08A631A0;
extern void func_0884D754(void *, s16, s8, s32);
extern int func_08890144(s32, s32, s32);
extern s32 func_088901E0(s32, s32);
extern int func_088901F8(s32, s32, s32);
extern s32 func_08890284(s32, s32, s32);

void func_088B996C(char *arg0, s32 arg1) {
    T t;

    switch (*(s32 *)(arg0 + 0x34)) {
    case 0:
        if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 8) != 0) {
            func_0884D754(D_089CC01C, 1, 0, 1);
        }
        func_08890144(D_08A631A0, 0x47, 1);
        *(s32 *)(arg0 + 0x34) += 1;
        break;
    case 1:
        if (func_088901E0(D_08A631A0, 1) != 0) {
            break;
        }
        func_088901F8(D_08A631A0, 0x47, 1);
        *(s32 *)(arg0 + 0x34) += 1;
    case 2:
        if ((func_08890284(D_08A631A0, 0x4C, 2) & 0xFF) == 0) {
            func_08890144(D_08A631A0, 0x4C, 2);
            *(s32 *)(arg0 + 0x34) += 1;
        } else {
            *(s32 *)(arg0 + 0x34) = -1;
        }
        break;
    case 3:
        if (func_088901E0(D_08A631A0, arg1) != 0) {
            break;
        }
        func_088901F8(D_08A631A0, 0x4C, 2);
    default:
        *(s32 *)(arg0 + 0x34) = 0;
        t.v[0] = D_089B2B40[0];
        t.v[1] = D_089B2B40[1];
        t.v[2] = D_089B2B48;
        if (__ptmf_test(&t)) {
            *(T *)(arg0 + 4) = t;
        }
        break;
    }
}

}
