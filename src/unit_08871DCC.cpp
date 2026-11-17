/* unit_08871DCC: 0x08871DCC-0x08872108 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08870D40 and text_08872108). Sibling of func_0887221C.
 *
 * C++: virtual call. Optimized for speed. The arrays are written at [count]
 * and read at [i]: the original keeps a pointer for each.
 */

#pragma optimize_for_size off

typedef int s32;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct V18 { virtual void vfunc_08(); virtual void vfunc_0C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual u32 vfunc_18(u16); } V18;

extern "C" {

extern s32 D_08A62D8C;
extern V18 *D_089CC434;
extern u16 D_09BC8400[][3];
extern s16 D_089A8278[][2];

extern s32 *func_08869774(char *, s32);
extern void func_08880CF8(s32, s32);
extern void func_08880D64(s32, s32, u16, u16, u16, u8, s32);
extern u8 func_08880D94(s32, u16 *, s32);
extern void func_08880E50(s32, s16 (*)[2], u16 *, u16 *, u16 *, u8 *, s32, s32, s32);

void func_08871DCC(char *arg0) {
    u16 a[4];
    u16 b[4];
    u16 c[4];
    u8 ids[4];
    u32 vals[4];
    s32 count = 0;
    s32 *list;
    s32 i;
    s32 k;
    s32 j;
    u8 flag;
    u32 v;

    list = func_08869774(arg0, 0);
    for (j = 0; j < 4; j++) {
        ids[j] = 0;
        vals[j] = 0;
        a[j] = 0xFFFF;
        b[j] = 0xFFFF;
        c[j] = 0xFFFF;
    }
    if (list == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (list[i] == -1) {
            break;
        }
        func_08880CF8(D_08A62D8C, i);
        a[count] = D_09BC8400[list[i]][0];
        b[count] = D_09BC8400[list[i]][1];
        c[count] = D_09BC8400[list[i]][2];
        ids[count] = list[i];
        func_08880D64(D_08A62D8C, D_089A8278[i][0], a[i], b[i], c[i], ids[i], i);
        count++;
    }
    if (count <= 0) {
        return;
    }
    if (ids[0] == ids[1]) {
        count--;
    }
    func_08880D94(D_08A62D8C, a, 0);
    flag = func_08880D94(D_08A62D8C, b, 1);
    func_08880D94(D_08A62D8C, c, 2);
    for (k = 0; k < count; k++) {
        for (j = 0; j < *(s8 *)(arg0 + k * 0x2C + 0x786); j++) {
            v = D_089CC434->vfunc_18(D_09BC8400[*(s8 *)(arg0 + k * 0x2C + 0x77C + j)][1]);
            if (vals[k] < v) {
                vals[k] = v;
            }
        }
        if (k == 1 && flag) {
            vals[k] = 0;
        }
    }
    func_08880E50(D_08A62D8C, D_089A8278, a, b, c, ids, count, 0, (s32) vals);
    *(s16 *)(arg0 + 0x5C0) = count;
}

}