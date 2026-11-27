/* unit_08842628: 0x08842628-0x088428EC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off


typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

extern char *D_08A631A8;
extern s32 D_09A4F0C4;
extern char *D_089CC438;
extern char *D_089CBBE4;
extern s32 D_089CBBE8;
extern char *D_09A0B544;

extern void func_08890DE8(char *, s8, u8);
extern void func_08890E38(char *, s8);
extern char *func_088DCEBC(s32, s32);
extern s32 func_08865BAC(void *);
extern void func_08814674(char *, float *, float *);
extern s32 func_088167F4(s32, char *);
extern void func_088912BC(char *, s16, s16, char *);

static inline void mtx_identity(float *m) {
    asm {
        vmidt.q E000
        sv.q C000, 0x0(m)
        sv.q C010, 0x10(m)
        sv.q C020, 0x20(m)
        sv.q C030, 0x30(m)
    }
}

void func_08842628(char *arg0) {
    float mtx[16] __attribute__((aligned(16)));
    float in[4] __attribute__((aligned(16)));
    float out[4] __attribute__((aligned(16)));
    s32 i;
    char *e;
    char *t;
    u16 w;

    func_08890DE8(D_08A631A8, 0x10, 0xE);
    func_08890E38(D_08A631A8, 0);
    for (i = 0; i < 4; i++) {
        e = func_088DCEBC(D_09A4F0C4, i);
        if (e == 0) continue;
        if (*(u16 *)(e + 0x1E6) == (u8)D_089CC438[0x28]) continue;
        if ((s32)((*(u32 *)(e + 4) & 1) != 0) == 0) continue;
        if ((s32)((*(u32 *)(e + 4) & 2) != 0) == 0) continue;
        if ((u8)func_08865BAC(e) == 0) continue;
        if (*(u8 *)(e + 0x1E8) == 0xC) continue;
        mtx_identity(mtx);
        in[0] = *(float *)(e + 0x200);
        in[1] = 200.0f + *(float *)(e + 0x204);
        in[2] = *(float *)(e + 0x208);
        in[3] = 1.0f;
        func_08814674(D_089CBBE4, out, in);
        if (out[3] <= 0.0f) continue;
        if (out[0] >= 562.0f) continue;
        if (out[0] <= -50.0f) continue;
        if (out[1] >= 272.0f) continue;
        if (out[1] <= -20.0f) continue;
        t = D_09A0B544 + *(u8 *)(e + 0x1E6) * 200 + 0xBC8;
        w = func_088167F4(D_089CBBE8, t) * 4;
        func_088912BC(D_08A631A8, (s16)((u16)(u32)out[0] - w), (s16)(u32)out[1], t);
    }
}
