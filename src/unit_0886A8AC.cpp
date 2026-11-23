/* unit_0886A8AC: 0x0886A8AC-0x0886AA28 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0886A8AC */

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

/* Placeholder virtuals: only the slot at 0xF4 is called. */
typedef struct VF4 {
    virtual void vfunc_08();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
} VF4;

extern "C" {

extern char *D_089CC438;
extern u16 D_089A7EB0[];

extern char *func_0886DD3C(char *, char *);
extern u8 func_0886D8A8(char *, u8);
extern u8 func_0884FC74(char *, u8);
extern s16 func_09ACBF40(char *);
extern s32 func_08872CC0(s32, s32, s32);
extern u8 func_0886AA28(char *, char *);
extern void func_09AC7668(char *);

s32 func_0886A8AC(char *arg0, char *arg1) {
    char *p;
    u16 lim;

    p = func_0886DD3C(arg0, arg1);
    if (p != 0) {
    if (*(s16 *)(p + 0x2E) & 1) {
        return 0;
    }
    *(s16 *)(p + 0x2E) = 2;
    if (func_0886D8A8(arg0, *(u8 *)(arg1 + 0x1E8)) == 1) {
        *(u16 *)(arg1 + 0x274) += 5;
        lim = D_089A7EB0[func_0884FC74(D_089CC438, *(u8 *)(arg1 + 0x1E8))];
        if (lim < *(u16 *)(arg1 + 0x274)) {
            *(u16 *)(arg1 + 0x274) = lim;
        }
        *(s16 *)(arg1 + 0x5F4) = func_09ACBF40(arg1);
        if (!(*(s32 *)(arg0 + 0x28) & 0x8000)) {
            *(s8 *)(arg1 + 0x4BC) = func_08872CC0((s32)arg0, *(s8 *)(arg1 + 0x4BC), 1);
        }
    }
    *(s16 *)(p + 0x32) = *(s16 *)(arg1 + 0x2E4);
    switch (*(s8 *)(p + 0xB)) {
    case 1:
        if (func_0886AA28(arg0, arg1) == 1) {
            break;
        }
    case 0:
    default:
        *(float *)(arg1 + 0x200) = *(float *)(p + 0x20);
        *(float *)(arg1 + 0x204) = *(float *)(p + 0x24);
        *(float *)(arg1 + 0x208) = *(float *)(p + 0x28);
        *(s32 *)(arg1 + 0x1F4) = *(s32 *)(p + 0x1C);
        break;
    }
    *(u16 *)(arg1 + 0x29A) = *(u16 *)(p + 0x8);
    ((VF4 *)arg1)->vfunc_F4();
    func_09AC7668(arg1);
    return *(s8 *)(p + 0x4);
    }
    return 0;
}

}
