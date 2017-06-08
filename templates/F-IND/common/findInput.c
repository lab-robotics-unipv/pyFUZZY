#include <stdint.h>
#include "memFunc.h"
#include "findInput.h"

/*! INIT OF A FUZZY INPUT
 *		output		fi			FIND input to init
 *		input		name		Label of the FIND input
 *		input		MFs			Array of membership functions
 *		input 		nMF			Number of membership functions to be included
 * 		input		min			Minimum value of the Fuzzy Input
 * 		input 		max			Maximum value of the Fuzzy Input
 */
void createFindInput(findInput *fi, memFunction *MFs, uint_t nMF, dataType min, dataType max) {
	
	fi->minValue = min;
	fi->maxValue = max;

	fi->nMF = nMF;

	fi->mf = MFs;

}

/*! CALCULATION OF THE MEMBERSHIP TO A GIVEN FIND INPUT
 *			input		fuzzy_input		A FIND Input
 *			input 		inputValue		Value of the input
 * 
 * 			output		output			The % of membership to a FIND Input given an input value
 */
uint_t getPercentageFromFindInput(findInput *fuzzy_input, dataType inputValue, dataType *output) {

	if (inputValue < fuzzy_input->minValue) {
		*output = 1.0;
		return 0;
	} else if (inputValue > fuzzy_input->maxValue) {
		*output = 1.0;
		return fuzzy_input->nMF-(uint_t)1;
	}
	
	uint_t i;	
	for ( i = 0; i < fuzzy_input->nMF; i++) {
		*output = getPercentage(&(fuzzy_input->mf[i]), inputValue);
		if(*output>0)
			return i;
	}
	//Warning: it should never reach this point
	return 0;
}