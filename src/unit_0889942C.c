/* unit_0889942C: 0x0889942C-0x088994AC (ULES01213) */

typedef int s32;
typedef unsigned char u8;

typedef struct {
    char b[6];
} Id6;

typedef struct {
    Id6 id;
    struct { u8 a; u8 b; } unk6;
} Rec;

extern void memset(void *, s32, s32);
extern Rec *func_0889C518(s32);

void func_0889942C(s32 arg0, Rec *arg1) {
    Rec *src;

    memset(arg1, 0, 0x20);
    src = func_0889C518(arg0);
    arg1->id = src->id;
    arg1->unk6 = src->unk6;
}
