/* unit_088BA704: 0x088BA704-0x088BA760 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern u16 D_089AD050;
extern s32 D_089CC438;
extern s32 D_08A631A8;
extern void *func_0885151C(int, u16);
extern int func_08892148(s32, s16, s16, s32, char *);

void func_088BA704(s32 arg0, s32 arg1) {
    func_08892148(D_08A631A8, arg0, arg1, 0, func_0885151C(D_089CC438, D_089AD050));
}
