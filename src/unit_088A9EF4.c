/* unit_088A9EF4: 0x088A9EF4-0x088A9F4C (ULES01213)
 *
 * Bounds (hypothesis): 1 function between unit_088A9E28 and unit_088A9F4C.
 *
 * Runs the session step while the session is open and in mode 1 or 2.
 */

#include "unk_peer.h"

extern void func_088A9660(Session *arg0);
extern Session D_09A1D5D0;

void func_088A9EF4(void) {
    if (D_09A1D5D0.unk1C != 0) {
        switch (D_09A1D5D0.unk20) {
        case 1:
        case 2:
            func_088A9660(&D_09A1D5D0);
            break;
        }
    }
}
