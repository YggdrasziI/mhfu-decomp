/* unit_0884F2E0: 0x0884F2E0-0x0884F3FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884F2E0: 0x0884F2E0-0x0884F3FC (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    s32 size;
    s32 mpidtext;
    s32 mpiddata;
    u32 flags;
    u8 position;
    u8 access;
    u8 creserved[2];
} LMOption;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); } V18;

extern char D_0899A19C;

extern "C" {

extern void memset(void *, s32, s32);
extern int func_0880E8F0(char *, char *, ...);
extern s32 sceIoOpen(char *, s32, s32);
extern s32 sceIoClose(s32);
extern s32 sceKernelDelayThreadCB(u32);
extern s32 sceKernelLoadModuleByID(s32, s32, LMOption *);
extern s32 sceKernelStartModule(s32, s32, void *, s32 *, void *);

s32 func_0884F2E0(char *p, u16 idx, s32 part) {
    LMOption opt;
    s32 status;
    s32 fd;
    s32 mid;
    char *name;

    memset(&opt, 0, 0x14);
    opt.size = 0x14;
    opt.access = 1;
    opt.mpidtext = part;
    opt.mpiddata = part;
    opt.position = 0;
    name = *(char **)((char *)(idx * 4) + (s32)p + 0x2AC0);
    func_0880E8F0(p + 0x101C, &D_0899A19C, *(char **)(p + 0x1018) + (s32)name,
                  ((V18 *)p)->vfunc_18(idx));
    while (1) {
        fd = sceIoOpen(p + 0x101C, 1, 0);
        if (fd >= 0) break;
        sceKernelDelayThreadCB(10000);
    }
    while (1) {
        mid = sceKernelLoadModuleByID(fd, 0, &opt);
        if (mid >= 0) break;
        sceKernelDelayThreadCB(10000);
    }
    sceKernelStartModule(mid, 0, 0, &status, 0);
    sceIoClose(fd);
    return mid;
}
}
