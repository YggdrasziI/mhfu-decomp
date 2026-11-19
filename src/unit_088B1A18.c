/* unit_088B1A18: 0x088B1A18-0x088B1A94 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B1A04 and unit_088B1A94.
 *
 * When the record at D_09A4410C is active, runs func_088B1A94,
 * func_088B1BF8 or func_088B1C28 on it for phase 0, 1 or 2 (as
 * func_088ADF58).
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x20];
    u8 active;
    u8 phase;
} Record;

extern char D_09A4410C[];

extern void func_088B1A94(Record *);
extern void func_088B1BF8(Record *);
extern void func_088B1C28(Record *);

void func_088B1A18(void) {
    Record *r = (Record *) D_09A4410C;

    if (r->active) {
        switch (r->phase) {
        case 0:
            func_088B1A94(r);
            break;
        case 1:
            func_088B1BF8(r);
            break;
        case 2:
            func_088B1C28(r);
            break;
        }
    }
}
