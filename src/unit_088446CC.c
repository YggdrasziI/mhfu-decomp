/* unit_088446CC: 0x088446CC-0x08844744 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_088446CC (ULES01213) */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern char *D_089CC438;

s32 func_088446CC(s32 arg0, u16 arg1) {
    switch (*(u8 *)(D_089CC438 + 0x6AF10)) {
    case 14:
    case 15:
        switch (arg1) {
        case 0x79:
        case 0x7A:
        case 0x7B:
            return 1;
        }
        return 2;
    }
    return 0;
}
