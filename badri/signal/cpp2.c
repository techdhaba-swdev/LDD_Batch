#include <stdio.h>
#include <signal.h>

//Function to handle any signal (demonstration purposes)

void signal_handler(int sig)
{
	printf("Caught signal: %d\n",sig);


//**important: ** cannot perform actions that rely on external resoueces
//due to asynchronous nature of signals.(e.g., printf,network I/O)
//example of safe action: setting a flag to indicate signal received

static int signal_received = 0;
signal_received = 1;
}
int main()
{
	 //attempt to register signal handler for SIGKILL (will fail)

	if(signal(SIGKILL , signal_handler) == SIG_ERR)
	{
		perror("signal");
		return 1;
	}
	printf("Process running..\n");
	//loop to demonstrate program execution
	while(1)
		{
			//simulate work being done (replace with actual work)
			sleep(1);
		}

			//check if signal was received (safe action)
			if(  )
			{
				printf("signal received likely not SIGKILL due to limitations).\n"):
					break;
			}
		}

