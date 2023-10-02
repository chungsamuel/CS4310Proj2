#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "Wait.h"
#include <sys/wait.h>

Wait::Wait(int argc, char **argv)
    : POSIXApplication(argc, argv)
{
    parser().setDescription("Wait for a background process to finish");
    parser().registerPositional("PID", "PID of the background process to wait for");
}

Wait::~Wait()
{
}

Wait::Result Wait::exec()
{
    int pid = 0;

    if ((pid = atoi(arguments().get("PID"))) <= 0)
    {
        ERROR("Invalid PID: " << arguments().get("PID"));
        return InvalidArgument;
    }

    int status;
    if (waitpid(pid, &status, 0) == -1)
    {
        ERROR("Failed to wait for PID " << pid << ": " << strerror(errno));
        return IOError;
    }

    return Success;
}
