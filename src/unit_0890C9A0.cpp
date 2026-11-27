/* unit_0890C9A0: 0x0890C9A0-0x0890CB64 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_0890CB64.
 *
 * C++ with a try/catch block: the compiler emits the $fp frame, the stack
 * pointer saved in the catch record and the implicit call to __end__catch
 * at the end of the catch. The name __unexpected is the one mwccpsp calls
 * from the handler of a `throw()` function (func_0890BFA4).
 */

typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    char *unk0;
    char *unk4;
    char *unk8;
    char *unkC;
    s32 unk10;
    char *unk14;
} Rec18;

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u8 *unkC;
} Rec10;

typedef struct {
    char *vtbl;
} Exc;

extern "C" {
extern char D_089B9264;
extern char D_089B927C;
extern char D_089BAEEC;
extern char **func_0890CB64(char **, short);
extern void __throw(char *, void *, void *);
extern void func_0890C200(void);
extern void func_0890C224(void);
extern u8 *func_0890C3F4(u8 *, u32 *);
extern u8 *func_0890C490(u8 *, u32 *);
extern s32 func_0890BFE0(char *, char *, s32 *);
}

static inline s32 find(Rec10 *es, char *type) {
    u8 *spec = es->unkC;
    u32 i;
    i = 0;
    if (es->unk0 != 0) {
        do {
            struct { s32 off; char *t; } l;
            l.t = (char *) (spec[0] | (spec[1] << 8) | (spec[2] << 16) | (spec[3] << 24));
            if (!func_0890BFE0(type, l.t, &l.off)) {
            } else {
                return 1;
            }
            i++;
            spec += 4;
        } while (i < es->unk0);
    }
    return 0;
}

extern "C" void __unexpected(Rec18 *arg0) {
    u8 *p = (u8 *) arg0->unk14;
    Rec10 es;

#pragma exception_magic
    try {
        func_0890C200();
    } catch (...) {
        es.unkC = func_0890C490(func_0890C3F4(func_0890C3F4(p + 1, &es.unk0), &es.unk4), &es.unk8);
        if (find(&es, ((Rec18 *) &__exception_magic)->unk4)) {
            __throw(0, 0, 0);
        }
        if (find(&es, &D_089B9264)) {
            Exc e;
            e.vtbl = &D_089BAEEC;
            __throw(&D_089B927C, &e, (void *) func_0890CB64);
        }
    }
    func_0890C224();
}
