/* unit_088DE8EC: 0x088DE8EC-0x088DEA14 (ULES01213)
 *
 * 1 function between jpeg-6b/jcomapi and unit_088DEA14: the decoder
 * initialisation of the IJG JPEG library (jpeg_CreateDecompress of
 * jdapimin.c), written from the assembly before the library was
 * identified. Kept until jdapimin.c itself is linked.
 *
 * Optimized for speed, as the library (unrolled loops).
 */

#pragma optimize_for_size off

typedef unsigned char u8;
typedef int s32;

typedef struct Obj Obj;

typedef struct Err {
    void (*error_exit)(Obj *);
    char pad4[0x10];
    s32 code;
    s32 parm[2];
} Err;

struct Obj {
    Err *err;
    void *mem;
    s32 unk8;
    s32 unkC;
    u8 unk10;
    s32 state;
    s32 unk18;
    char pad1C[0x74];
    s32 unk90[4];
    s32 unkA0[4];
    s32 unkB0[4];
    char padC0[0x4C];
    s32 unk10C;
};

extern void memset(void *, s32, s32);
extern void func_088E3250(Obj *);
extern void func_088E6310(Obj *);
extern void func_088EC284(Obj *);

void func_088DE8EC(Obj *arg0, s32 arg1, s32 arg2) {
    s32 i;

    arg0->mem = 0;
    if (arg1 != 62) {
        arg0->err->code = 12;
        arg0->err->parm[0] = 62;
        arg0->err->parm[1] = arg1;
        arg0->err->error_exit(arg0);
    }
    if (arg2 != 0x1B0) {
        arg0->err->code = 21;
        arg0->err->parm[0] = 0x1B0;
        arg0->err->parm[1] = arg2;
        arg0->err->error_exit(arg0);
    }
    {
        Err *err = arg0->err;
        s32 keep = arg0->unkC;

        memset(arg0, 0, 0x1B0);
        arg0->err = err;
        arg0->unkC = keep;
    }
    arg0->unk10 = 1;
    func_088EC284(arg0);
    arg0->unk8 = 0;
    arg0->unk18 = 0;
    for (i = 0; i < 4; i++) {
        arg0->unk90[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        arg0->unkA0[i] = 0;
        arg0->unkB0[i] = 0;
    }
    arg0->unk10C = 0;
    func_088E6310(arg0);
    func_088E3250(arg0);
    arg0->state = 200;
}
