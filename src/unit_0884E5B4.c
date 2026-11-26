/* unit_0884E5B4: 0x0884E5B4-0x0884E72C (ULES01213)
 *
 * Two thread bodies (no return): each waits on an event flag, handles the
 * current request, then clears and sets the flag again.
 */

typedef unsigned char u8;
typedef int s32;

extern int sceKernelWaitEventFlag(s32, s32, s32, s32, s32);
extern int sceKernelClearEventFlag(s32, s32);
extern int sceKernelSetEventFlag(s32, s32);
extern void sceKernelDcacheWritebackAll(void);
extern void memcpy(void *, void *, s32);
extern s32 func_0884E7FC(char *, char *);
extern void func_0884E998(char *, char *);
extern void func_0884E884(char *, char *);

void func_0884E5B4(s32 argc, void *argp) {
    char *p = *(char **)argp;

    for (;;) {
        sceKernelWaitEventFlag(*(s32 *)(p + 0x2FBC0), 1, 0, 0, 0);
        if (!(func_0884E7FC(p, *(char **)(p + 0x2FBC8)) != 0) == 0) {
            if (*(u8 *)(*(char **)(p + 0x2FBC8) + 0x1B) != 0) {
                func_0884E998(p, *(char **)(p + 0x2FBC8));
            }
            if (*(u8 *)(*(char **)(p + 0x2FBC8) + 0x1C) != 0) {
                func_0884E884(p, *(char **)(p + 0x2FBC8));
            }
        }
        sceKernelClearEventFlag(*(s32 *)(p + 0x2FBC0), -2);
        sceKernelSetEventFlag(*(s32 *)(p + 0x2FBC0), 0x10);
    }
}

void func_0884E678(s32 argc, void *argp) {
    char *p = *(char **)argp;
    char *r;

    for (;;) {
        sceKernelWaitEventFlag(*(s32 *)(p + 0x2FBE8), 1, 0, 0, 0);
        if (!(func_0884E7FC(p, *(char **)(p + 0x2FBC8)) != 0) == 0) {
            r = *(char **)(p + 0x2FBC8);
            memcpy((void *)(*(s32 *)(r + 4) + *(s32 *)(r + 0xC)), p + 0x9300, *(s32 *)(r + 8));
            sceKernelDcacheWritebackAll();
        }
        sceKernelClearEventFlag(*(s32 *)(p + 0x2FBE8), -2);
        sceKernelSetEventFlag(*(s32 *)(p + 0x2FBE8), 0x10);
    }
}
