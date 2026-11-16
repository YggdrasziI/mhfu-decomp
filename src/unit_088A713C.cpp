/* unit_088A713C: 0x088A713C-0x088A72F0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function (state machine on +0x1C; the cases of the
 * switch compare in reverse source order) at the end of a run of functions still
 * in assembly.
 *
 * C++: the flag test of case 1 is a bool conversion.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { float v[3]; } T;

extern "C" {

extern s32 __ptmf_test(void *);
extern float D_089B2818[2];
extern float D_089B2820;
extern float D_089B2824;
extern char *D_089CC01C;
extern char *D_089CC434;
extern char *D_08A631A0;
extern void func_0884D754(void *, s16, s8, s32);
extern int func_08890144(void *, s32, s32);
extern s32 func_088901E0(void *, s32);
extern int func_088901F8(void *, s32, s32);
extern s32 func_08890284(void *, s32, s32);

void func_088A713C(char *arg0, s32 arg1) {
    T t;

    switch (*(s32 *)(arg0 + 0x1C)) {
    case 0:
        func_0884D754(D_089CC01C, 1, 0, 1);
        func_08890144(D_08A631A0, 0x46, 1);
        *(s32 *)(arg0 + 0x1C) += 1;
        break;
    case 1:
        if (func_088901E0(D_08A631A0, 1) != 0) {
            break;
        }
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
            *(u8 *)(D_089CC434 + 0x2FBDC) = 0;
        }
        func_088901F8(D_08A631A0, 0x46, 1);
        *(s32 *)(arg0 + 0x1C) += 1;

    case 2:
        if ((func_08890284(D_08A631A0, 0x4C, 2) & 0xFF) == 0) {
            func_08890144(D_08A631A0, 0x4C, 2);
            *(s32 *)(arg0 + 0x1C) += 1;
        } else {
            *(s32 *)(arg0 + 0x1C) = -1;
        }
        break;
    case 3:
        if (func_088901E0(D_08A631A0, arg1) != 0) {
            break;
        }
        func_088901F8(D_08A631A0, 0x4C, 2);
    default:
        *(s32 *)(arg0 + 0x1C) = 0;
        t.v[0] = D_089B2818[1];
        t.v[1] = D_089B2820;
        t.v[2] = D_089B2824;
        if (__ptmf_test(&t)) {
            *(T *)(arg0 + 4) = t;
        }
        break;
    }
}

}
