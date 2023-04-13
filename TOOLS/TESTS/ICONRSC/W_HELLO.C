#include <p_std.h>
#include <wlib.h>

GLDEF_C INT main(VOID)
    {
    WS_EV event;

    wStartup();
    gBorder(W_BORD_CORNER_4);
    wSetBusyMsg("Hello world",W_CORNER_BOTTOM_LEFT);
    do
        {
        wGetEventWait(&event);
        } while (event.type!=WM_KEY || event.p.key.keycode!=W_KEY_ESCAPE);
    return(0);
    }
