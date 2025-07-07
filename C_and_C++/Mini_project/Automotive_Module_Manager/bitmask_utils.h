#ifndef _BITMASK_U_
#define _BITMASK_U_

#define STATUS_ON			(1<<0)
#define STATUS_OFF			(1<<1)
#define STATUS_WARNING 		(1<<2)

#define PREMISSION_READ		(1<<0)
#define PREMISSION_WRITE	(1<<1)
#define PREMISSION_NONE		(1<<2)

typedef enum{
	ON,
	OFF
}Status_Module;

typedef enum{
	NONE,
	READ,
	WRITE
}Premission_Module;

#endif