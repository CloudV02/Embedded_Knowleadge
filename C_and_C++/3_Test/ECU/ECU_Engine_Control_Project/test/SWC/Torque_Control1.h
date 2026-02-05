#ifndef __TORQUE_CONTROL__
#define __TORQUE_CONTROL__

#include "../BSW/Services/Std_Types.h"

#define MAX_TORQUE      100.0f
#define MIN_TORQUE      0.0f


void TorqueControl_Init(void);
void TorqueControl_Update(void);

#endif
