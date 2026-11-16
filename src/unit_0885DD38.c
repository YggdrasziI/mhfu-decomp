/* unit_0885DD38: 0x0885DD38-0x0885DD9C (ULES01213)
 *
 * NonMatching: compiled for the report only, the code is linked from assembly.
 * Bounds (hypothesis): 1 function between two functions still in assembly. Its
 * jump table is 0x08931584-0x089315A0.
 */

typedef int s32;
typedef unsigned char u8;

extern s32 func_0885EBC8(s32, u8 *);
extern s32 func_0885ECF4(s32, u8 *);

/* 97.0 %: after each call the original has `b end; nop` to the `lw ra` of the
 * epilogue; ours branches one instruction further with the `lw ra` copied into
 * the delay slot. Tried: a result variable, `return 0` after the switch, s32 /
 * u8 / float return types, void calls with a missing return, explicit
 * arguments. */
s32 func_0885DD38(s32 arg0, u8 *arg1) {
    switch (arg1[1]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return func_0885EBC8(arg0, arg1);
    case 5:
    case 6:
        return func_0885ECF4(arg0, arg1);
    default:
        return 0;
    }
}
