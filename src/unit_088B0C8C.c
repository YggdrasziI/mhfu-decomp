/* unit_088B0C8C: 0x088B0C8C-0x088B0D2C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088B0C68 and unit_088B0D2C.
 *
 * Replaces the 0xA4-byte session body (D_09A2889C and D_09A20210) with
 * arg0, copies it into the slot of the console (func_088AFA2C with
 * D_09A201F0) and passes it on (func_088B158C, reply dropped). Returns 0.
 */

typedef signed char s8;
typedef short s16;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s16 h[0x52];
} Body;

typedef struct {
    s8 b[0x14];
} Id;

extern Body D_09A2889C;
extern Body D_09A20210;
extern u8 D_09A201F0[];

extern void func_088AFA2C(u8 *, Body *);
extern void func_088B158C(Id *, Body *);

s32 func_088B0C8C(Body *arg0) {
    Id id;

    D_09A2889C = *arg0;
    D_09A20210 = *arg0;
    func_088AFA2C(D_09A201F0, arg0);
    func_088B158C(&id, arg0);
    return 0;
}
