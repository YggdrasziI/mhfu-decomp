/* unit_088DA974: 0x088DA974-0x088DAA54 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef int s32;
typedef struct { char b[4]; } E4;

void func_088DA974(char *arg0, char *arg1, s32 arg2) {
    s32 temp_a2;
    s32 temp_a0_i;

    temp_a2 = arg2 & 0xFF;
    if (temp_a2 == 0xFF) {
        *(u8 *)(arg0 + 0x10D0) = (u8) *(u8 *)arg1;
        *(u8 *)(arg0 + 0x10D1) = (u8) *(u8 *)(arg1 + 1);
        *(u8 *)(arg0 + 0x10D2) = (u8) *(u8 *)(arg1 + 2);
        *(u8 *)(arg0 + 0x10D3) = (u8) *(u8 *)(arg1 + 3);
        *(u8 *)(arg0 + 0x10D4) = (u8) *(u8 *)(arg1 + 4);
        *(u8 *)(arg0 + 0x10D5) = (u8) *(u8 *)(arg1 + 5);
        *(u8 *)(arg0 + 0x10D6) = (u8) *(u8 *)(arg1 + 6);
        *(u8 *)(arg0 + 0x10D7) = (u8) *(u8 *)(arg1 + 7);
        *(u8 *)(arg0 + 0x10D8) = (u8) *(u8 *)(arg1 + 8);
        *(u8 *)(arg0 + 0x10D9) = (u8) *(u8 *)(arg1 + 9);
        *(u8 *)(arg0 + 0x10DA) = (u8) *(u8 *)(arg1 + 0xA);
        *(u8 *)(arg0 + 0x10DB) = (u8) *(u8 *)(arg1 + 0xB);
        *(u8 *)(arg0 + 0x10DC) = (u8) *(u8 *)(arg1 + 0xC);
        *(u8 *)(arg0 + 0x10DD) = (u8) *(u8 *)(arg1 + 0xD);
        *(u8 *)(arg0 + 0x10DE) = (u8) *(u8 *)(arg1 + 0xE);
        *(u8 *)(arg0 + 0x10DF) = (u8) *(u8 *)(arg1 + 0xF);
        *(u8 *)(arg0 + 0x10E0) = (u8) *(u8 *)(arg1 + 0x10);
        *(u8 *)(arg0 + 0x10E1) = (u8) *(u8 *)(arg1 + 0x11);
        *(u8 *)(arg0 + 0x10E2) = (u8) *(u8 *)(arg1 + 0x12);
        *(u8 *)(arg0 + 0x10E3) = (u8) *(u8 *)(arg1 + 0x13);
        return;
    }
    temp_a0_i = temp_a2;
    *(u8 *) &((E4 *) (arg0 + 0x10D0))[temp_a0_i] = (u8) *(u8 *)arg1;
    *(u8 *) &((E4 *) (arg0 + 0x10D1))[temp_a0_i] = (u8) *(u8 *)(arg1 + 1);
    *(u8 *) &((E4 *) (arg0 + 0x10D2))[temp_a0_i] = (u8) *(u8 *)(arg1 + 2);
    *(u8 *) &((E4 *) (arg0 + 0x10D3))[temp_a0_i] = (u8) *(u8 *)(arg1 + 3);
}
