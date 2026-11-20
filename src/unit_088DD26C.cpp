/* unit_088DD26C: 0x088DD26C-0x088DD3A8 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088DD264 and unit_088DD3A8.
 *
 * Draws the object: func_08860B24 / func_08860EC0, five GE commands, its
 * virtual function at 0x4C, the one at 0x78 when bit 0x400 of the flags at
 * +0x614 is set, then func_08860C54 / func_08861184.
 *
 * C++: virtual calls and bool conversion.
 */

typedef int s32;

typedef struct VObj { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); } VObj;

extern "C" {

extern s32 *D_089CC000;
extern s32 D_08A62C58;

extern void func_08860B24(s32, char *);
extern void func_08860C54(s32);
extern void func_08860EC0(s32, char *);
extern void func_08861184(s32, s32);

void func_088DD26C(char *arg0) {
    func_08860B24(D_08A62C58, arg0);
    func_08860EC0(D_08A62C58, arg0);
    *D_089CC000 = 0x23000001;
    D_089CC000++;
    *D_089CC000 = 0xDE000005;
    D_089CC000++;
    *D_089CC000 = 0xC6000107;
    D_089CC000++;
    *D_089CC000 = 0x22000001;
    D_089CC000++;
    *D_089CC000 = 0xDBFFC007;
    D_089CC000++;
    ((VObj *) arg0)->vfunc_4C();
    if ((bool) (*(s32 *)(arg0 + 0x614) & 0x400) == 1) {
        ((VObj *) arg0)->vfunc_78();
    }
    func_08860C54(D_08A62C58);
    func_08861184(D_08A62C58, 1);
}

}
