/* unit_088CE298: 0x088CE298-0x088CE754 (ULES01213)
 *
 * Bounds (hypothesis): 3 functions between unit_088CE1AC and unit_088CE754.
 *
 * Set-up of an object from the 0x8C-byte record of its slot (index at +0x1E6)
 * in D_089CC438, reset of its animation state, and a 16 x 3 update loop.
 *
 * C++: member-wise structure copies, a bool comparison and virtual calls.
 * Optimized for speed: the 32-byte clear is unrolled by 8.
 */

#pragma optimize_for_size off

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef struct S3 {
    s16 x;
    s16 y;
    s16 z;
} S3;

typedef struct Item {
    u8 unk0;
    u8 unk1;
    u16 unk2;
    u16 unk4;
    S3 unk6;
} Item;

typedef struct Sub30 {
    char pad0[0x10];
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    char unk15[0x17];
    s32 unk2C;
    Item unk30;
    Item unk3C[5];
} Sub30;

typedef struct Obj {
    char pad0[0x2FF];
    u8 unk2FF[0x20];
    char pad31F[0x1D5];
    Item unk4F4[5];
} Obj;

typedef struct V20 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual s32 vfunc_20(u16); } V20;

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62C54;
extern char *D_08A62C58;
extern char *D_09A4F060;
extern char D_09CE10A0[];

extern s32 func_0885187C(char *, s32, u32);
extern s32 func_08851F20(char *, s32);
extern u8 func_0885CCD0(s32, u16);
extern u8 func_0885CDB8(s32, char *);
extern u8 func_0885CE00(s32, u8);
extern u8 func_0885CE1C(s32, u8);
extern void func_08860CB0(char *, char *, char *, s32);
extern void func_08863E70(char *, s32, s32, s32, s32);
extern void func_08864554(char *);
extern void func_088CF210(char *, s32);
extern void func_088D2894(char *);
extern void func_088D2C14(char *);
extern void func_088D2E04(char *);
extern void func_088D3A84(char *);
extern void func_088D5B54(u8 *);
extern void func_088D5C74(char *, s32, s32, s32);
extern void func_088D897C(char *);
extern void func_088DA2C4(char *);
extern void func_088DA940(char *, char *);
extern void func_088DA974(char *, char *, s32);
extern void func_088DAD58(char *, s32);
extern void func_09C57BA0(char *, s32);

void func_088CE298(char *arg0) {
    s32 i;
    s32 j;
    char *rec;
    Sub30 *p;

    func_08864554(arg0);
    *(s32 *)(arg0 + 0x1C0) = 2;
    func_088DA2C4(arg0);
    *(u8 *)(arg0 + 0x68E) = 0xFF;
    *(u8 *)(arg0 + 0x298) = 0;
    *(u8 *)(arg0 + 0x299) = 0;
    *(u8 *)(arg0 + 0x460) = *(u8 *)(arg0 + 0x298);
    *(u8 *)(arg0 + 0x461) = *(u8 *)(arg0 + 0x299);
    *(u8 *)(arg0 + 0x2C8) = 1;
    *(u8 *)(arg0 + 0x3D0) = 0xFF;
    *(s32 *)(arg0 + 0x614) |= 0x400;
    *(s16 *)(arg0 + 0x41E) = 0x64;
    *(s16 *)(arg0 + 0x2E4) = 0x64;
    *(s16 *)(arg0 + 0x62E) = 0x12C;
    *(u16 *)(arg0 + 0x29A) = *(u16 *)(D_089CC438 + 0x6AF0E);
    func_088DA940(arg0, D_09CE10A0 + *(u16 *)(D_09A4F060 + 0x288) * 0x10);
    *(u16 *)(arg0 + 0x320) = *(s32 *)(arg0 + 0x1F4);
    for (i = 0; i < 0x20; i++) {
        (arg0 + i)[0x2FF] = 0;
    }
    rec = D_089CC438 + *(u16 *)(arg0 + 0x1E6) * 0x8C;
    p = (Sub30 *) (rec + 0x30);
    *(u8 *)(arg0 + 0x4E0) = p->unk10;
    *(u8 *)(arg0 + 0x4E1) = p->unk11;
    *(s32 *)(arg0 + 0x4E4) = p->unk2C;
    *(Item *)(arg0 + 0x4E8) = p->unk30;
    for (j = 0; j < 5; j++) {
        ((Obj *) arg0)->unk4F4[j] = p->unk3C[j];
    }
    *(u8 *)(arg0 + 0x530) = p->unk12;
    *(u8 *)(arg0 + 0x531) = p->unk13;
    *(u8 *)(arg0 + 0x532) = p->unk14;
    *(u16 *)(arg0 + 0x53A) = func_0885187C(D_089CC438, *(u16 *)(arg0 + 0x1E6), 2);
    *(u16 *)(arg0 + 0x534) = func_08851F20(D_089CC438, *(u16 *)(arg0 + 0x1E6));
    *(u8 *)(arg0 + 0x1E8) = func_0885CCD0(D_08A62C54, *(u16 *)(arg0 + 0x534));
    *(u8 *)(arg0 + 0x55C) = 0;
    *(s16 *)(arg0 + 0x646) = 0x63;
    *(u8 *)(arg0 + 0x67D) = 0xA;
    func_088D5C74(arg0, 1, 0, 0);
    *(u16 *)(arg0 + 0x682) = 0;
    *(u16 *)(arg0 + 0x684) = 0xFFFF;
    func_09C57BA0(arg0, 1);
    func_088D897C(arg0);
    if ((*(u16 *)(arg0 + 0x1E6) == *(u8 *)(D_089CC438 + 0x28)) == 1) {
        func_088DA974(arg0, D_089CC438 + 0x6AC3E, 0xFF);
    } else {
        func_088DA974(arg0, p->unk15, 0xFF);
    }
    func_088D3A84(arg0);
    *(float *)(arg0 + 0x69C) = 1.0f;
    *(u8 *)(arg0 + 0x5F3) = func_0885CE00(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    *(u8 *)(arg0 + 0x5F5) = func_0885CDB8(D_08A62C54, arg0 + 0x4E8);
    *(u8 *)(arg0 + 0x5F4) = func_0885CE1C(D_08A62C54, *(u8 *)(arg0 + 0x1E8));
    func_088D2C14(arg0);
    func_088DAD58(arg0, *(u16 *)(arg0 + 0x534));
    func_088D5B54((u8 *) arg0);
    func_088CF210(arg0, *(u8 *)(arg0 + 0x612));
}

static inline void copy_quad(float *src, float *dst) {
    asm {
        lv.q C000, 0(src)
        sv.q C000, 0(dst)
    }
}

void func_088CE5D4(char *arg0) {
    s32 i;

    *(s32 *)(arg0 + 0x1D4) = 0;
    *(u16 *)(arg0 + 0x1D8) = 0;
    *(s32 *)(arg0 + 0x614) &= ~0x180;
    *(float *)(arg0 + 0x220) = 1.0f;
    *(float *)(arg0 + 0x224) = 1.0f;
    *(float *)(arg0 + 0x228) = 1.0f;
    *(float *)(arg0 + 0x94) = 2.0f;
    *(float *)(arg0 + 0xD4) = 2.0f;
    *(float *)(arg0 + 0x650) = 0.0f;
    *(float *)(arg0 + 0x654) = 0.0f;
    *(float *)(arg0 + 0x658) = 0.0f;
    *(float *)(arg0 + 0x65C) = 0.0f;
    copy_quad((float *)(arg0 + 0x650), (float *)(arg0 + 0x660));
    *(u16 *)(arg0 + 0x670) = 0;
    for (i = 0; i < 4; i++) {
        *(u8 *)(arg0 + 0x1A8 + i) = 0;
        ((u16 *)(arg0 + 0x1B8))[i] = 0;
        ((u16 *)(arg0 + 0x1B0))[i] = 0;
    }
    *(u8 *)(arg0 + 0x67E) = 0;
    func_08863E70(arg0 + 0x80, ((V20 *) arg0)->vfunc_20(*(u16 *)(arg0 + 0x324)), *(u16 *)(arg0 + 0x32C), 0, 0);
    func_08863E70(arg0 + 0x80, ((V20 *) arg0)->vfunc_20(*(u16 *)(arg0 + 0x326)), *(u16 *)(arg0 + 0x32E), 0, 1);
    func_088D2894(arg0);
}

void func_088CE6DC(char *arg0) {
    char buf[4];
    s32 i;
    s32 j;

    i = 0;
    do {
        func_088D2E04(arg0);
        j = 0;
        do {
            func_08860CB0(buf, D_08A62C58, arg0, j);
            j++;
        } while (j < 3);
        i++;
    } while (i < 0x10);
}

}
