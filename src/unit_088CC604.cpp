/* unit_088CC604: 0x088CC604-0x088CC828 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions after func_088CC568 (NonMatching): a destructor
 * shape and a state machine on +0x8C (the cases of the switch compare in reverse
 * source order). The code after them is still in assembly.
 *
 * C++: the flag test of the state machine is a bool conversion.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { float v[3]; } T;

extern "C" {

extern s32 __ptmf_test(void *);
extern char D_089BAB98;
extern char D_089BAD98;
extern s32 D_09A4F068;
extern void func_08897298(char **);
extern float D_089B5620[2];
extern float D_089B5628;
extern float D_089B562C;
extern char *D_089CC01C;
extern char *D_089CC434;
extern char *D_08A631A0;
extern void func_0884D754(void *, s16, s8, s32);
extern int func_08890144(void *, s32, s32);
extern s32 func_088901E0(void *, s32);
extern int func_088901F8(void *, s32, s32);
extern s32 func_08890284(void *, s32, s32);


char **func_088CC604(char **arg0, s16 arg1) {
    if (arg0 != 0) {
        *arg0 = &D_089BAD98;
        if (((char *) arg0 + 0x1C) != 0) {
            D_09A4F068 = 0;
        }
        if (arg0 != 0) {
            *arg0 = &D_089BAB98;
        }
        if (arg1 > 0) {
            func_08897298(arg0);
        }
    }
    return arg0;
}

void func_088CC678(char *arg0, s32 arg1) {
    T t;

    switch (*(s8 *)(arg0 + 0x8C)) {
    case 0:
        func_0884D754(D_089CC01C, 1, 0, 1);
        func_08890144(D_08A631A0, 0x49, 1);
        *(s8 *)(arg0 + 0x8C) += 1;
        break;
    case 1:
        if (func_088901E0(D_08A631A0, 1) != 0) {
            break;
        }
        if ((bool) (*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
            *(u8 *)(D_089CC434 + 0x2FBDC) = 0;
        }
        func_088901F8(D_08A631A0, 0x49, 1);
        *(s8 *)(arg0 + 0x8C) += 1;
        break;
    case 2:
        if ((func_08890284(D_08A631A0, 0x4C, 2) & 0xFF) == 0) {
            func_08890144(D_08A631A0, 0x4C, 2);
            *(s8 *)(arg0 + 0x8C) += 1;
        } else {
            *(s8 *)(arg0 + 0x8C) = -1;
        }
        break;
    case 3:
        if (func_088901E0(D_08A631A0, arg1) != 0) {
            break;
        }
        func_088901F8(D_08A631A0, 0x4C, 2);
    default:
        *(s8 *)(arg0 + 0x8C) = 0;
        t.v[0] = D_089B5620[1];
        t.v[1] = D_089B5628;
        t.v[2] = D_089B562C;
        if (__ptmf_test(&t)) {
            *(T *)(arg0 + 4) = t;
        }
        break;
    }
}

}
