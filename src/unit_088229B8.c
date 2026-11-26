/* unit_088229B8: 0x088229B8-0x08822BF4 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Rec Rec;

extern s32 D_08A62C54;
extern char *D_08A631A8;
extern char *D_089CC438;
extern u16 D_089AC8F0;
extern u16 D_089AC98C;
extern u16 D_089AC98E;
extern u16 D_089AC990;
extern u8 D_0899D198[][24];
extern s8 D_0893AA88[];

extern s8 func_0885EB34(s32 arg0, Rec *arg1);
extern s32 func_0885E748(s32 arg0, Rec *arg1);
extern void func_0885EA08(s32 arg0, Rec *arg1, u16 *out);
extern void func_08890E38(char *, s8);
extern char *func_0885151C(char *, u16);
extern s32 func_08890E48(char *, char *);
extern void func_08891474(char *, s16, s16, char *, ...);

void func_088229B8(s32 arg0, Rec *arg1, u16 x, u16 y, u8 arg4) {
    s32 n;
    s32 cnt;
    s32 i;
    u16 ids[3];

    n = (u8)func_0885EB34(D_08A62C54, arg1);
    cnt = n - func_0885E748(D_08A62C54, arg1);
    func_0885EA08(D_08A62C54, arg1, ids);
    func_08890E38(D_08A631A8, 9);
    x += (u16)((func_08890E48(D_08A631A8, func_0885151C(D_089CC438, D_089AC8F0)) + 1) * 7);
    for (i = 0; i < cnt; i++) {
        if (arg4 == 0) {
            func_08890E38(D_08A631A8, D_0893AA88[D_0899D198[ids[i]][6]]);
        }
        func_08891474(D_08A631A8, (s16)x, (s16)y, func_0885151C(D_089CC438, D_089AC98C));
        x += 14;
    }
    func_08890E38(D_08A631A8, 9);
    for (; i < n; i++) {
        func_08891474(D_08A631A8, (s16)x, (s16)y, func_0885151C(D_089CC438, D_089AC98E));
        x += 14;
    }
    for (; i < 3; i++) {
        func_08891474(D_08A631A8, (s16)x, (s16)y, func_0885151C(D_089CC438, D_089AC990));
        x += 14;
    }
}
