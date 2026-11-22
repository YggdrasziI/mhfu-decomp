/* unit_0889F0D8: 0x0889F0D8-0x0889F1CC (ULES01213) */

typedef int s32;
typedef unsigned int u32;

extern s32 D_09A0B5BC;
extern s32 D_09A0B5C4;
extern s32 D_09A0B5C8;
extern char D_089B20DC[];
extern char D_089B20E4[];
extern char D_089B20EC[];
extern int func_0880D9EC(char *, ...);
extern void memcpy(void *, void *, s32);
extern s32 sceKernelSuspendDispatchThread(void);
extern s32 sceKernelResumeDispatchThread(s32);

s32 func_0889F0D8(s32 arg0, void *src, s32 size) {
    s32 state;
    s32 ret;
    u32 *q;
    u32 h;

    state = sceKernelSuspendDispatchThread();
    switch (arg0) {
    case 0:
        q = (u32 *)&D_09A0B5BC;
        if (D_09A0B5C4 == D_09A0B5C8) {
            func_0880D9EC(D_089B20DC);
            func_0880D9EC(D_089B20E4);
            func_0880D9EC(D_089B20EC);
            ret = 0x8000001A;
        } else {
            memcpy((char *)q[4] + (q[0] << 6), src, size);
            h = (q[0] + 1) % q[3];
            ret = q[2] + 1;
            q[2] = ret;
            q[0] = h;
        }
        break;
    default:
        ret = 0x80000019;
        break;
    }
    sceKernelResumeDispatchThread(state);
    return ret;
}
