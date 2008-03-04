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
						"Vacuum out of range"};
	if (lookupval < sizeof(strArray)/sizeof(strArray[0]))
	{
		strcpy(p->vala,strArray[lookupval]);
		if ((lookupval>0)&(lookupval<3)) recGblSetSevr(p,epicsAlarmState,epicsSevMinor);
		else if (lookupval>4) recGblSetSevr(p,epicsAlarmState,epicsSevMajor);
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
