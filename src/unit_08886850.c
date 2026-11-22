/* unit_08886850: 0x08886850-0x08886870 (ULES01213) */

typedef int s32;
typedef short s16;

typedef struct {
    s32 unk0;
    char pad4[0x8];
    s16 unkC;
    char padE[0xA];
} Entry08886850;

extern void func_088A2378(s32, s32);

void func_08886850(Entry08886850 *arg0, s32 arg1, s32 arg2) {
    Entry08886850 *e = &arg0[arg1];
    e->unkC = arg2;
    func_088A2378(e->unk0, arg2);
}
