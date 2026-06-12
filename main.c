#include <stdint.h>
#include "tm4c123gh6pm_registers.h"
#include "periph_configs.h"

int main(void)
{
    enable_clock (SSI, 2);
    set_ssi_portenable (2, DISABLED);
    set_ssi_ctrltype (2, MASTER);
    set_ssi_clksource (2, SYSTEM);
    set_ssi_clkmultiplier (2, 0);
    set_ssi_clkphase (2, FIRST_EDGE);
    set_ssi_clkpolarity (2, STEADY_STATE_LOW);
    set_ssi_frameformat (2, FREESCALE);
    set_ssi_datasize (2, 16);
    set_ssi_portenable (2, ENABLED);

	return 0;
}
