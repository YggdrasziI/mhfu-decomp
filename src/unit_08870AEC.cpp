/* unit_08870AEC: 0x08870AEC-0x08870D30 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly and
 * unit_08870D30.
 *
 * C++: virtual calls. Optimized for speed: divisions by a constant are
 * multiplications.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct V38_0 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual s32 vfunc_18(u16); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(u16, s32, s32, s32, s32, s32); virtual s32 vfunc_38(); } V38_0;

extern "C" {

extern u16 **D_089A7CE8[];
extern char D_08A5C440;
extern V38_0 *D_089CC434;
extern s32 D_09A0B540;
extern s32 D_09A44C60;

extern s32 func_08898694(s32, s32, s32);
extern void func_08898748(s32, s32);
extern s32 func_08898898(s32, s32);
extern void func_088C2BE0(s32, char *, s32);

u8 func_08870AEC(char *arg0, u16 arg1, char *arg2) {
    u8 ret = 0;

    switch (*(u8 *)(arg0 + 0x716)) {
    case 0: {
        s32 id = arg1;

        if (id < 60000) {
            s32 group;
            u16 **table;
            u16 *row;
            u16 file;

            if (id <= 9999) {
                group = id / 1000;
            } else if (id <= 19999) {
                group = (id - 10000) / 1000 + 5;
            } else if (id <= 29999) {
                group = (id - 20000) / 1000 + 7;
            } else if (id < 40000) {
                group = 10;
            } else if (id < 50000) {
                group = 11;
            } else {
                group = 12;
            }
            /* Each level is its own pointer step: the table and the row are
             * loaded before the index terms that follow them. */
            table = D_089A7CE8[group];
            table += id % 1000 / 100;
            row = *table;
            row += id % 100;
            file = *row;
            if (*(u16 *)(arg0 + 0x714) != file) {
                D_089CC434->vfunc_34(file, func_08898694(D_09A0B540, 0x17, 0x6800), -1, 0, 0, 1);
                *(u16 *)(arg0 + 0x714) = file;
                (*(u8 *)(arg0 + 0x716))++;
            } else {
                ret = 1;
            }
        } else {
            ret = 1;
        }
        break;
    }
    case 1:
        if (D_089CC434->vfunc_38() == 0) {
            if (arg2 == 0) {
                arg2 = &D_08A5C440;
            }
            func_088C2BE0(D_09A44C60, arg2, func_08898898(D_09A0B540, 0x17));
            func_08898748(D_09A0B540, 0x17);
            *(u8 *)(arg0 + 0x716) = 0;
            ret = 1;
        }
        break;
    }
    return ret;
}

}