/* unit_0884DE3C: 0x0884DE3C-0x0884E478 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 *
 * C++: virtual call.
 */

/* func_0884DE3C */

typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 f0;
    u16 f2;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 *f14;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 f1B;
    u8 f1C;
    u8 pad[3];
} Ent;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); } V18;

extern "C" {

extern char *D_089CC438;
extern char D_0899A174[];
extern char D_08979804[];

extern int sceKernelSleepThread(void);
extern int sceKernelWaitSema(s32, s32, s32);
extern int func_0880E8F0(char *, char *, ...);
extern s32 sceIoOpen(char *, s32, s32);
extern s32 sceKernelDelayThreadCB(u32);
extern void func_0884F5F4(char *, s32);
extern s32 sceIoLseek(s32, s64, s32);
extern s32 sceIoClose(s32);
extern s32 func_0884E72C(char *, s32, Ent *);
extern s32 func_0884E858(char *, u32, s32);
extern s32 func_0884E7FC(char *, Ent *);
extern int sceKernelClearEventFlag(s32, s32);
extern int sceKernelSetEventFlag(s32, s32);
extern int sceKernelWaitEventFlag(s32, s32, s32, s32, s32);
extern void func_0884E788(char *, Ent *);
extern s32 func_0880BFF0(void *, void *, s32);
extern void func_0884E478(char *, Ent *);
extern s32 sceKernelSuspendDispatchThread(void);
extern void func_088B85F8(char *);
extern s32 sceKernelResumeDispatchThread(s32);
extern int sceKernelSignalSema(s32, s32);
extern s32 sceUmdGetDriveStat(void);


void func_0884DE3C(s32 argc, void *argp) {
    char *s;
    s32 fd;
    Ent *ent;
    s32 r;
    s32 i;
    s32 x;
    s32 pos;
    char buf[0x40];

    s = *(char **)argp;
    for (;;) {
        while ((ent = (Ent *)(s + *(s32 *)(s + 0x1004) * 32 + 4))->f0 == 0) {
            sceKernelSleepThread();
        }
        switch (*(s32 *)(s + 0x100C)) {
        case 0:
            sceKernelWaitSema(*(s32 *)(s + 0x2931C), 1, 0);
            if (*(s8 *)(D_089CC438 + 0x6ADDE) == 0) {
                *(s32 *)(s + 0x100C) = 7;
            } else {
                *(s32 *)(s + 0x100C) = 1;
            }
            continue;
        case 1:
            x = *(u16 *)(s + ent->f2 * 4 + 0x29348);
            if (x == 0xFFFF) {
                *(s32 *)(s + 0x100C) = 7;
                continue;
            }
            func_0880E8F0(buf, D_0899A174, x);
            i = 30;
            do {
                fd = sceIoOpen(buf, 1, 0);
                if (fd >= 0) {
                    break;
                }
                sceKernelDelayThreadCB(100000);
            } while (--i >= 0);
            if (fd < 0) {
                *(s32 *)(s + 0x100C) = 7;
                func_0884F5F4(s, fd);
                continue;
            }
            r = sceIoLseek(fd, ent->fC + (*(u16 *)(s + ent->f2 * 4 + 0x2934A) << 11), 0);
            if (r < 0) {
                sceIoClose(fd);
                *(s32 *)(s + 0x100C) = 7;
                func_0884F5F4(s, r);
                continue;
            }
            r = func_0884E72C(s, fd, ent);
            if (r != ent->f8) {
                goto fail;
            }
            if (r == ent->f8) {
                *(Ent **)(s + 0x2FBC8) = ent;
                if (func_0884E858(s, ent->f4 + ent->fC, ent->f8)) {
                    if (func_0884E7FC(s, ent)) {
                        sceKernelClearEventFlag(*(s32 *)(s + 0x2FBE8), -0x11);
                        sceKernelSetEventFlag(*(s32 *)(s + 0x2FBE8), 1);
                        sceKernelWaitEventFlag(*(s32 *)(s + 0x2FBE8), 0x10, 0, 0, 0);
                    }
                } else {
                    func_0884E788(s, ent);
                }
                if (func_0884E7FC(s, ent)) {
                    sceKernelClearEventFlag(*(s32 *)(s + 0x2FBC0), -0x11);
                    sceKernelSetEventFlag(*(s32 *)(s + 0x2FBC0), 1);
                    sceKernelWaitEventFlag(*(s32 *)(s + 0x2FBC0), 0x10, 0, 0, 0);
                    if (ent->f1C != 0 && ent->f1A != 0 &&
                        func_0880BFF0(s + 0x2FB4C, D_08979804 + ent->f2 * 20, 20) != 0) {
                        sceIoClose(fd);
                        *(s32 *)(s + 0x100C) = 7;
                        func_0884F5F4(s, r);
                        func_0884E478(s, ent);
                        continue;
                    }
                }
                if (func_0884E7FC(s, ent)) {
                    x = sceKernelSuspendDispatchThread();
                    func_088B85F8(s);
                    sceKernelResumeDispatchThread(x);
                    sceKernelSignalSema(*(s32 *)(s + 0x2931C), 1);
                    sceIoClose(fd);
                    continue;
                }
            }
        fail:
            *(s32 *)(s + 0x100C) = 7;
            func_0884F5F4(s, r);
            sceIoClose(fd);
            continue;
        case 7:
            pos = *(s32 *)(s + ent->f2 * 4 + 0x2AC0) << 11;
            if (*(s32 *)(s + 0x29340) != pos) {
                if (sceIoLseek(*(s32 *)(s + 0x1010), ent->fC + pos, 0) >= 0) {
                    *(s32 *)(s + 0x29340) = ent->fC + (*(s32 *)(s + ent->f2 * 4 + 0x2AC0) << 11);
                } else {
                    sceKernelDelayThreadCB(10000);
                    continue;
                }
            }
            *(s32 *)(s + 0x100C) = 10;
        case 10:
            if (!(sceUmdGetDriveStat() & 0x20)) {
                sceKernelDelayThreadCB(10000);
                continue;
            }
            *(s32 *)(s + 0x100C) = 8;
        case 8:
            r = func_0884E72C(s, *(s32 *)(s + 0x1010), ent);
            x = ent->f8;
            if (r == x) {
                if (x < 0) {
                    x = ((V18 *)s)->vfunc_18(ent->f2);
                }
                if (r == x) {
                    *(Ent **)(s + 0x2FBC8) = ent;
                    *(s32 *)(s + 0x29340) += x;
                    if (func_0884E858(s, ent->f4 + ent->fC, ent->f8)) {
                        sceKernelClearEventFlag(*(s32 *)(s + 0x2FBE8), -0x11);
                        sceKernelSetEventFlag(*(s32 *)(s + 0x2FBE8), 1);
                        sceKernelWaitEventFlag(*(s32 *)(s + 0x2FBE8), 0x10, 0, 0, 0);
                    } else {
                        func_0884E788(s, ent);
                    }
                    if (func_0884E7FC(s, ent)) {
                        sceKernelClearEventFlag(*(s32 *)(s + 0x2FBC0), -0x11);
                        sceKernelSetEventFlag(*(s32 *)(s + 0x2FBC0), 1);
                        sceKernelWaitEventFlag(*(s32 *)(s + 0x2FBC0), 0x10, 0, 0, 0);
                    }
                    if (!func_0884E7FC(s, ent) && ent->f14 != 0) {
                        *ent->f14 = 1;
                    }
                    x = sceKernelSuspendDispatchThread();
                    func_088B85F8(s);
                    sceKernelResumeDispatchThread(x);
                    sceKernelSignalSema(*(s32 *)(s + 0x2931C), 1);
                    continue;
                }
                *(s32 *)(s + 0x100C) = 7;
                sceKernelDelayThreadCB(10000);
                continue;
            }
            sceKernelDelayThreadCB(10000);
            continue;
        }
    }
}
}
