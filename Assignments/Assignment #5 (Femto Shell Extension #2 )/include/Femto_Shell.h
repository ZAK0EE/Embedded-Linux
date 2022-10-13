#define FEMTO_MAX_ARGV 100

/**
* @brief This function starts the Femto Shell
*
* @return 1 on sucess
*/
int Femto_Shell();


/**
* @brief This function parses the input and stores tokens
*
* @return 1 on sucess
*/
int Femto_ParseInput();


/**
* @brief This function deconstructs the shell loop and frees any allocated memory
*
* @Note This function does not terminate the shell
*
* @return 1 on sucess
*/
int Femto_Deconstruct();
