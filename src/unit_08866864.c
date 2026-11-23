/* unit_08866864: 0x08866864-0x0886691C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

#pragma optimize_for_size off
typedef unsigned char u8;
typedef int s32;

typedef struct {
    u8 type;
    u8 pad[3];
    s32 value;
} Entry;

void func_08866864(char *arg0) {
    Entry *e = (Entry *)(arg0 + 0x800A8);
    s32 i;

    for (i = 0; i < 0x30; i++, e++) {
        if (e->value == -1) {
            continue;
        }
        switch (e->type) {
        case 0:
            break;
        case 1:
            *(s32 *)(arg0 + 0x80258 + i * 4) = 0;
            *(s32 *)(arg0 + 0x80318 + i * 4) = 0;
            if (*(u8 *)(arg0 + 0x803D8 + i) != 3) {
                *(u8 *)(arg0 + 0x803D8 + i) = 0;
            }
            *(u8 *)(arg0 + 0x800A8 + i * 8) = 0;
            *(s32 *)(arg0 + 0x800AC + i * 8) = 0;
            break;
        }
    }
}
