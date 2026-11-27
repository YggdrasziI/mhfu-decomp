/* unit_088B9E90: 0x088B9E90-0x088BA0BC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088B9E90: state machine on +0x1C (C++ as its siblings unit_088B9BF8). */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { float v[3]; } T;

extern "C" {

extern s32 __ptmf_test(void *);
extern float D_089B2B70[2];
extern float D_089B2B78;
extern char *D_089CC01C;
extern char *D_089CC434;
extern s32 D_08A631A0;
extern char *D_08A62D8C;
extern char *D_09C1B720;
extern void func_0884D754(void *, s16, s8, s32);
extern int func_08890144(s32, s32, s32);
extern s32 func_088901E0(s32, s32);
extern int func_088901F8(s32, s32, s32);
extern s32 func_08890284(s32, s32, s32);
extern void func_08882A74(char *, s32, s32);
extern s32 func_09C190F0(char *);
extern s32 func_09C19270(char *);

void func_088B9E90(char *arg0, s32 arg1) {
    T t;

    switch (*(s32 *)(arg0 + 0x1C)) {
    case 0:
        func_0884D754(D_089CC01C, 1, 0, 1);
        func_08890144(D_08A631A0, 0x43, 1);
        *(s32 *)(arg0 + 0x1C) += 1;
        break;
    case 1:
        if (func_088901E0(D_08A631A0, arg1) != 0) {
            break;
        }
        if ((s32)((*(s32 *)((char *)D_08A631A0 + 0xF7A57C) & 1) != 0) != 0) {
            *(u8 *)(D_089CC434 + 0x2FBDC) = 0;
        }
        func_088901F8(D_08A631A0, 0x43, 1);
        *(s32 *)(arg0 + 0x1C) += 1;
    case 2:
        if ((func_08890284(D_08A631A0, 0x4B, 2) & 0xFF) == 0) {
            func_08890144(D_08A631A0, 0x4B, 2);
            *(s32 *)(arg0 + 0x1C) += 1;
        } else {
            *(s32 *)(arg0 + 0x1C) = 4;
        }
        break;
    case 3:
        if (func_088901E0(D_08A631A0, arg1) != 0) {
            break;
        }
        func_088901F8(D_08A631A0, 0x4B, 2);
        *(s32 *)(arg0 + 0x1C) += 1;
    case 4:
        if (func_09C190F0(D_09C1B720) == 0) {
            break;
        }
        *(s32 *)(arg0 + 0x1C) += 1;
    case 5:
        if (func_09C19270(D_09C1B720) == 0) {
            break;
        }
        *(s32 *)(arg0 + 0x1C) += 1;
    case 6:
        func_08882A74(D_08A62D8C, 5, 1);
        *(s32 *)(D_09C1B720 + 8) = 0;
        *(s32 *)(arg0 + 0x1C) += 1;
    default:
        *(s32 *)(arg0 + 0x1C) = 0;
        t.v[0] = D_089B2B70[0];
        t.v[1] = D_089B2B70[1];
        t.v[2] = D_089B2B78;
        if (__ptmf_test(&t)) {
            *(T *)(arg0 + 4) = t;
        }
        break;
    }
}

}
