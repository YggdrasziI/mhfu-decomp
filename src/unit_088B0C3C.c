/* unit_088B0C3C: 0x088B0C3C-0x088B0C68 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0B14 and unit_088B0C68.
 *
 * Stores the pair arg1 / arg2 in slot arg0 of the tables D_09A44BB4 and
 * D_09A44C08.
 */

typedef unsigned short u16;
typedef int s32;

extern s32 D_09A44BB4[];
extern s32 D_09A44C08[];

void func_088B0C3C(u16 arg0, s32 arg1, s32 arg2) {
    D_09A44BB4[arg0] = arg1;
    D_09A44C08[arg0] = arg2;
}
