/* unit_088DE804: 0x088DE804-0x088DEA14 (ULES01213)
 *
 * Bounds (hypothesis): 5 functions between unit_088DE6EC and unit_088DEA14.
 *
 * Common part of an image codec object (hypothesis from the shape and the
 * constants - version 62, object size 0x1B0, states 100 and 200: the IJG
 * JPEG library, release 6b; no string of the library proves it here).
 * func_088DE804 aborts the object (frees pool 1 of its memory manager),
 * func_088DE858 destroys it, func_088DE894 and func_088DE8C0 allocate a
 * 0x82-byte and a 0x112-byte table from pool 0 and clear their last
 * byte, func_088DE8EC initialises a decoder object after checking the
 * version and the size the caller was built with.
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

typedef struct Mem {
    char *(*alloc_small)(Obj *, s32, s32);
    char pad4[0x20];
    void (*free_pool)(Obj *, s32);
    void (*self_destruct)(Obj *);
} Mem;

struct Obj {
    Err *err;
    Mem *mem;
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

extern void func_0880C464(void *, s32, s32);
extern void func_088E3250(Obj *);
extern void func_088E6310(Obj *);
extern void func_088EC284(Obj *);

void func_088DE804(Obj *arg0) {
    if (arg0->mem == 0) {
        return;
    }
    arg0->mem->free_pool(arg0, 1);
    if (arg0->unk10 != 0) {
        arg0->state = 200;
        arg0->unk10C = 0;
    } else {
        arg0->state = 100;
    }
}

void func_088DE858(Obj *arg0) {
    if (arg0->mem != 0) {
        arg0->mem->self_destruct(arg0);
    }
    arg0->mem = 0;
    arg0->state = 0;
}

char *func_088DE894(Obj *arg0) {
    char *t = arg0->mem->alloc_small(arg0, 0, 0x82);

    *(u8 *)(t + 0x80) = 0;
    return t;
}

char *func_088DE8C0(Obj *arg0) {
    char *t = arg0->mem->alloc_small(arg0, 0, 0x112);

    *(u8 *)(t + 0x111) = 0;
    return t;
}

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

        func_0880C464(arg0, 0, 0x1B0);
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
