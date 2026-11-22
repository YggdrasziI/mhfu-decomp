/* unit_0889BEC0: 0x0889BEC0-0x0889BF08 (ULES01213)
 *
 * Bounds (hypothesis): 1 function between neighbouring units.
 */

/* func_0889BEC0: takes a 0x14-byte record by value and passes its address on. */

#pragma optimize_for_size off

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
} Rec14;

extern void func_0889B1A4(Rec14 *arg0);

void func_0889BEC0(Rec14 arg0) {
    func_0889B1A4(&arg0);
}
