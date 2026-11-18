/* unit_088ABE58: 0x088ABE58-0x088AC04C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between func_088AB980 (still in
 * assembly) and unit_088AC04C.
 *
 * C++: the member bit is tested through an inline function returning a
 * bool (kept as `sltu`), virtual call.
 *
 * Follows the wireless switch (shows a message through func_088307BC when
 * it is turned off), then, for each of the four members whose bit is set
 * in unk171 of the session object, clears the bit and the record's active
 * flag and removes or resets the member's object.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct V6C { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(s32, s32, s32); } V6C;

typedef struct {
    char unk0[0x171];
    u8 unk171;
    char unk172[4];
    u8 unk176;
} Lobby;

extern "C" {

extern char *D_089CC438;
extern char *D_089CBBEC;
extern char *D_08A62C7C;
extern s32 D_09A4F0C4;
extern u16 D_089ACF9C;
extern Lobby *D_09A1DAEC;

s32 sceWlanGetSwitchState(void);
char *func_0885151C(char *, u16);
void func_088307BC(char *, char *);
u8 func_08830728(char *, s8, s16, s16);
char *func_088DCEBC(s32, s32);
void func_088DB534(s32, s32);
void func_088DBE70(s32, s32);
void func_08865D84(char *);
s32 func_08865CB8(char *, s32, s32);
s32 func_08872ED4(char *, s32);
void func_088AB6D0(Lobby *, s32, void *);

inline bool clearBit(u8 *f, u8 n) {
    bool set = (*f & (1 << n)) != 0;
    *f &= (u8) ~(1 << n);
    return set;
}

void func_088ABE58(Lobby *l) {
    s32 i;
    char *p;
    s32 r;
    u8 msg[8];
    u8 on;

    on = sceWlanGetSwitchState() == 1;
    if (l->unk176 != on) {
        if (sceWlanGetSwitchState() != 1) {
            func_088307BC(D_089CBBEC, func_0885151C(D_089CC438, D_089ACF9C));
        }
    }
    if (l->unk176 != 0) {
        l->unk176 = sceWlanGetSwitchState() == 1;
    }
    for (i = 0; i < 4; i++) {
        if (clearBit(&D_09A1DAEC->unk171, i)) {
            *(u8 *) (D_089CC438 + (u8) i * 0x8C + 0x30) = 0;
            func_08830728(D_089CBBEC, 3, 3, i);
            p = func_088DCEBC(D_09A4F0C4, i);
            if (p != 0) {
                if (*(u16 *) (p + 0x29A) != *(u16 *) (D_089CC438 + 0x6AF0E)) {
                    func_088DB534(D_09A4F0C4, *(u8 *) (p + 0x1E6));
                    func_088DBE70(D_09A4F0C4, *(u16 *) (p + 0x1E6));
                    func_08865D84(p);
                } else if ((u8) func_08865CB8(p, 4, 5) == 0) {
                    ((V6C *) p)->vfunc_6C(4, 5, 2);
                }
            }
            r = func_08872ED4(D_08A62C7C, i);
            if (r != -1) {
                msg[1] = r;
                func_088AB6D0(D_09A1DAEC, 5, msg);
            }
        }
    }
}

}
