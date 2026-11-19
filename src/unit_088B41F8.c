/* unit_088B41F8: 0x088B41F8-0x088B4274 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B41EC and unit_088B4274.
 *
 * Dispatches the phase of the record D_09A440BC (as func_088B3130).
 */

typedef unsigned char u8;

typedef struct {
    char unk0[0x20];
    u8 unk20;
    u8 unk21;
} State;

extern char D_09A440BC[];

extern void func_088B4274(char *);
extern void func_088B455C(char *);
extern void func_088B45B0(char *);

void func_088B41F8(void) {
    State *p = (State *) D_09A440BC;

    if (p->unk20 != 0) {
        switch (p->unk21) {
        case 0:
            func_088B4274((char *) p);
            break;
        case 1:
            func_088B455C((char *) p);
            break;
        case 2:
            func_088B45B0((char *) p);
            break;
        }
    }
}
