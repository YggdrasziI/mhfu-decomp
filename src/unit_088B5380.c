/* unit_088B5380: 0x088B5380-0x088B5560 (ULES01213)
 *
 * Bounds (hypothesis): 2 functions between unit_088B4FAC (NonMatching) and
 * unit_088B5560.
 *
 * Message builders on the buffer of func_088AFE78 (kinds 0x10 and 0x11),
 * as func_088B4950; func_088B5380 also passes the identifier to
 * func_088B7D78.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    s8 b[6];
} B6;

typedef struct {
    s8 b[0x12];
} B12;

typedef struct {
    s8 b[0xA0];
} BA0;

typedef struct {
    s8 b[0x14];
} Id;

typedef struct {
    B6 unk0;
    u8 unk6;
    u8 unk7;
    B12 unk8;
    u16 unk1A;
    u8 unk1C;
    u8 unk1D;
    u8 pad1E[2];
    BA0 unk20;
    u16 unkC0;
    u8 unkC2;
    u8 unkC3;
    u8 unkC4;
    u8 unkC5;
    u8 unkC6;
    u8 unkC7;
} RecC8;

extern void memset(void *, s32, s32);
extern s32 func_088AFE78(void);
extern void func_088AFE90(s32, s32);
extern void func_088AFFBC(s32, u16);
extern void func_088AFFD0(s32);
extern void func_088B0010(s32, u16);
extern s32 func_088B012C(s32);
extern void func_088B01BC(s32, RecC8 *);
extern void func_088B7D78(s32, RecC8 *, Id *);

void func_088B5380(Id *arg0, RecC8 *arg1, u16 arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x10);
    func_088AFFBC(h, arg2);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
        func_088B7D78(0, arg1, &id);
    }
    *arg0 = id;
}

void func_088B5478(Id *arg0, RecC8 *arg1, u16 arg2) {
    s32 h;
    Id id;

    h = func_088AFE78();
    memset(&id, 0, sizeof(id));
    func_088B01BC(1, arg1);
    func_088AFE90(h, 0x11);
    func_088B0010(h, arg2);
    func_088AFFD0(h);
    if (func_088B012C(h) == 0) {
        id = *(Id *) (h + 4);
    }
    *arg0 = id;
}
