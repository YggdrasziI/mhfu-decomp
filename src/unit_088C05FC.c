/* unit_088C05FC: 0x088C05FC-0x088C0940 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (unit_088C0594 and unit_088C0940).
 *
 * Optimized for speed. The local table ids is copied from its initializer
 * (0x089B4E28) through FPU registers; D_089B4E10 (0x089B4E10-0x089B4E28) is
 * only used here. Both stay in the data piece while the function does not match.
 *
 * NonMatching: func_088C05FC 93.5 %. Only the store of the ninth argument
 * (0 at 0(sp)) is scheduled differently: the original issues it after the
 * fifth argument's loads, ours before them. Tried: parameter types of
 * func_08831338, the fifth argument in a temporary, an inline wrapper with
 * other argument orders, C and C++ (array declared after the first call).
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 x;
    u16 y;
    u16 step;
    u16 tx;
    u16 ty;
    u16 dy;
} Layout;

extern char *D_089CBBEC;
extern char *D_089CC438;
extern char *D_08A631A8;
extern char *D_08A62C54;
Layout D_089B4E10[2] = {
    {0x118, 0x52, 0x14, 0x130, 0x54, 0x14},
    {0x114, 0x44, 0x1A, 0x130, 0x4A, 0x1A},
};
extern u16 D_089AC8E0;
extern u16 D_089AC8E2;

extern void func_08831338(char *, s16, s32, u16, u16, s32, s32, s32, s32);
extern char *func_0885151C(char *, u16);
extern char *func_0885C968(char *, u8, u16);
extern void func_088920A8(char *, s16, s16, char *, ...);
extern char *func_08851598(char *, u16);
extern char *func_088515C4(char *, u16);
extern char *func_088515F0(char *, u16);
extern char *func_0885161C(char *, u16);
extern char *func_08851648(char *, u16);

void func_088C05FC(char *arg0, char *arg1, s32 arg2) {
    s32 i;
    s32 y;

    func_08831338(D_089CBBEC, *(u8 *)(arg1 + 0x21), *(s16 *)(arg1 + 0x22), D_089B4E10[arg2].x, D_089B4E10[arg2].y, 0x12, 0x12, 0xFF, 0);
    {
        s32 ids[5] = {1, 2, 3, 4, 0};
        for (i = 0; i < 5; i++) {
            func_08831338(D_089CBBEC, ids[i], *(s16 *)(arg1 + ids[i] * 12 + 0x2E), D_089B4E10[arg2].x, D_089B4E10[arg2].y + (i + 1) * D_089B4E10[arg2].step, 0x12, 0x12, 0xFF, 0);
        }
    }
    func_088920A8(D_08A631A8, D_089B4E10[arg2].tx, D_089B4E10[arg2].ty, func_0885151C(D_089CC438, D_089AC8E0), func_0885C968(D_08A62C54, *(u8 *)(arg1 + 0x21), *(u16 *)(arg1 + 0x22)));
    y = D_089B4E10[arg2].ty + D_089B4E10[arg2].dy;
    func_088920A8(D_08A631A8, D_089B4E10[arg2].tx, y, func_0885151C(D_089CC438, D_089AC8E2), func_08851598(D_089CC438, *(u16 *)(arg1 + 0x3A)));
    y += D_089B4E10[arg2].dy;
    func_088920A8(D_08A631A8, D_089B4E10[arg2].tx, y, func_0885151C(D_089CC438, D_089AC8E2), func_088515C4(D_089CC438, *(u16 *)(arg1 + 0x46)));
    y += D_089B4E10[arg2].dy;
    func_088920A8(D_08A631A8, D_089B4E10[arg2].tx, y, func_0885151C(D_089CC438, D_089AC8E2), func_088515F0(D_089CC438, *(u16 *)(arg1 + 0x52)));
    y += D_089B4E10[arg2].dy;
    func_088920A8(D_08A631A8, D_089B4E10[arg2].tx, y, func_0885151C(D_089CC438, D_089AC8E2), func_0885161C(D_089CC438, *(u16 *)(arg1 + 0x5E)));
    y += D_089B4E10[arg2].dy;
    func_088920A8(D_08A631A8, D_089B4E10[arg2].tx, y, func_0885151C(D_089CC438, D_089AC8E2), func_08851648(D_089CC438, *(u16 *)(arg1 + 0x2E)));
}
