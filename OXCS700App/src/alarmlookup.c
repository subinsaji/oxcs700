#include <stdio.h>
#include <string.h>

#include <dbDefs.h>
#include <registryFunction.h>
#include <genSubRecord.h>
#include <epicsExport.h>
#include <alarm.h>
#include <recGbl.h>

typedef long (*processMethod)(genSubRecord *precord);

static long alarmlookupProcess(genSubRecord *p)
{
	/* lookup a string from an int value */
	int lookupval = *(int *)p->a;
	char* strArray[] = {"No Alarm",
						"Stop Button Pressed",
						"Stop Command Received",
						"End Phase Done",
						"Purge Phase Done",
						"Temp Error > 5K",
						"Back Pressure > 0.5bar",
						"Evap reduction at max",
						"Self-check fail",
						"Gas flow < 2 l/min",
						"Temp error > 25 K",
						"Wrong gas type",
						"Unphysical temp",
						"Suct temp out of range",
						"Invalid ADC reading",
						"Degradation of PSU",
						"Heat sink overheating",
						"PSU overheating",
						"Power failure",
						"Refrigerator stage too cold",
						"Refrigerator stage timeout",
						"Cryodrive not responding",
						"Cryodrive error",
						"No nitrogen available",
						"No helium available",
						"Vacuum gauge not responding",
						"Vacuum out of range",
						"RS232 error",
						"Refrigerator temp warning",
						"Refrigerator temp error",
						"Do not open cryostat",
						"Do not open cryostat",
						"Unplug Xtal sensor",
						"Cryostat open",
						"Cryostat open timeout",
						"High temp warning",
						"High temp error",
						"Cryodrive T sensor fault",
						"Cryodrive P sensor fault",
						"Cryodrive low T trip",
						"Cryodrive high T trip",
						"Cryodrive low P trip",
						"Cryodrive high T warning",
						"Cryodrive low P warning",
						"Connect gas supply",
						"Autofill fault",
						"Autofill about to fill",
						"Autofill filling",
						"Collar temp error",
						"Refrigerator error",
						"Turbo flow",
						"He selected",
						"Cryodrive not ready",
						"Regen required",
						"Regen complete",
						"Connect vacuum",
						"Disconnect vacuum"};
	if (lookupval < sizeof(strArray)/sizeof(strArray[0]))
	{
		strcpy(p->vala,strArray[lookupval]);
		if ((lookupval>0)&(lookupval<3)) recGblSetSevr(p,epicsAlarmState,epicsSevMinor);
		else if (((lookupval>4)&(lookupval<46))|(lookupval>47)) recGblSetSevr(p,epicsAlarmState,epicsSevMajor);
		else recGblSetSevr(p,epicsAlarmState,epicsSevNone);
	}
	else
	{
		strcpy(p->vala,"Illegal Alarm");
	}
    return(0);
}

/* Register these symbols for use by IOC code: */
epicsRegisterFunction(alarmlookupProcess);
