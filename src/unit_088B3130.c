/* unit_088B3130: 0x088B3130-0x088B31AC (ULES01213)
 *
 * Bounds (hypothesis): 1 function between matched units.
 */

typedef unsigned char u8;
typedef int s32;

typedef struct {
    char unk0[0x20];
    u8 unk20;
    u8 unk21;
} State;

extern char D_09A4406C[];

extern void func_088B31AC(char *);
extern void func_088B32A0(s32);
extern void func_088B32AC(char *);

void func_088B3130(void) {
    State *p = (State *) D_09A4406C;

    if (p->unk20 != 0) {
        switch (p->unk21) {
        case 0:
            func_088B31AC((char *) p);
            break;
        case 1:
            func_088B32A0((s32) p);
            break;
        case 2:
            func_088B32AC((char *) p);
            break;
        }
    }
}
