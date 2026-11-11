/* unit_088A0938: 0x088A0938-0x088A0958 (ULES01213)
 *
 * Bounds (hypothesis): one function between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u16 a, b, c, d;
    int e;
    u16 f;
} Obj;

void func_088A0938(Obj *o) {
    o->a = 0xFFF;
    o->b = 0xFFF;
    o->d = 0xFFF;
    o->c = 0;
    o->e = 0;
    o->f = 0;
}
