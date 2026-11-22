/* unit_08882750: 0x08882750-0x0888291C (ULES01213)
 *
 * State machine on the word at +0x8B98: state 0 walks the entry table at
 * +0x8B54 (u16 ids, s16 arguments 3 entries later), calls func_088DE014 and
 * either the 0x34 virtual method of D_089CC434 or func_088DDD9C, then moves
 * to state 1; state 1 walks it again through func_088816AC / func_08886638.
 *
 * C++: virtual call through D_089CC434; speed setting.
 */

#pragma optimize_for_size off

typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, u8, s32, s32); } V34;

typedef struct S8B54 { u16 id[3]; s16 arg[3]; u8 flag; } S8B54;

extern "C" {

extern V34 *D_089CC434;
extern s32 D_09A4F0D0;
extern s32 D_08A62D94;

extern void func_08881824(char *);
extern s32 func_088816AC(char *, s32, s32);
extern s32 func_08886664(s32, s32);
extern void func_08886638(s32, s32, u16, s32);
extern s32 func_088DE014(s32, s32);
extern void func_088DDD9C(s32, s32, s32, s32);

void func_08882750(char *arg0) {
    S8B54 *s;
    s32 r;
    s32 i;
    u16 *p;
    s32 j;

    s = (S8B54 *)(arg0 + 0xB5C + 0x7FF8);
    p = s->id;
    switch (*(s32 *)(arg0 + 0x8B98)) {
    case 0:
        for (i = 0; i < *(s32 *)(arg0 + 0x562434); i++) {
            if (s->id[i] != 0xFFFF) {
                r = func_088DE014(D_09A4F0D0, s->id[i]);
                if (r == -1) {
                    D_089CC434->vfunc_34(s->id[i], func_08886664(D_08A62D94, s->arg[i]), -1,
                                         s->flag, 0, 1);
                } else {
                    func_088DDD9C(D_09A4F0D0, func_08886664(D_08A62D94, s->arg[i]), r, -1);
                }
            } else {
                func_08881824(arg0);
            }
        }
        (*(s32 *)(arg0 + 0x8B98))++;
        break;
    case 1:
        for (j = 0; j < *(s32 *)(arg0 + 0x562434); j++, p++) {
            if (p[0] != 0xFFFF) {
                func_08886638(D_08A62D94, (s16)p[3], p[0],
                              func_088816AC(arg0, (s16)p[3], p[0]));
            }
        }
        func_08881824(arg0);
        break;
    }
}

}
