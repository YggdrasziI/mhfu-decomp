/* unit_088B0F30: 0x088B0F30-0x088B0FAC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0EFC and unit_088B0FAC.
 *
 * When the record at D_09A4401C is active (+0x20), runs the handler of its
 * phase (+0x21), as func_088ADF58 does for D_09A43FA4.
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x20];
    u8 active;
    u8 phase;
} Record;

extern char D_09A4401C[];

extern void func_088B0FAC(Record *);
extern void func_088B11EC(Record *);
extern void func_088B11F8(Record *);

void func_088B0F30(void) {
    Record *r = (Record *) D_09A4401C;

    if (r->active) {
        switch (r->phase) {
        case 0:
            func_088B0FAC(r);
            break;
        case 1:
            func_088B11EC(r);
            break;
        case 2:
            func_088B11F8(r);
            break;
        }
    }
}
