/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rdict.h"

char	dict[DICTSIZ][MAXWORD+1];/* storage for a dictionary of words	*/
int	nwords = 0;		/* number of words in the dictionary	*/

int *
initw_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */
	nwords = 0;
	result = 1;
	return &result;
}

int *
insertw_1_svc(char **argp, struct svc_req *rqstp)
{
	static int  result;

		strcpy(dict[nwords], *argp);
	nwords++;
	result = nwords;

	return &result;
}

int *
deletew_1_svc(char **argp, struct svc_req *rqstp)
{
	static int  result;

	int	i;
	result = 0;
	for (i=0 ; i<nwords ; i++)
		if (strcmp(*argp, dict[i]) == 0) {
			nwords--;
			strcpy(dict[i], dict[nwords]);
			result = 1;
		}
	return &result;
}

int *
lookupw_1_svc(char **argp, struct svc_req *rqstp)
{
	static int  result;

	int	i;
	result = 0;
	for (i=0 ; i<nwords ; i++)
		if (strcmp(*argp, dict[i]) == 0)
			result = 1;


	return &result;
}
