/* unit_0889A32C: 0x0889A32C-0x0889A3D8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function. func_0889A32C: takes a 20-byte record by pointer, copies it, and updates
 * the object it points to. */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    s32 unk0;
    s32 unk4;
    char *obj;
    signed char unkC;
    char padD[3];
    u16 unk10;
} Rec_0889A32C;

extern void func_0889CF34(char *obj, s32 arg1);
extern void func_0889D6EC(char *obj);

void func_0889A32C(Rec_0889A32C *arg0) {
    Rec_0889A32C rec = *arg0;
    char *obj = rec.obj;

    *(s32 *) (obj + 0x12C0) &= ~0x10;
    *(u8 *) (obj + 0x1AF4) = rec.unkC == 0;
    *(s32 *) (obj + 0x1AF8) = rec.unk10;
    if (*(u8 *) (obj + 0x1AF4)) {
        func_0889CF34(obj, 1);
        func_0889D6EC(obj);
    } else if (*(s32 *) (obj + 0x1AF8) == 0x8003) {
        *(u8 *) (obj + 0x1AFC) = 1;
    }
}
