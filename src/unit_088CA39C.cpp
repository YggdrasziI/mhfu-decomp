/* unit_088CA39C: 0x088CA39C-0x088CA508 (ULES01213)
 *
 * Bounds (hypothesis): the whole text_088CA39C asm piece, 1 function
 * between unit_088CA2E0 and unit_088CA508.
 *
 * C++: virtual calls (record table at vtable offset 0xB0, count at 0xAC,
 * as unit_088CA944). Registers each 0x20-byte record.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct Rec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    char unk10[0x10];
} Rec;

typedef struct List {
    virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8();
    virtual s32 vfunc_AC();
    virtual Rec *vfunc_B0();
} List;

extern "C" {

extern char *D_089CC438;
extern s32 D_08A62D8C;
extern s32 D_09A4F060;
extern s32 D_09A4F06C;
extern s32 func_0884FA5C(char *, s32);
extern s32 func_088CDEDC(s32, s32, s32);
extern void func_08885494(s32, s32, s32, s32, s32);
extern s32 func_088C6BCC(s32, s32, s32, s32, s32, s32, char *, s32);
extern s32 func_08883B54(s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32);

void func_088CA39C(List *arg0) {
    s32 i;
    Rec *rec;

    rec = arg0->vfunc_B0();
    i = 0;
    if (arg0->vfunc_AC() > 0) {
        do {
            if ((bool) (*(s32 *)(D_089CC438 + 0x6AF14) & 1) == 0 && (u8) func_0884FA5C(D_089CC438, 0) == 1) {
                func_08885494(D_08A62D8C, rec->unk4, 0xC0, i + 1, 0);
            } else if ((u8) func_088CDEDC(D_09A4F06C, rec->unk8, 0) == 0) {
                if (rec->unk0 == 0) {
                    func_088C6BCC(D_09A4F060, rec->unk4, rec->unk8, 0, 0xC0, i + 1, rec->unk10, rec->unkC);
                } else {
                    func_08883B54(D_08A62D8C, rec->unk4, rec->unk8, 0, 0xC0, i + 1, rec->unk10, rec->unkC, 0, 0, 0);
                }
            }
            i++;
            rec++;
        } while (i < arg0->vfunc_AC());
    }
}

}
