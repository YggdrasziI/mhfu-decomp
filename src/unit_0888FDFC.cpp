/* unit_0888FDFC: 0x0888FDFC-0x08890020 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct V44 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(s32, s32); } V44;

extern "C" {

extern V44 *D_089CC434;
extern char D_089AD230[];
extern char *D_089CBBE0;
extern char *D_089CBBE4;
extern char *D_089CBFFC;
extern char *D_08A62C40;
extern char *D_08A62C64;
extern char *D_08A631A8;
extern char *D_09A0B540;
extern char *D_09A4F0D0;
extern char *D_09A1FDDC;
extern char *D_09A44C60;
extern char *D_08A8B1E8;

extern s32 sceKernelGetThreadId(void);
extern s32 sceKernelChangeCurrentThreadAttr(s32, s32);
extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);
extern s32 sceKernelDeleteThread(s32);
extern s32 sceUtilityLoadModule(s32);
extern void func_08890718(char *);
extern void func_088905B0(char *);
extern void func_08897BC0(s32);
extern void func_08890430(char *);
extern void func_08890020(void);
extern void func_08811C84(char *);
extern void func_08858FF4(char *);
extern void func_08868F0C(char *);
extern void func_08898590(char *, s32);
extern void func_088DD838(char *);
extern void func_08859174(char *);
extern void func_0884B284(char *);
extern void func_088907D8(char *);
extern void func_08812A08(char *);
extern void func_088ADD3C(char *);
extern s32 func_08859B44(void *, s32, s32);
extern char *func_08897290(s32, s32);
extern char *func_0885A994(char *);
extern void func_088BA2A0(char *);
extern void func_088DD868(char *);

void func_0888FDFC(char *arg0) {
    char **slot;
    char *p;

    *(s32 *)(arg0 + 0xF7F024) = sceKernelGetThreadId();
    *(u8 *)(arg0 + 0xF7F034) = 0;
    *(s32 *)(arg0 + 0xF7A554) = 0;
    func_08890718(arg0);
    *(s32 *)(arg0 + 0xF7A568) = 0;
    sceKernelChangeCurrentThreadAttr(0, 0x4000);
    func_088905B0(arg0);
    func_08897BC0(0);
    func_08890430(arg0);
    *(s32 *)(arg0 + 0xF7A564) = sceKernelCreateThread(D_089AD230, (void *)func_08890020, 0x6F, 0x1000, 0, 0);
    if (sceKernelStartThread(*(s32 *)(arg0 + 0xF7A564), 0, 0) < 0) {
        sceKernelDeleteThread(*(s32 *)(arg0 + 0xF7A564));
    }
    func_08811C84(D_089CBBE0);
    func_08858FF4(D_08A62C40);
    func_08868F0C(D_08A62C64);
    D_089CC434->vfunc_0C();
    func_08898590(D_09A0B540, 0x83C000);
    func_088DD838(D_09A4F0D0);
    func_08859174(D_08A62C40);
    D_089CC434->vfunc_44(0x2A, 2);
    sceUtilityLoadModule(0x100);
    sceUtilityLoadModule(0x101);
    func_0884B284(D_089CBFFC);
    func_088907D8(D_08A631A8);
    func_08812A08(D_089CBBE4);
    func_088ADD3C(D_09A1FDDC);
    slot = (char **)D_08A8B1E8;
    {
        s32 r = func_08859B44(slot + 0x14010 / 4, 0x20, 0x10);
        if (r != 0) {
            p = func_08897290(0x20, r);
            if (p != 0) {
                p = func_0885A994(p);
            }
            *slot = p;
            if (p != 0) {
                p[0x10] = 0;
                *(s32 *)(*slot + 0x14) = 1;
                p = *slot;
                p[0x11] = 2;
                p[0x12] = 0;
            }
        }
    }
    func_088BA2A0(D_09A44C60);
    func_088DD868(D_09A4F0D0);
}

}
