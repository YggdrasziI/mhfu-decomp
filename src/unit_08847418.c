/* unit_08847418: 0x08847418-0x088474DC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_08847418: draws a frame from three pieces (0x29, 0x2A, 0x2B). */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
} Unk3AC;

extern s16 D_08939398;
extern Unk3AC D_089393AC;

extern s32 func_0882A9DC(char *, u16, u16, s32);
extern s32 func_0882AF70(char *, u16, u16, u16, u16, s32);

void func_08847418(char *arg0, u16 x, u16 y, u16 w, u16 h) {
    Unk3AC *s = (Unk3AC *)(s32)&D_089393AC;

    func_0882A9DC(arg0, x, y, 0x29);
    func_0882AF70(arg0, x + D_08939398, y, w - D_08939398 - s->unk4, h, 0x2A);
    func_0882A9DC(arg0, x + w - s->unk4, y, 0x2B);
}
