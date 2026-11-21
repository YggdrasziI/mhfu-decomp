/* unit_088A32A0: 0x088A32A0-0x088A3480 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between its neighbours.
 */

typedef int s32;
typedef signed char s8;

typedef struct {
    s32 unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    char unk20[0x14];
    float unk34;
    float unk38;
    char unk3C[0x78];
} Param;

extern s8 D_09A0DB44;
extern int D_09A0DA8C;
extern s32 D_09A0DA80;
extern s32 D_09A0DA74;
extern s32 D_09A0DA78;
extern s32 D_09A0DA7C;
extern float D_089B24E0[2];
extern float D_089B24E8[2];
extern float D_089B24F0[2];
extern float D_089B24F8[2];
extern float D_089B2510;
extern char D_089B2530[];
extern char D_089B2544[];
extern char D_089B254C[];
extern char D_089B2554[];
extern char D_089B2570[];

extern void func_088A3ED4(Param *);
extern void func_088A3AB0(Param *);
extern void func_088A356C(void);
extern s32 sceKernelCreateThread(const char *, void *, s32, s32, s32, void *);
extern s32 sceKernelStartThread(s32, s32, void *);
extern int func_0880D9EC(char *, ...);
extern s32 func_088A407C(void);
/* func_088A40D4 reads one argument (src/unit_088A407C.c), but this call
 * sets no $a0: the original passes whatever func_088A407C left there. */
extern void func_088A40D4(void);
extern int func_08897A08(s32, s32);
extern int func_08897A78(s32, s32, s32);
extern int func_08897B48(s32, s32);

s32 func_088A32A0(s32 arg0, s32 arg1) {
    Param p;
    s32 ret;

    D_09A0DB44 = 0;
    D_09A0DA8C = 0;
    func_088A3ED4(&p);
    p.unk4 = D_089B24E0[0];
    p.unk8 = D_089B24E0[1];
    p.unkC = D_089B24E8[0];
    p.unk10 = D_089B24E8[1];
    p.unk14 = D_089B24F0[0];
    p.unk18 = D_089B24F0[1];
    p.unk1C = D_089B24F8[0];
    p.unk34 = D_089B2510;
    p.unk38 = D_089B2510;
    func_088A3AB0(&p);
    if (arg1 < 0 || arg1 > 2) { return -1; }
    D_09A0DA80 = sceKernelCreateThread(D_089B2530, func_088A356C, arg0, 0x1000, 0, 0);
    if (D_09A0DA80 < 0) {
        func_0880D9EC(D_089B2544);
        func_0880D9EC(D_089B254C);
        func_0880D9EC(D_089B2554, D_09A0DA80);
        return -1;
    }
    D_09A0DA74 = arg1;
    func_088A407C();
    func_088A40D4();
    func_08897A08(D_09A0DA74, 0x100);
    func_08897A78(D_09A0DA74, 0x8000, 0x8000);
    func_08897B48(D_09A0DA74, 0);
    ret = sceKernelStartThread(D_09A0DA80, 0, 0);
    if (ret != 0) {
        func_0880D9EC(D_089B2544);
        func_0880D9EC(D_089B254C);
        func_0880D9EC(D_089B2570, ret);
        return -1;
    }
    D_09A0DA78 = 0;
    D_09A0DA7C = -1;
    return D_09A0DA80;
}
