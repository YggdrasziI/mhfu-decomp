/* unit_088901F8: 0x088901F8-0x08890284 (ULES01213) */

typedef int s32;
typedef unsigned short u16;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); } V18;

extern "C" {

extern void *D_089CBA70[];
extern V18 *D_089CC434;
extern void func_0890DD9C(void *, s32);
extern s32 sceKernelIcacheInvalidateAll(void);

void func_088901F8(char *arg0, u16 arg1, s32 arg2) {
    void *p = D_089CBA70[arg2];

    func_0890DD9C(p, D_089CC434->vfunc_18(arg1));
    ((u16 *)(arg0 + 0xF7A580))[arg2] = arg1;
    sceKernelIcacheInvalidateAll();
}

}
