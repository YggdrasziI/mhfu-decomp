/* unit_088A4408: 0x088A4408-0x088A4504 (ULES01213) */

typedef int s32;
typedef short s16;
typedef unsigned short u16;

extern void func_08897470(u16, s16, s16, u16, u16);
extern void func_088974D4(u16, u16);
extern void func_08897580(u16, u16, u16);
extern void func_08897524(u16, s32, s32, s32);
extern void func_088973F8(u16);
extern void func_08897434(u16);

typedef struct {
    char unk0[0x6];
    u16 unk6;
    char unk8[0x4];
    s32 unkC;
    s16 unk10;
    s16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    char unk1A[0x6];
    u16 unk20;
    u16 unk22;
    s32 unk24;
    s32 unk28;
} T;

void func_088A4408(T *arg0) {
    s32 bit;
    s32 flags;

    flags = arg0->unkC;
    bit = 1;
    if (flags != 0) do {
        switch (flags & bit) {
        case 0x400:
            func_08897470(arg0->unk6, arg0->unk10, arg0->unk12, arg0->unk20, arg0->unk22);
            break;
        case 0x4:
            func_088974D4(arg0->unk6, arg0->unk14);
            break;
        case 0x800:
            func_08897580(arg0->unk6, arg0->unk16, arg0->unk18);
            break;
        case 0x4000:
            func_08897524(arg0->unk6, arg0->unk24, arg0->unk28, 1);
            func_088973F8(arg0->unk6);
            break;
        case 0x8000:
            func_08897434(arg0->unk6);
            break;
        }
        flags = arg0->unkC & ~bit;
        arg0->unkC = flags;
        bit <<= 1;
    } while (flags != 0);
}
