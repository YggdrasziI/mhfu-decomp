/* unit_0886423C: 0x0886423C-0x088642FC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef unsigned short u16;
typedef int s32;
typedef float f32;

typedef struct {
    char pad0[0x10];
    f32 unk10;
    s32 unk14;
    f32 unk18;
    f32 unk1C;
    char pad20[0x18];
    char *unk38;
    u16 unk3C;
    char pad3E[2];
} Entry;

extern f32 func_0886025C(char *arg0, char *arg1);

static inline void vec_zero(void *dst) {
    asm {
        vzero.q C000
        sv.q C000, 0(dst)
    }
}

void func_0886423C(Entry *arg0, char *arg1, s32 arg2, f32 arg3) {
    arg0[arg2].unk3C |= 1;
    arg0[arg2].unk10 = arg3;
    arg0[arg2].unk14 = 0x40000000;
    arg0[arg2].unk18 = *(f32 *)(arg1 + 0x10);
    arg0[arg2].unk1C = func_0886025C(*(char **)((char *)arg0 + 0x110), arg1);
    if (*(s32 *)(arg1 + 0xC) != 0) {
        arg0[arg2].unk3C |= 2;
    } else {
        arg0[arg2].unk3C &= ~2;
    }
    arg0[arg2].unk38 = arg1;
    if (arg2 == 0) {
        vec_zero((char *)&arg0[arg2] + 0x40);
    }
}
