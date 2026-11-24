/* unit_0885115C: 0x0885115C-0x0885128C (ULES01213)
 *
 * Bounds (hypothesis): 2 functions (func_0885115C, func_088511B4) between code still in assembly.
 */

/* func_0885115C (0x58) is a tail call through the vtable of D_089CC434
 * (`jr $t9`); func_088511B4 (0xD8) follows it. `#pragma exceptions off` gives
 * the tail call.
 */

#pragma exceptions off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad0[0x22];
    u16 unk22;
    u8 unk24;
    u8 unk25;
    char pad26[0x4C - 0x26];
    u8 unk4C;
    u8 unk4D;
} Obj;

typedef struct V34 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual s32 vfunc_34(u16, char *, s32, s32, s32, s32); } V34;

extern "C" {

extern V34 *D_089CC434;
extern char *D_08A631A0;
extern u16 D_0899CA40[];
extern char D_089CC440[];

extern s32 func_088900C4(char *, s32);

s32 func_0885115C(void) {
    return D_089CC434->vfunc_34(D_0899CA40[*(s32 *)(D_08A631A0 + 0xF7A574)], D_089CC440, -1, 0, 0, 1);
}

void func_088511B4(s32 arg0, Obj *arg1) {
    arg1->unk22++;
    if (arg1->unk22 >= 10) {
        do {
            u16 thr;
            arg1->unk22 -= 10;
            thr = (arg1->unk4C < arg1->unk4D) ? (u16)0x54 : (u16)0x10;
            if ((u16)func_088900C4(D_08A631A0, 1) % 100 < thr) {
                if (arg1->unk24 < 99) {
                    arg1->unk24++;
                }
            } else {
                if (arg1->unk25 < 99) {
                    arg1->unk25++;
                }
            }
        } while (arg1->unk22 >= 10);
    }
}

}
