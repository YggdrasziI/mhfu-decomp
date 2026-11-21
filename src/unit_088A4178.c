/* unit_088A4178: 0x088A4178-0x088A43C0 (ULES01213)
 *
 * Bounds (hypothesis): func_088A4178 is a static function defined before its
 * only caller func_088A4344, which keeps a0 live across the call to it (the
 * compiler only does this for a static callee defined earlier in the same
 * file), so the unit runs from func_088A4178 to the end of func_088A4344.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

/* 0x2C-byte entry of the 32-entry table D_09A0E3CC. */
typedef struct {
    s32 unk0;
    u16 unk4;
    u16 unk6;
    char unk8[0x4];
    s32 unkC;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    char unk1A[0x6];
    u16 unk20;
    u16 unk22;
    char *unk24;
    s32 unk28;
} T;

extern char D_09A0E3A0;
extern s32 D_09A0E3B0;
extern s32 D_09A0E3B4;
extern s32 D_09A0E3B8;
extern s32 D_09A0E3BC;
extern s32 D_09A0E3C0;
extern s32 D_09A0E3C4;
extern s32 D_09A0E3C8;
extern s32 D_09A0E3CC;

extern int memset(s32 *, s32, s32);
extern s32 sceKernelSuspendDispatchThread(void);
extern s32 sceKernelResumeDispatchThread(s32);
extern s32 func_088A3554(void);
extern void func_088A412C(void);
extern void func_088A4408(void *);

void func_088A4344(T *arg0);

static char *func_088A4178(void) {
    return &D_09A0E3A0;
}

void func_088A4184(void) {
    s32 var_s1;
    char *var_s0;

    func_088A412C();
    memset(&D_09A0E3CC, 0, 0x580);
    var_s1 = 0;
    var_s0 = (char *) (&D_09A0E3CC);
    do {
        *(s16 *)(var_s0 + 6) = var_s1;
        *(s32 *)(var_s0 + 8) = (s32) (1 << var_s1);
        func_088A4344((T *) (var_s0));
        var_s1 += 1;
        var_s0 += 0x2C;
    } while (var_s1 < 0x20);
    memset(&D_09A0E3B0, 0, 0x1C);
    D_09A0E3B0 = -1;
    D_09A0E3B4 = 0;
    D_09A0E3B8 = 0;
    D_09A0E3BC = 0;
    D_09A0E3C0 = 0;
    D_09A0E3C4 = 1;
    D_09A0E3C8 = 0;
}

char *func_088A4248(u32 arg0) {
    if (arg0 >= 0x20U) {
        return 0;
    }
    return (char *)&D_09A0E3CC + (arg0 * 0x2C);
}

void func_088A4280(T *arg0) {
    s32 state;

    if (arg0->unk6 < 0x20) {
        state = sceKernelSuspendDispatchThread();
        arg0->unkC |= 0x4000;
        arg0->unkC &= ~0x8000;
        arg0->unk0 = func_088A3554();
        arg0->unk4 = 0;
        sceKernelResumeDispatchThread(state);
    }
}

void func_088A42F0(T *arg0) {
    s32 state;

    if (arg0->unk6 < 0x20) {
        state = sceKernelSuspendDispatchThread();
        arg0->unkC |= 0x8000;
        arg0->unkC &= ~0x4000;
        sceKernelResumeDispatchThread(state);
    }
}

void func_088A4344(T *arg0) {
    s32 state = sceKernelSuspendDispatchThread();
    arg0->unk10 = 0;
    arg0->unk12 = 0;
    arg0->unk20 = 0;
    arg0->unk22 = 0;
    arg0->unk14 = 0x2000;
    arg0->unk16 = 0x80FF;
    arg0->unk18 = 0x5FC0;
    arg0->unk24 = func_088A4178();
    arg0->unk28 = 0x10;
    arg0->unkC = 0x8C04;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    sceKernelResumeDispatchThread(state);
    func_088A4408(arg0);
}
