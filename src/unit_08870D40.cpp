/* unit_08870D40: 0x08870D40-0x08870E88 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V18_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual u32 vfunc_18(u16); } V18_0;

extern "C" {

extern V18_0 *D_089CC434;
extern s32 D_09A4F0D0;

extern void func_088DE0B8(s32, s32, u32, s32);

void func_08870D40(char *arg0) {
    s32 i;
    s32 j;
    s32 k;
    u32 *m;
    char *p;
    u32 *m2;
    u8 *s;
    u32 max[2];
    u8 seen[2];

    for (i = 0, m = max, p = arg0; i < 2; i++, m++, p += 0x2C) {
        *m = 0;
        for (j = 0; j < *(s8 *)(p + 0x786); j++) {
            u32 size = D_089CC434->vfunc_18(*(u8 *)(p + 0x77C + j) + 0x17DF);
            if (*m < size) {
                *m = size;
            }
        }
    }
    for (k = 0, m2 = max, s = seen; k < 2; k++, arg0 += 0x2C, m2++, s++) {
        if (*(s8 *)(arg0 + 0x786) > 0) {
            s32 ok = 1;
            s32 n;
            for (n = 0; n < k; n++) {
                if (seen[n] == *(s8 *)(arg0 + 0x77C)) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                func_088DE0B8(D_09A4F0D0, *(u8 *)(arg0 + 0x77C), *m2, k);
                *s = *(s8 *)(arg0 + 0x77C);
            }
        }
    }
}

}
