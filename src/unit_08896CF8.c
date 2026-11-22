/* unit_08896CF8: 0x08896CF8-0x08896D24 (ULES01213) */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

extern u8 *D_089B1630[];

/* Byte 1 of the 2-byte entry arg2 of the table D_089B1630[arg1]. */
u8 func_08896CF8(s32 arg0, u8 arg1, u8 arg2) {
    return *(u8 *) ((s32) D_089B1630[arg1] + (u32) (arg2 * 2) + 1);
}
