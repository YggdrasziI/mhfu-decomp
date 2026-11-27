/* unit_088131FC: 0x088131FC-0x08813320 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma opt_propagation off

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    s8 unk0;
    char pad1[3];
    char *unk4[3];
    char pad10[0x20];
    u8 unk30;
    u8 unk31[3];
    s16 unk34;
    s16 unk36;
    s32 unk38[3];
    s32 unk44[3];
    s32 unk50;
    s32 unk54;
} S;

void func_088131FC(char *arg0, char *arg1, u8 arg2) {
    S *s = (S *)(arg0 + 0x7E0);
    char *src;
    char *dst;
    s32 n;

    if (arg2 == 1) {
        s->unk0 = 0;
        s->unk30 = 2;
        s->unk36 = 0xF;
    } else {
        if (s->unk30 == 2) {
            s->unk0 = 0;
        }
        s->unk30 = 1;
    }
    if (arg1 != 0) {
        s->unk0 = 0;
        n = 0;
        s->unk54 = 0;
        s->unk4[n] = arg1;
        s->unk50 = 0x3F060A92;
        s->unk34 = 0xF;
        s->unk31[s->unk54] = 0;
        dst = (char *)s + 0x10;
        src = arg1 + 0x200;
        asm {
            lv.q C000, 0(src)
            sv.q C000, 0(dst)
        }
    } else {
        s->unk4[s->unk54] = arg1;
        s->unk50 = 0x3F060A92;
        s->unk34 = 0xF;
        switch (s->unk31[s->unk54]) {
        case 4:
            s->unk38[s->unk54] = 0x43200000;
            s->unk44[s->unk54] = 0x42F00000;
            break;
        default:
            s->unk38[s->unk54] = 0x42F00000;
            s->unk44[s->unk54] = 0x43960000;
            break;
        }
    }
}
