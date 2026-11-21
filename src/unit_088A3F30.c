/* unit_088A3F30: 0x088A3F30-0x088A3FF4 (ULES01213) */

typedef int s32;

extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);
extern int func_0880D9EC(char *, ...);
extern s32 func_088A4004(s32, void *);

extern s32 D_09A0E384;
extern s32 D_09A0E388;
extern s32 D_09A0E38C;
extern char D_089B2590[];
extern char D_089B25A4[];
extern char D_089B25AC[];
extern char D_089B25B4[];

s32 func_088A3F30(s32 arg0) {
    s32 *p;
    s32 thread;

    p = &D_09A0E384;
    D_09A0E384 = 0;
    D_09A0E388 = 0;
    D_09A0E38C = 0;
    thread = sceKernelCreateThread(D_089B2590, func_088A4004, arg0, 0x1000, 0, 0);
    if (thread < 0) {
        func_0880D9EC(D_089B25A4);
        func_0880D9EC(D_089B25AC);
        func_0880D9EC(D_089B25B4, thread);
        return -1;
    }
    D_09A0E384 = thread;
    D_09A0E38C = 0;
    sceKernelStartThread(thread, 4, &p);
    return D_09A0E384;
}
