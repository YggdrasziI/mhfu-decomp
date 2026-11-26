/* unit_0884D878: 0x0884D878-0x0884DBA8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884D878: 0x0884D878-0x0884DBA8 (ULES01213) */

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;

extern char D_0899A118[];
extern char D_0899A120[];
extern char D_0899A130[];
extern char D_0899A140[];
extern char D_0899A14C[];
extern char D_0899A160[];
extern void func_0884E678(s32, void *);
extern char *D_08A631A0;

extern void func_088B8548(char *);
extern void func_088B85CC(char *);
extern char *func_0884F86C(char *);
extern void func_0884EC3C(void *, u32);
extern int func_0884EA1C(char *, char *, s32, u32);
extern void func_0884F440(char *);
extern void func_0884DE3C(s32, void *);
extern void func_0884E5B4(s32, void *);

extern s32 sceUmdActivate(s32, const char *);
extern s32 sceUmdGetErrorStat(void);
extern s32 sceUmdGetDriveStat(void);
extern s32 sceKernelDelayThreadCB(u32);
extern s32 sceIoOpen(const char *, s32, s32);
extern s32 sceIoRead(s32, void *, u32);
extern s32 sceIoGetstat(const char *, void *);
extern void sceKernelDcacheInvalidateRange(const void *, u32);
extern void sceKernelDcacheWritebackRange(const void *, u32);
extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);
extern s32 sceKernelCreateEventFlag(const char *, s32, s32, void *);

typedef struct {
    char pad[0x40];
    u32 size;
    char pad2[0x5C - 0x44];
} Stat;

void func_0884D878(char *arg0) {
    char *self;
    Stat st;
    char *g;

    func_088B8548(arg0);
    sceUmdActivate(1, D_0899A118);
    while (1) {
        if (sceUmdGetErrorStat() == 0) break;
        sceKernelDelayThreadCB(10000);
    }
    while (((sceUmdGetDriveStat() & 0x20) != 0) ^ 1) {
        sceKernelDelayThreadCB(10000);
    }
    while (1) {
        if ((*(s32 *)(arg0 + 0x1010) = sceIoOpen(func_0884F86C(arg0), 1, 0)) >= 0) break;
        sceKernelDelayThreadCB(10000);
    }
    sceKernelDcacheInvalidateRange(arg0 + 0x2AC0, 0x6840);
    while (1) {
        if (sceIoRead(*(s32 *)(arg0 + 0x1010), arg0 + 0x2AC0, 0x6808) >= 0) break;
        sceKernelDelayThreadCB(10000);
    }
    sceKernelDcacheWritebackRange(arg0 + 0x2AC0, 0x6840);
    func_0884EC3C(arg0, 0);
    func_0884EA1C(arg0, arg0 + 0x2AC0, 0x6808, 0);
    sceKernelDcacheInvalidateRange(arg0 + 0x1140, 0x1980);
    while (1) {
        if (sceIoRead(*(s32 *)(arg0 + 0x1010), arg0 + 0x1140, 0x1968) >= 0) break;
        sceKernelDelayThreadCB(10000);
    }
    sceKernelDcacheWritebackRange(arg0 + 0x1140, 0x1980);
    func_0884EA1C(arg0, arg0 + 0x1140, 0x1968, 0x6808);
    while (1) {
        if (sceIoGetstat(func_0884F86C(arg0), &st) >= 0) break;
        sceKernelDelayThreadCB(10000);
    }
    *(u32 *)(arg0 + 0x1018) = st.size;
    func_0884F440(arg0);
    *(u8 *)(arg0 + 0x1014) = 3;
    func_088B85CC(arg0);
    *(u8 *)(arg0 + 0x111C) = 0;
    *(s32 *)(arg0 + 0x29344) = sceKernelCreateThread(D_0899A120, func_0884DE3C, 0x30, 0x1000, 0, 0);
    self = arg0;
    sceKernelStartThread(*(s32 *)(arg0 + 0x29344), 4, &self);
    *(s32 *)(arg0 + 0x2FBC0) = sceKernelCreateEventFlag(D_0899A130, 0x200, 0, 0);
    *(s32 *)(arg0 + 0x2FBC4) = sceKernelCreateThread(D_0899A140, func_0884E5B4, 0x31, 0x1000, 0, 0);
    self = arg0;
    sceKernelStartThread(*(s32 *)(arg0 + 0x2FBC4), 4, &self);
    g = D_08A631A0;
    *(s32 *)(g + 0xF7F030) = *(s32 *)(arg0 + 0x2FBC4);
    *(u8 *)(g + 0xF7F034) = 1;
    *(s32 *)(arg0 + 0x2FBE8) = sceKernelCreateEventFlag(D_0899A14C, 0x200, 0, 0);
    *(s32 *)(arg0 + 0x2FBEC) = sceKernelCreateThread(D_0899A160, func_0884E678, 0x13, 0x1000, 0, 0);
    self = arg0;
    sceKernelStartThread(*(s32 *)(arg0 + 0x2FBEC), 4, &self);
    *(u8 *)(arg0 + 0x2FBCC) = 1;
    *(u8 *)(arg0 + 0x2FBDC) = 1;
    *(s32 *)(arg0 + 0x2FBE0) = 0;
    *(s32 *)(arg0 + 0x2FBE4) = 0;
}
