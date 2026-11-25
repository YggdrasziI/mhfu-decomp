/* unit_0884953C: 0x0884953C-0x088495AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

/* func_0884953C (ULES01213) */

typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;

extern char *D_089CC438;

s32 func_0884953C(char *arg0) {
    *(u8 *)(arg0 + 0x57F) = 0;
    *(s32 *)(arg0 + 0x5E8) |= 4;
    *(u8 *)(arg0 + 0x5FE) = 3;
    *(s16 *)(arg0 + 0x5FC) = 0;
    switch (*(s8 *)(D_089CC438 + 0x6ADD9)) {
    case 1:
        *(u8 *)(arg0 + 0x5E4) = 0;
        break;
    case 2:
        *(u8 *)(arg0 + 0x5E4) = 1;
        break;
    case 3:
        *(u8 *)(arg0 + 0x5E4) = 2;
        break;
    }
    return 0;
}
