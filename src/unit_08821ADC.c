/* unit_08821ADC: 0x08821ADC-0x08821B58 (ULES01213)
 *
 * Bounds (hypothesis): 1 small function between code still in assembly.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

typedef struct {
    s16 a;
    s16 b;
    s16 c;
} Tri;

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    u16 h4;
    Tri t;
} Ent;

typedef struct {
    char pad[0x4F4];
    Ent ent[1];
} Owner;

extern void func_088D897C(Owner *);

void func_08821ADC(char *arg0, Owner *arg1, Ent *arg2) {
    Ent *e = &arg1->ent[arg2->b1];

    e->b0 = arg2->b0;
    e->b1 = arg2->b1;
    e->h2 = arg2->h2;
    e->h4 = arg2->h4;
    e->t = arg2->t;
    func_088D897C(arg1);
    arg0[0x1206] = 1;
}
