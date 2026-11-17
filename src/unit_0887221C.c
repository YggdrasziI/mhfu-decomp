/* unit_0887221C: 0x0887221C-0x08872444 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly
 * (text_08870D40 and text_08872444).
 *
 * Optimized for speed: the clearing loop is unrolled and the main loop walks
 * the four arrays through pointers. The byte array is written last in the
 * loop body: written first, its pointer takes another saved register.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

extern s32 D_08A62D8C;
extern char *D_09A4F0D0;
extern u16 D_09BC8400[][3];
extern s16 D_089A8278[][2];

extern void func_08880CF8(s32, s32);
extern void func_08880D64(s32, s32, u16, u16, u16, u8, s32);
extern void func_08880D94(s32, u16 *, s32);
extern void func_08880E50(s32, s16 (*)[2], u16 *, u16 *, u16 *, u8 *, s32, s32, s32);

void func_0887221C(char *arg0) {
    u16 a[4];
    u16 b[4];
    u16 c[4];
    u8 ids[4];
    s32 j;
    s32 count = 0;
    s32 i;
    u16 id;
    char *rec;
    u8 k;

    for (j = 0; j < 4; j++) {
        ids[j] = 0;
        a[j] = 0xFFFF;
        b[j] = 0xFFFF;
        c[j] = 0xFFFF;
    }
    for (i = *(s16 *)(arg0 + 0x5C0); i < 4; i++) {
        func_08880CF8(D_08A62D8C, i);
        rec = D_09A4F0D0 + i * 12;
        if (*(u16 *)(rec + 0x6C) & 3) {
            id = *(u16 *)(rec + 0x6E);
        } else {
            id = 0xFFFF;
        }
        if (id != 0xFFFF) {
            k = id - 0x17DF;
            a[i] = D_09BC8400[k][0];
            b[i] = D_09BC8400[k][1];
            c[i] = D_09BC8400[k][2];
            ids[i] = k;
            func_08880D64(D_08A62D8C, D_089A8278[i][0], a[i], b[i], c[i], ids[i], i);
            count++;
        }
    }
    if (count > 0) {
        func_08880D94(D_08A62D8C, a, 0);
        func_08880D94(D_08A62D8C, b, 1);
        func_08880D94(D_08A62D8C, c, 2);
        func_08880E50(D_08A62D8C, D_089A8278, a, b, c, ids, *(s16 *)(arg0 + 0x5C0) + count, 1, 0);
    }
}