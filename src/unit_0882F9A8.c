/* unit_0882F9A8: 0x0882F9A8-0x0882FA24 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 * Builds a box from the template arg1 (func_0882FA24, no offsets) in a
 * stack buffer, then draws it with func_0882F580 and the other arguments.
 */

typedef int s32;

typedef struct {
    char data[0x28];
} Box;

extern void func_0882FA24(Box *, char *, char *, s32, s32);
extern void func_0882F580(char *, Box *, char *, s32, s32, s32);

void func_0882F9A8(char *arg0, char *arg1, char *arg2, s32 arg3, s32 arg4, s32 arg5)
{
    Box box;

    func_0882FA24(&box, arg1, arg2, 0, 0);
    func_0882F580(arg0, &box, arg2, arg3, arg4, arg5);
}
