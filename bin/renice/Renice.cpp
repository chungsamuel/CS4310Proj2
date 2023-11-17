#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <Process.h>
#include <ProcessClient.h>
#include "Renice.h"


Renice::Renice(int argc, char** argv) : POSIXApplication(argc, argv)
{
	parser().setDescription("Change the priority of a currently running process. If flag n is not registered, will increase the priority by 1. Else, will set the priority to specified value.");
   	parser().registerFlag('n', "priority", "Specify the scheduling priority to be used for the process");
	parser().registerPositional("PRIORITY", "A specific priority level to set the process to.");
	parser().registerPositional("PID", "The process id of a currently running process.");
}

Renice::~Renice() 
{
	
}

Renice::Result Renice::exec()
{
    if (arguments().getFlags().count() > 0)
    {
        ProcessClient client;
        ProcessID pid = atoi(arguments().get("PID"));
        int priority = atoi(arguments().get("PRIORITY"));
        if (priority < 1 || priority > 5)
        {
            return InvalidArgument;
        }
        client.setPriority(pid, priority);
        return Success;
    }
    return InvalidArgument;
}
