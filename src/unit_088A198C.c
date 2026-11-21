/* unit_088A198C: 0x088A198C-0x088A1E70 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef int s32;
typedef unsigned int u32;

extern char D_09A0D260[];
extern s32 D_09A0D254;
extern float D_089B23E8[2];
extern float D_089B23F0[2];
extern float D_089B23F8[2];
extern float D_089B2400[2];
extern float D_089B2408[2];
extern float D_089B2410[2];
extern float D_089B2420[2];
extern float D_089B2428[2];
extern float D_089B2430[2];
extern float D_089B2418;
extern float D_089B241C;
extern float D_089B2438;
extern char D_089B2450[];
extern char D_089B2458[];
extern char D_089B2460[];
extern char D_089B2480[];
extern char D_089B2498[];
extern char D_089B24B4[];
extern int func_0880D9EC(char *, ...);
extern s32 func_088A2498(s32, void *);
extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);
extern int memset(void *, s32, s32);
extern void func_088A3244(void *);
extern void func_088A2F88(void *, char *);
extern int func_08897A78(s32, s32, s32);
extern int func_08897B48(s32, s32);
extern int func_08897A08(s32, s32);

typedef struct {
    float v[21];
    char pad[0xB4 - 0x54];
} Params;

char *func_088A198C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *p = 0;
    Params prm;
    s32 tid;
    char *e;
    s32 ret;

    e = D_09A0D260 + arg0 * 0x204;
    if (*(s32 *)e == 1) {
        func_0880D9EC(D_089B2450);
        func_0880D9EC(D_089B2458);
        func_0880D9EC(D_089B2460);
        return e;
    }
    tid = sceKernelCreateThread(D_089B2480, func_088A2498, D_09A0D254, 0x8000, 0, 0);
    if (tid < 0) {
        func_0880D9EC(D_089B2450);
        func_0880D9EC(D_089B2458);
        func_0880D9EC(D_089B2498, tid);
        return 0;
    }
    p = e;
    memset(e, 0, 0x204);
    *(s32 *)(p + 0x4) = tid;
    *(s32 *)(p + 0x8) = -1;
    *(s32 *)(p + 0xC) = 0;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x20) = arg0;
    *(s32 *)(p + 0x24) = arg1;
    *(s32 *)(p + 0x28) = 0;
    *(s32 *)(p + 0x2C) = 0;
    *(s32 *)(p + 0x30) = 0;
    *(s32 *)(p + 0x34) = 0;
    *(s32 *)(p + 0x38) = 0;
    *(s32 *)(p + 0x3C) = 0;
    *(s32 *)(p + 0x40) = 0;
    *(s32 *)(p + 0x44) = 0;
    *(s32 *)(p + 0x48) = 0;
    *(s32 *)(p + 0x4C) = 0;
    *(s32 *)(p + 0x50) = 0;
    *(s32 *)(p + 0x54) = 0;
    *(s32 *)(p + 0x58) = 0;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x64) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0x7F;
    *(u32 *)(p + 0x70) = (*(u32 *)(p + 0x6C) << 15) / 127;
    *(s32 *)(p + 0x74) = 0x40;
    *(s32 *)(p + 0x78) = 0;
    *(s32 *)(p + 0x90) = 0;
    *(s32 *)(p + 0x94) = arg3 / 2;
    *(u32 *)(p + 0x80) = *(u32 *)(p + 0x94) / 2 / 2;
    *(s32 *)(p + 0x7C) = *(s32 *)(p + 0x80) - 0x40;
    *(s32 *)(p + 0x84) = 0;
    *(s32 *)(p + 0x88) = 0;
    *(s32 *)(p + 0x8C) = 0;
    *(s32 *)(p + 0x98) = arg2;
    *(s32 *)(p + 0x9C) = arg2 + arg3 / 2;
    *(s32 *)(p + 0xA0) = 0;
    memset(*(void **)(p + 0x98), 0, *(s32 *)(p + 0x94));
    memset(*(void **)(p + 0x9C), 0, *(s32 *)(p + 0x94));
    *(s32 *)(p + 0xA4) = 0;
    *(s32 *)(p + 0xA8) = 0;
    *(s32 *)(p + 0xAC) = 0;
    memset(p + 0xB0, 0, 0x80);
    *(s32 *)(p + 0x130) = 0;
    *(s32 *)(p + 0x134) = 0;
    *(s32 *)(p + 0x138) = 0;
    *(s32 *)(p + 0x13C) = 0;
    *(s32 *)(p + 0x140) = 0;
    *(s32 *)(p + 0x144) = 0;
    *(s32 *)(p + 0x148) = 0;
    *(s32 *)(p + 0x14C) = 0;
    func_088A3244(&prm);
    prm.v[0] = D_089B23E8[1];
    prm.v[1] = D_089B23F0[0];
    prm.v[2] = D_089B23F0[1];
    prm.v[3] = D_089B23F8[0];
    prm.v[4] = D_089B23F8[1];
    prm.v[5] = D_089B2400[0];
    prm.v[6] = D_089B2400[1];
    prm.v[7] = D_089B2408[0];
    prm.v[8] = D_089B2408[1];
    prm.v[9] = D_089B2410[0];
    prm.v[10] = D_089B2410[1];
    prm.v[11] = D_089B2418;
    prm.v[12] = D_089B241C;
    prm.v[13] = D_089B2420[0];
    prm.v[14] = D_089B2420[0];
    prm.v[15] = D_089B2420[1];
    prm.v[16] = D_089B2428[0];
    prm.v[17] = D_089B2428[1];
    prm.v[18] = D_089B2430[0];
    prm.v[19] = D_089B2430[1];
    prm.v[20] = D_089B2438;
    func_088A2F88(&prm, p);
    func_08897A78(*(s32 *)(p + 0x24), *(s32 *)(p + 0x70), *(s32 *)(p + 0x70));
    func_08897B48(*(s32 *)(p + 0x24), 0);
    func_08897A08(*(s32 *)(p + 0x24), 0x40);
    ret = sceKernelStartThread(*(s32 *)(p + 0x4), 4, &p);
    if (ret != 0) {
        func_0880D9EC(D_089B2450);
        func_0880D9EC(D_089B2458);
        func_0880D9EC(D_089B24B4, ret);
        return 0;
    }
    *(s32 *)p = 1;
    return p;
}
