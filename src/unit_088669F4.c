/* unit_088669F4: 0x088669F4-0x08866AAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between code still in assembly.
 */

typedef int s32;
typedef unsigned char u8;

typedef struct Ent {
    u8 type;
    u8 pad[3];
    s32 val;
} Ent;

void func_088669F4(char *arg0) {
    Ent *e;
    s32 i;
    char *p4;
    char *p8;

    e = (Ent *)(arg0 + 0x800A8);
    for (i = 0, p4 = arg0, p8 = arg0; i < 48; i++, p4 += 4, p8 += 8, e++) {
        if (e->val != -1) {
            switch (e->type) {
            case 0:
                break;
            case 2:
                *(s32 *)(p4 + 0x80258) = 0;
                *(s32 *)(p4 + 0x80318) = 0;
                if (*(u8 *)(arg0 + i + 0x803D8) != 3) {
                    *(u8 *)(arg0 + i + 0x803D8) = 0;
                }
                *(u8 *)(p8 + 0x800A8) = 0;
                *(s32 *)(p8 + 0x800AC) = 0;
                break;
            }
        }
    }
}
