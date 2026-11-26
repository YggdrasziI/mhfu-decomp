/* unit_088307BC: 0x088307BC-0x08830850 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef struct { char b[36]; } E36;

extern char *D_089CC438;

u8 func_088307BC(char *arg0, char *arg1) {
    s32 temp_t0_i;

    if (*(s8 *)(arg0 + 0x10F8) >= 0x13) {
        return 0xFFU;
    }
    *(u8 *)(D_089CC438 + 0x380) = (u8) ((*(u8 *)(D_089CC438 + 0x380) + 1) & 0x7F);
    temp_t0_i = (s8) ((s32) (*(s8 *)(arg0 + 0x10F9) + *(s8 *)(arg0 + 0x10F8)) % 20);
    *(u8 *) &((E36 *) (arg0 + 0xE43))[temp_t0_i] = (u8) *(u8 *)(D_089CC438 + 0x380);
    *(u8 *) &((E36 *) (arg0 + 0xE42))[temp_t0_i] = 0xFF;
    *(char **) &((E36 *) (arg0 + 0xE48))[temp_t0_i] = arg1;
    *(s8 *)(arg0 + 0x10F8) = (s8) (*(s8 *)(arg0 + 0x10F8) + 1);
    return *(u8 *)(D_089CC438 + 0x380);
}
