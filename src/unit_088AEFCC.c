/* unit_088AEFCC: 0x088AEFCC-0x088AF020 (ULES01213)
 *
 * Bounds (hypothesis): small tests and getters on globals between unrelated code.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 D_09A202DE;
extern u16 D_09A202E0;
extern signed char D_09A202E4;
extern u16 D_09A202E6;

int func_088AEFCC(u8 v) { return D_09A202DE != v; }
int func_088AEFE4(signed char v) { return D_09A202E4 != v; }
u16 func_088AEFFC(void) { return D_09A202E6; }
int func_088AF008(u16 v) { return D_09A202E0 != v; }
