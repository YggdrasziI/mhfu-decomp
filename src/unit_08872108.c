/* unit_08872108: 0x08872108-0x0887221C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_08871DCC and unit_0887221C,
 * same family.
 *
 * The slot is read as an array element (`addu index, base`); D_09BC8402 and
 * D_09BC8404 are the second and third columns of D_09BC8400, declared apart as
 * splat names them.
 */

#pragma optimize_for_size off

typedef int s32;
typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char b[0x2C];
} Blk;

extern s32 D_08A62D8C;
extern u16 D_09BC8400[][3];
extern u16 D_09BC8402[][3];
extern u16 D_09BC8404[][3];
extern s16 D_089A8278[][2];

extern void func_08880CF8(s32, s32);
extern void func_08880D64(s32, s32, u16, u16, u16, u8, s32);
extern void func_08881114(s32, s32, u16, u16, u16, u8, s32);

void func_08872108(char *arg0, s32 arg1) {
    u16 a;
    u16 b;
    u16 c;
    u8 id;
    s32 k;

    k = (u8) arg1;
    id = ((Blk *) (arg0 + 0x77C))[k].b[*(s8 *) &((Blk *) (arg0 + 0x787))[k]];
    func_08880CF8(D_08A62D8C, k);
    a = D_09BC8400[id][0];
    b = D_09BC8402[id][0];
    c = D_09BC8404[id][0];
    func_08880D64(D_08A62D8C, D_089A8278[k][0], a, b, c, id, k);
    func_08881114(D_08A62D8C, *(s32 *)D_089A8278[k], a, b, c, id, k);
}