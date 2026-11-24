/* unit_088590B0: 0x088590B0-0x08859174 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088590B0
 *
 * C++: the bool flag test keeps the sltu only when compiled as C++. */

typedef int s32;
typedef unsigned char u8;

extern "C" {

extern char *D_08A62C60;
extern char *D_08A631A0;
extern s32 D_09A1FDDC;
extern s32 D_09A1DAEC;
extern s32 D_09A0B544;
extern s32 D_09A44C60;

extern void func_088597BC(void);
extern void func_08868B6C(s32);
extern void func_088ADF24(s32);
extern void func_088AB1CC(s32);
extern void func_08898980(s32);
extern void func_088C0084(s32);
extern void func_088592A8(char *);
extern void func_08859218(char *);
extern void sceKernelDcacheWritebackAll(void);
extern void func_08859224(char *);
extern void func_08859728(char *);

void func_088590B0(char *arg0) {
    func_088597BC();
    func_08868B6C((s32)D_08A62C60);
    if ((bool)(*(s32 *)(D_08A631A0 + 0xF7A57C) & 1) != 0) {
        func_088ADF24(D_09A1FDDC);
        func_088AB1CC(D_09A1DAEC);
        func_08898980(D_09A0B544);
    }
    func_088C0084(D_09A44C60);
    if (*(u8 *)(arg0 + 0x801A0) == 0) {
        func_088592A8(arg0);
    }
    func_08859218(arg0);
    sceKernelDcacheWritebackAll();
    func_08859224(arg0);
    func_08859728(arg0);
}
}
