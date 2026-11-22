/* unit_088816AC: 0x088816AC-0x088817E8 (ULES01213)
 *
 * C++: virtual calls through D_089CC434.
 */

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); } V18;

extern "C" {

extern V18 *D_089CC434;
extern char *D_089CC438;
extern s32 D_089AC3F4[];

s32 func_088816AC(s32 arg0, s32 arg1, s32 arg2) {
    char *p;
    s32 found;
    s32 i;
    s32 *tbl;
    s32 *q;
    s32 key;
    s32 r;

    switch (arg2) {
    case 0x19BE:
        return D_089CC434->vfunc_18(0x19BE);
    case 0x19BF:
        return D_089CC434->vfunc_18(0x19BF);
    case 0x19C3:
        return D_089CC434->vfunc_18(0x19C3);
    case 0x19C4:
        return D_089CC434->vfunc_18(0x19C4);
    }
    p = D_089CC438;
    key = *(u8 *)(p + 0x6AF10);
    found = 0;
    tbl = D_089AC3F4;
    q = D_089AC3F4 + arg1;
    for (i = 0; i < 6; i++) {
        if (*tbl == key) {
            r = q[-0x11];
            found = 1;
        }
        tbl += 4;
        q += 4;
    }
    if (!found || *(u8 *)(p + 0x480) != 0) {
        return D_089CC434->vfunc_18(arg2);
    }
    return r;
}

}
