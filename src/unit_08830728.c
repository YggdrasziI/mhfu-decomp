/* unit_08830728: 0x08830728-0x088307BC (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { char b[36]; } E36;

extern char *D_089CC438;

u8 func_08830728(char *arg0, s8 arg1, s16 arg2, s16 arg3) {
    s32 temp_t0_i;

    if (*(s8 *)(arg0 + 0x10F8) >= 0x13) {
        return 0xFFU;
    }
    *(u8 *)(D_089CC438 + 0x380) = (u8) ((*(u8 *)(D_089CC438 + 0x380) + 1) & 0x7F);
    temp_t0_i = (s8) ((s32) (*(s8 *)(arg0 + 0x10F9) + *(s8 *)(arg0 + 0x10F8)) % 20);
    *(s8 *) &((E36 *) (arg0 + 0xE42))[temp_t0_i] = arg1;
    *(s16 *) &((E36 *) (arg0 + 0xE44))[temp_t0_i] = arg2;
    *(u8 *) &((E36 *) (arg0 + 0xE43))[temp_t0_i] = (u8) *(u8 *)(D_089CC438 + 0x380);
    *(s16 *) &((E36 *) (arg0 + 0xE46))[temp_t0_i] = arg3;
    *(s8 *)(arg0 + 0x10F8) = (s8) (*(s8 *)(arg0 + 0x10F8) + 1);
    return *(u8 *)(D_089CC438 + 0x380);
}
