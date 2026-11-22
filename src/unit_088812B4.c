/* unit_088812B4: 0x088812B4-0x088813E0 (ULES01213) */

typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4;
} Unk8B2C;

extern s32 D_08A62D94;
extern u16 func_0888670C(s32, s32);
extern void func_088817E8(char *, s32, s32);
extern int func_08881438(char *, s32);
extern void func_0888664C(s32, s32);
extern void func_0888291C(char *, s32);

s32 func_088812B4(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    Unk8B2C *p;

    if (func_0888670C(D_08A62D94, arg1) != arg2) {
        if (arg3 == 1) {
            func_088817E8(arg0, 0x13, 0);
            func_088817E8(arg0, 0x14, 0);
            i = 0;
            do {
                func_08881438(arg0, i);
                func_0888664C(D_08A62D94, arg1 + i);
                i++;
            } while (i < 3);
        } else {
            func_0888664C(D_08A62D94, arg1);
        }
    } else {
        arg2 = 0xFFFF;
    }
    if (*(s32 *)(arg0 + 0x8B94) == 0) {
        p = (Unk8B2C *)(arg0 + 0x8B2C);
        p->unk2 = arg1;
        p->unk0 = arg2;
        p->unk4 = arg4;
        *(s32 *)(arg0 + 0x8B94) = 1;
        if (arg3 == 1) {
            func_0888291C(arg0, 2);
        }
        return 1;
    }
    return 0;
}
