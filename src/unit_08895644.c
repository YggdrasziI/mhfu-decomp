/* unit_08895644: 0x08895644-0x08895EA0 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

typedef int s32;
typedef unsigned char u8;
typedef float f32;
typedef struct { f32 a, b, c; } F3;

extern s32 func_0889560C(s32, s32);
extern void *func_08859B44(void *, s32, s32);
extern char *func_08897290(s32, void *);
extern char *func_0885A994(char *);
extern char *func_088B9B0C(char *);
extern char *func_0887F464(char *);
extern char *func_0884D06C(char *);
extern char *func_0884AF84(char *);
extern char *func_088B8374(char *);
extern char *func_088B9DA8(char *);
extern char *func_088BA0BC(char *);
extern char *func_089038C4(char *);
extern char *func_088A6FEC(char *);
extern char *func_088B97BC(char *);
extern char *func_088CC568(char *);
extern char *func_08906744(char *);
extern f32 D_089AD408[];
extern f32 D_089AD410;
extern f32 D_089AD414;
extern char D_089BAB98;
extern char D_089BAA94;
extern s32 D_089CC01C;
extern s32 __ptmf_test(f32 *);
typedef struct Obj { char pad[0x10]; signed char f10; u8 f11; u8 f12; char pad13; s32 f14; } Obj;
typedef struct Mgr { Obj *obj[4]; } Mgr;

#define FINISH()                                                        \
            arg0->obj[(u8) arg1] = (Obj *) p;                           \
            if (arg0->obj[(u8) arg1] != 0) {                            \
                arg0->obj[(u8) arg1]->f10 = arg1;                       \
                arg0->obj[(u8) arg1]->f14 = arg2;                       \
                q = arg0->obj[(u8) arg1]; q->f11 = 2; q->f12 = 0;                      \
            }

#define CREATE(size, ctor)                                              \
    if ((u8) arg1 < 4) {                                                \
        mem = func_08859B44((char *) arg0 + 0x14010, size, 0x10);       \
        if (mem != 0) {                                                 \
            p = func_08897290(size, mem);                               \
            if (p != 0) {                                               \
                p = ctor(p);                                            \
            }                                                           \
            FINISH()                                                    \
        }                                                               \
    }                                                                   \
    break;

void func_08895644(Mgr *arg0, s32 arg1, s32 arg2) {
    void *mem;
    char *p;
    Obj *q;
    F3 sp24;

    if ((u8) func_0889560C((s32) arg0, arg1) != 0) {
        return;
    }
    if (arg2 == 0) {
        return;
    }
    switch (arg2) {
    case 1: CREATE(0x20, func_0885A994)
    case 2: CREATE(0x30, func_088B9B0C)
    case 3: CREATE(0x24, func_0887F464)
    case 4: CREATE(0xA0, func_0884D06C)
    case 5: CREATE(0x24, func_0884AF84)
    case 6: CREATE(0x3C, func_088B8374)
    case 7: CREATE(0x64, func_088B9DA8)
    case 8: CREATE(0x68, func_088BA0BC)
    case 9: CREATE(0x129B0, func_089038C4)
    case 10: CREATE(0x78, func_088A6FEC)
    case 11: CREATE(0x70, func_088B97BC)
    case 12:
        if ((u8) arg1 < 4) {
            mem = func_08859B44((char *) arg0 + 0x14010, 0x34, 0x10);
            if (mem != 0) {
                p = func_08897290(0x34, mem);
                if (p != 0) {
                    *(char **) p = &D_089BAB98;
                    sp24.a = D_089AD408[1];
                    sp24.b = D_089AD410;
                    sp24.c = D_089AD414;
                    if (__ptmf_test((f32 *) &sp24) != 0) {
                        *(F3 *) (p + 4) = sp24;
                    }
                    D_089CC01C = (s32) ((char *) (s32) (p + 0x1C) - 0x1C);
                    *(char **) p = &D_089BAA94;
                }
                FINISH()
            }
        }
        break;
    case 13: CREATE(0x218, func_088CC568)
    case 14: CREATE(0x20, func_08906744)
    }
}
